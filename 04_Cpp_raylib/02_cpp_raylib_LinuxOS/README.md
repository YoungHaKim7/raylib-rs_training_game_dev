# C++ starter

```
git clone https://github.com/CapsCollective/raylib-cpp-starter.git
```

```bash
$ mkdir -p  bin
$ g++ -MMD -MP -c -std=c++17 -I include src/main.cpp -o bin/main.o
$ g++  bin/main.o -o bin/app -L lib/Linux -l raylib -l GL -l m -l pthread -l dl -l rt -l X11
$ bin/app
```


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
