- https://github.com/RobLoach/raylib-cpp/

# Run

```bash
$ c++ -MMD -MP -c -std=c++17 -I include src/main.cpp -o bin/main.o
$ c++  bin/main.o -o bin/app -L lib/macOS -l raylib -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
$ bin/app
  
```


- tree

```bash
$ eza -la -TL2 bin
drwxr-xr-x@    - gy  5 Jan 00:02 bin
.rwxr-xr-x@ 898k gy  5 Jan 00:02 ├── app
.rw-r--r--@ 3.5k gy  5 Jan 00:02 ├── main.d
.rw-r--r--@  10k gy  5 Jan 00:02 └── main.o

```
