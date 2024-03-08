# Connect Four
```
🔴🔴🔴🟡🔴
🔴🔴🟡🔴🔴
🔴🟡🔴🔴🔴
🟡🔴🔴🔴🔴
```

### Note for the Windows Users
**If stuff looks weird, it's probably because of your terminal.**
The default ones on Windows can be pretty bad, try using **[Windows Terminal](https://apps.microsoft.com/detail/9n0dx20hk701?rtc=1&hl=de-de&gl=DE)** instead (if you aren't already).

# Installation
### From Release
Just grab a [release](https://github.com/julius-boettger/connect-four-c/releases) :)
### From Source
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