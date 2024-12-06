import os, pathlib, re, sys, subprocess

CWD = os.path.dirname(__file__)
ROOT_DIR = os.path.dirname(os.path.dirname(CWD))
SENTINEL_BEGIN = "DL_BUTTONS_BEGIN"
SENTINEL_END = "DL_BUTTONS_END"


def latest_git_tag_version() -> str:
    p = subprocess.run(
        ["git", "describe", "--tags", "--abbrev=0"],
        cwd=ROOT_DIR,
        capture_output=True,
        text=True,
    )
    if p.returncode != 0:
        raise RuntimeError("failed to get latest git tag")
    tag = str(p.stdout).strip()
    if not re.search(r"^v\d+\.\d+\.\d+$", tag):
        raise RuntimeError(f"bad tag format: {tag}")
    return tag[1:]


def update_download_buttons(file: pathlib.Path, version: str):
    with open(file, "rt") as f:
        replace = False
        has_replaced = False
        new_lines = []
        for line in f.readlines():
            new_lines.append(line)
            if SENTINEL_BEGIN in line:
                replace = True
                continue
            if SENTINEL_END in line:
                replace = False
                continue
            if replace:
                line_new, n = re.subn(r"\d+\.\d+\.\d+", version, line)
                if n > 0:
                    has_replaced = True
                    new_lines.pop()
                    new_lines.append(line_new)
    if has_replaced:
        new_content = "".join(new_lines)
        with open(file, "wt") as f:
            f.write(new_content)
        pure_path = pathlib.PurePosixPath(file.relative_to(ROOT_DIR))
        print(f"Updated {pure_path} to version {version}")


if __name__ == "__main__":
    version = latest_git_tag_version()
    for file in [
        pathlib.Path(os.path.join(ROOT_DIR, "README.md")),
        *pathlib.Path(os.path.join(ROOT_DIR, "documentation")).rglob("*.md"),
    ]:
        update_download_buttons(file, version)
