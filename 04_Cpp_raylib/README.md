# Starter Template

- https://github.com/RobLoach/raylib-cpp/

- https://github.com/educ8s/Raylib-CPP-Starter-Template-for-VSCODE
  - https://github.com/tupini07/raylib-cpp-cmake-template

# Raylib Tutorials | Programming With Nick
- https://youtube.com/playlist?list=PLwR6ZGPvjVOSRywn9VCQ3yrRVruxzzuo9&si=GgBQDYWrxr_Lujg0

- examples
  - https://github.com/raylib-extras/examples-cpp
  - https://github.com/raylib-extras/extras-cpp

# raylib-cpp
- https://robloach.github.io/raylib-cpp/index.html


<hr />

# C++ starter

```
git clone https://github.com/CapsCollective/raylib-cpp-starter.git

make setup
make
```

```bash
$ mkdir -p  bin
$ g++ -MMD -MP -c -std=c++17 -I include src/main.cpp -o bin/main.o
$ g++  bin/main.o -o bin/app -L lib/Linux -l raylib -l GL -l m -l pthread -l dl -l rt -l X11
$ bin/app
```

- .gitignore

```gitignore
include
lib
bin
.idea
.DS_Store
vendor
.git
.github
.gitmodules
lib
```

# 폴더 구조(raylib-c++)

```
$ eza -la -TL2
drwxrwxr-x    - gygy  5 Jan 00:23 .
drwxrwxr-x    - gygy  5 Jan 00:22 ├── .git
drwxrwxr-x    - gygy  5 Jan 00:22 ├── docs
.rw-rw-r-- 3.5k gygy  5 Jan 00:22 │   ├── InstallingDependencies.md
.rw-rw-r--  13k gygy  5 Jan 00:22 │   └── MakefileExplanation.md
drwxrwxr-x    - gygy  5 Jan 00:22 ├── include
...
많은 파일이 있음..
...
...
.rw-rw-r-- 1.6k gygy  5 Jan 00:22 │   ├── AudioDevice.hpp
.rw-rw-r-- 5.5k gygy  5 Jan 00:22 │   ├── AudioStream.hpp
.rw-rw-r-- 3.7k gygy  5 Jan 00:22 │   ├── AutomationEventList.hpp
.rw-rw-r-- 5.5k gygy  5 Jan 00:22 │   ├── Wave.hpp
.rw-rw-r--  10k gygy  5 Jan 00:22 │   └── Window.hpp
drwxrwxr-x    - gygy  5 Jan 00:23 ├── lib
drwxrwxr-x    - gygy  5 Jan 00:23 │   └── Linux
.rw-rw-r--  957 gygy  5 Jan 00:22 ├── LICENCE
.rw-rw-r-- 3.0k gygy  5 Jan 00:22 ├── Makefile
.rw-rw-r-- 8.3k gygy  5 Jan 00:22 ├── README.md
drwxrwxr-x    - gygy  5 Jan 00:22 ├── src
.rw-rw-r--  641 gygy  5 Jan 00:22 │   └── main.cpp
drwxrwxr-x    - gygy  5 Jan 00:22 └── vendor
drwxrwxr-x    - gygy  5 Jan 00:22     ├── raylib
drwxrwxr-x    - gygy  5 Jan 00:22     └── raylib-cpp


...
더 자세히 ....
...
...

rwxrwxr-x    - gygy  5 Jan 00:23 ├── lib
drwxrwxr-x    - gygy  5 Jan 00:23 │   └── Linux
.rw-rw-r-- 2.9M gygy  5 Jan 00:23 │       └── libraylib.a
.rw-rw-r--  957 gygy  5 Jan 00:22 ├── LICENCE
.rw-rw-r-- 3.0k gygy  5 Jan 00:22 ├── Makefile
.rw-rw-r-- 8.3k gygy  5 Jan 00:22 ├── README.md
drwxrwxr-x    - gygy  5 Jan 00:22 ├── src
.rw-rw-r--  641 gygy  5 Jan 00:22 │   └── main.cpp
drwxrwxr-x    - gygy  5 Jan 00:22 └── vendor
drwxrwxr-x    - gygy  5 Jan 00:22     ├── raylib
.rw-rw-r--   41 gygy  5 Jan 00:22     │   ├── .git
drwxrwxr-x    - gygy  5 Jan 00:22     │   ├── .github
.rw-rw-r-- 1.3k gygy  5 Jan 00:22     │   ├── .gitignore
.rw-rw-r--  19k gygy  5 Jan 00:22     │   ├── BINDINGS.md
.rw-rw-r--  176 gygy  5 Jan 00:22     │   ├── build.zig
.rw-rw-r-- 132k gygy  5 Jan 00:22     │   ├── CHANGELOG
drwxrwxr-x    - gygy  5 Jan 00:22     │   ├── cmake
.rw-rw-r-- 1.6k gygy  5 Jan 00:22     │   ├── CMakeLists.txt
.rw-rw-r-- 9.1k gygy  5 Jan 00:22     │   ├── CMakeOptions.txt
.rw-rw-r-- 4.4k gygy  5 Jan 00:22     │   ├── CONTRIBUTING.md
.rw-rw-r-- 3.4k gygy  5 Jan 00:22     │   ├── CONVENTIONS.md
drwxrwxr-x    - gygy  5 Jan 00:22     │   ├── examples
.rw-rw-r--  10k gygy  5 Jan 00:22     │   ├── FAQ.md
.rw-rw-r--  70k gygy  5 Jan 00:22     │   ├── HISTORY.md
.rw-rw-r--  877 gygy  5 Jan 00:22     │   ├── LICENSE
drwxrwxr-x    - gygy  5 Jan 00:22     │   ├── logo
drwxrwxr-x    - gygy  5 Jan 00:22     │   ├── parser
drwxrwxr-x    - gygy  5 Jan 00:22     │   ├── projects
.rw-rw-r--  427 gygy  5 Jan 00:22     │   ├── raylib.pc.in
.rw-rw-r--  10k gygy  5 Jan 00:22     │   ├── README.md
.rw-rw-r-- 4.8k gygy  5 Jan 00:22     │   ├── ROADMAP.md
drwxrwxr-x    - gygy  5 Jan 00:23     │   └── src
drwxrwxr-x    - gygy  5 Jan 00:22     └── raylib-cpp
.rw-rw-r--  147 gygy  5 Jan 00:22         ├── .editorconfig
.rw-rw-r--   45 gygy  5 Jan 00:22         ├── .git
drwxrwxr-x    - gygy  5 Jan 00:22         ├── .github
.rw-rw-r--   75 gygy  5 Jan 00:22         ├── .gitignore
.rw-rw-r--  192 gygy  5 Jan 00:22         ├── .gitmodules
.rw-rw-r-- 1.7k gygy  5 Jan 00:22         ├── clib.json
.rw-rw-r--  872 gygy  5 Jan 00:22         ├── CMakeLists.txt
.rw-rw-r--  125 gygy  5 Jan 00:22         ├── CPPLINT.cfg
drwxrwxr-x    - gygy  5 Jan 00:22         ├── examples
drwxrwxr-x    - gygy  5 Jan 00:22         ├── include
.rw-rw-r--  867 gygy  5 Jan 00:22         ├── LICENSE
.rw-rw-r--  945 gygy  5 Jan 00:22         ├── package.json
drwxrwxr-x    - gygy  5 Jan 00:22         ├── projects
.rw-rw-r-- 9.7k gygy  5 Jan 00:22         ├── README.md
drwxrwxr-x    - gygy  5 Jan 00:22         └── tests
```
