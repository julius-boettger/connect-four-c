# Connect Four
```
🔴🔴🔴🟡🔴
🔴🔴🟡🔴🔴
🔴🟡🔴🔴🔴
🟡🔴🔴🔴🔴
```

# Installation
## From Release
Just grab a [release](https://github.com/julius-boettger/connect-four-c/releases) :)
## From Source
Requirements:
- [`git`](https://git-scm.com/)
- a C compiler like [`gcc`](https://gcc.gnu.org/)
- [`meson`](https://mesonbuild.com/) with a backend (e.g. [`ninja`](https://ninja-build.org/))
```sh
git clone https://github.com/julius-boettger/connect-four-c
cd connect-four-c
meson setup build
meson compile -C build
# on windows:
.\build\connect-four-c.exe
# otherwise:
./build/connect-four-c
```