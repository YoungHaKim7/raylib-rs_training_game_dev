- https://github.com/RobLoach/raylib-cpp/

# Run

```bash
$ c++ -MMD -MP -c -std=c++17 -I include src/main.cpp -o bin/main.o
$ c++  bin/main.o -o bin/app -L lib/macOS -l raylib -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
bin/app
  
```
