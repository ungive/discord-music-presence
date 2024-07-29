# Fixes a changelog's bullet points to not contain linebreaks
# because release notes on GitHub will interpret them as actual linebreaks.
# Accepts input from stdin, prints result to stdout.

import sys

DEFAULT = 0
BULLET = 1

state = DEFAULT
linebreak = False

for line in sys.stdin:
    if len(line.strip()) == 0:
        print()
        continue
    is_bullet_start = line.lstrip()[0] in ('-', '*', '+')
    if state == BULLET and not is_bullet_start:
        if not linebreak:
            print(' ', end='')
        print(line.strip(), end='')
        continue
    if state == BULLET and is_bullet_start:
        print()
    linebreak = line.endswith('  \n') or line.endswith('  \r\n')
    if is_bullet_start:
        state = BULLET
        print(line.rstrip() + ('  ' if linebreak else ''), end=('\n' if linebreak else ''))
    else:
        state = DEFAULT
        print(line)
