#pragma  once

// cpp libs
#include <codecvt>
#include <regex>
#include <sstream>
#include <string>
#include <vector>
// winapi
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tlhelp32.h>
#include <Winuser.h>

#pragma comment (lib, "User32.lib")


/**
 * @brier Converts an std::wstring to utr-8 std::string
 * @param wstr The wstring to be converted
 * @return The copnverted string
 */
inline std::string rawWstringToString(const std::wstring &wstr) {
    return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(wstr);
}


/// @brief Enum describing the state of TIDAL app
enum status { error, closed, opened, playing };


/**
 * @brief struct to be passed to <enumWindowsProc>
 */
struct EnumWindowsProcParam {
    std::vector<DWORD> &pids;
    std::wstring &song;
    std::wstring &artist;
    status tidalStatus = closed;


    EnumWindowsProcParam(std::vector<DWORD> &pids, std::wstring &song, std::wstring &artist)
        : pids(pids), song(song), artist(artist) {}
};


inline bool isTIDAL(const PROCESSENTRY32W &entry) {
    return wcscmp(entry.szExeFile, L"TIDAL.exe") == 0;
}


/**
 * @brief Enums running apps and checks if TIDAL is running and if so if plays a song
 * @param hwnd
 * @param lParam <EnumWindowsProcParam> struct
 * @return returns TRUE if there wsa no error
 */
BOOL CALLBACK enumWindowsProc(HWND hwnd, LPARAM lParam) {
    static const std::wregex rgx(L"(.+) - (?!\\{)(.+)");
    auto &paramRe = *reinterpret_cast<EnumWindowsProcParam *>(lParam);
    DWORD winId;
    GetWindowThreadProcessId(hwnd, &winId);

    for (DWORD pid : (paramRe.pids)) {
        if (winId == pid) {

		  std::wstring title(GetWindowTextLength(hwnd) + 1, L'\0');
		  GetWindowTextW(hwnd, &title[0], (int)title.size()); //note: >=C++11

		  if (title.find(L"MSCTFIME UI") == 0
			  || title.find(L"Default IME") == 0
			  || title.find(L"MediaPlayer SMTC window") == 0
			  || title.size() == 1
			  )
		  {
			return TRUE;
		  }
		  paramRe.tidalStatus = opened;

//            std::regex_match(title, rgx);
            std::wsmatch matches;

            if (std::regex_search(title, matches, rgx)) {
                paramRe.song = matches[1].str();
                paramRe.artist = matches[2].str();
                paramRe.tidalStatus = playing;
                return FALSE;
            }
        }
    }
    return TRUE;
}


/**
 * @brief Checks tidal Info
 * @param song Track name if tidal is playing else empty string
 * @param artist Artist name if tidal is playing else empty string
 * @return returns a <status> struct with current tidal ifno
 */
status tidalInfo(std::wstring &song, std::wstring &artist) {
    static std::vector<DWORD> pids;
    static HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32W entry;
    entry.dwSize = sizeof entry;

    if (!Process32FirstW(snap, &entry))
        return error;

    if (pids.empty())
        do {
            if (isTIDAL(entry))
                pids.emplace_back(entry.th32ProcessID);
        } while (Process32NextW(snap, &entry));

    song = L"";
    artist = L"";

    EnumWindowsProcParam param(pids, song, artist);
    EnumWindows(enumWindowsProc, reinterpret_cast<LPARAM>(&param));

    if (param.tidalStatus == closed) {
        pids.clear();
        snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    }
    return param.tidalStatus;
}


/**
 * Gets locale of current user
 * @return ISO 2 letter formated country code
 */
inline char *getLocale() noexcept {
    static char buffer[3];
    GEOID myGEO = GetUserGeoID(GEOCLASS_NATION);
    int result = GetGeoInfoA(myGEO, GEO_ISO2, buffer, 3, 0);
    return buffer;
}
