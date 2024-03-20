cmake_minimum_required(VERSION 3.10)
project(discord-music-presence)

# Create executable
include_directories(.)
#if (APPLE)
#    #    set(CMAKE_PREFIX_PATH "~/Qt/5.14.2/clang_64/lib/cmake")
#else (APPLE)
#    set(CMAKE_PREFIX_PATH "C:\\Qt\\6.2.0\\msvc2019_64")
#endif (APPLE)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)


# Find the QtWidgets library
find_package(Qt6 COMPONENTS Widgets Core Network gui REQUIRED)
#set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_RELEASE} -fprofile-arcs -ftest-coverage")
qt6_add_resources(QRCS resources.qrc)
add_executable(discord-music-presence main.cc resource.rc ${QRCS})
target_include_directories(discord-music-presence PRIVATE vendor/discord_game_sdk/c)
target_include_directories(discord-music-presence PRIVATE vendor/discord_game_sdk/cpp)
target_link_libraries(discord-music-presence Qt6::Widgets Qt6::Core Qt6::Network)

if (DEFINED ENV{APPVEYOR_BUILD_VERSION})
    target_compile_definitions(discord-music-presence PUBLIC VERSION="v.$ENV{APPVEYOR_BUILD_VERSION}")
endif ()


# generate proper GUI program on specified platform if on release
if (NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("On release - generating gui app")
    if (WIN32) # Check if we are on Windows
        if (MSVC) # Check if we are using the Visual Studio compiler
            set_target_properties(discord-music-presence PROPERTIES
                    WIN32_EXECUTABLE YES
                    LINK_FLAGS "/ENTRY:mainCRTStartup"
                    )
        elseif (CMAKE_COMPILER_IS_GNUCXX)
            SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE} -mwindows") # Not tested
        else ()
            message(SEND_ERROR "You are using an unsupported Windows compiler! (Not MSVC or GCC)")
        endif (MSVC)
    elseif (APPLE)
        set_target_properties(discord-music-presence PROPERTIES
                MACOSX_BUNDLE YES
                )
    elseif (UNIX)
        # Nothing special required
    else ()
        message(SEND_ERROR "You are on an unsupported platform! (Not Win32, Mac OS X or Unix)")
    endif (WIN32)
endif ()


if (WIN32)
    if (MSVC)
        STRING(REPLACE "/Od" "/O2" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
        set(CMAKE_CXX_FLAGS_RELEASE "/MT")
    else ()
        target_link_libraries(discord-music-presence wsock32 ws2_32)
        set(CMAKE_CXX_FLAGS_RELEASE "-O3 -mwindows -lwinpthread")
    endif ()

    message("Building for Windows")
    if (CMAKE_SIZEOF_VOID_P EQUAL 8)
        # 64 bits
        message("\t64-bit")

        target_link_libraries(discord-music-presence ${CMAKE_SOURCE_DIR}/vendor/discord_game_sdk/lib/x86_64/discord_game_sdk.dll.lib)

        configure_file(${CMAKE_SOURCE_DIR}/vendor/discord_game_sdk/lib/x86_64/discord_game_sdk.dll ${CMAKE_BINARY_DIR}/discord_game_sdk.dll COPYONLY)

    elseif (CMAKE_SIZEOF_VOID_P EQUAL 4)
        # 32 bits
        message("\t32-bit")
        target_link_libraries(discord-music-presence ${CMAKE_SOURCE_DIR}/vendor/discord_game_sdk/lib/x86/discord_game_sdk.dll.lib)

        configure_file(${CMAKE_SOURCE_DIR}/vendor/discord_game_sdk/lib/x86/discord_game_sdk.dll ${CMAKE_BINARY_DIR}/discord_game_sdk.dll COPYONLY)
    endif ()

elseif (APPLE)
    message("Building for MacOS")
    target_link_libraries(discord-music-presence ${CMAKE_SOURCE_DIR}/vendor/discord_game_sdk/lib/x86_64/discord_game_sdk.dylib)
    set(CMAKE_CXX_FLAGS "-framework carbon -framework foundation -framework CoreFoundation")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    set(MACOSX_BUNDLE_BUNDLE_NAME rpc.music)
    set(MACOSX_BUNDLE_EXECUTABLE_NAME discord-music-presence)
    set(MACOSX_BUNDLE_INFO_STRING rpc.music)
    set(MACOSX_BUNDLE_GUI_IDENTIFIER rpc.music)
    set(MACOSX_BUNDLE_ICON_FILE icon.icns)

    set(app_icon_macos "${CMAKE_SOURCE_DIR}/assets/icon.icns")
    set_source_files_properties(${app_icon_macos} PROPERTIES
            MACOSX_PACKAGE_LOCATION "Resources")

    target_sources(discord-music-presence PRIVATE ${app_icon_macos})
endif ()
