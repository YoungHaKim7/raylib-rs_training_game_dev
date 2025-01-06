<p align="center">
	<img width=70px src="https://github.com/user-attachments/assets/a2721e59-5332-4e72-b874-641ee5c56f44" />
	<br /><img width=64px src="https://github.com/raysan5/raylib/raw/master/logo/raylib_logo_animation.gif" />
</p>

# link

- [raylib-rs_training_game_dev](#raylib-rs_training_game_dev)
  - [raylib_인스톨_Install](#install)
  - [raylib(C언어 예시 많다 굿)](#raylibc언어-예시-많다-굿)

- [raylib장점](#raylib-장점)

<hr />

- [justfile (C언어_파일 1개 짜리)](#justfile-c언어_파일-1개-짜리)


<hr />

<hr />

# raylib(C언어 예시 많다 굿)[|🔝|](#link)
- https://github.com/raylib-extras/examples-c
  - 개인이 만든거 자랑하는곳 대단한 사람들이 많다.
    - https://github.com/raysan5/raylib/discussions/1326

<hr />

# raylib-rs_training_game_dev[|🔝|](#link)
- https://github.com/raysan5/raylib

- https://github.com/raylib-rs/raylib-rs

- doc(API)
  - https://www.raylib.com/cheatsheet/cheatsheet.html

# Install[|🔝|](#link)

- LinuxOS
  - https://github.com/raysan5/raylib/wiki#development-platforms

```bash
- git clone https://github.com/raysan5/raylib.git raylib
cd raylib
mkdir build && cd build
cmake -DBUILD_SHARED_LIBS=ON ..
make
sudo make install
sudo ldconfig
```

# justfile (C언어_파일 1개 짜리)[|🔝|](#link)
- https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux#build-raylib-using-cmake

```justfile
# which clang
clang_which := `which clang`

# Source and target directories
src_dir := "./src"
target_dir := "./target"

# Files
source := src_dir+"/main.c"
target := target_dir+"/main"

# Common flags
ldflags_common := "-pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb"
ldflags_debug := "-c -pthread -lm -Wall -Wextra -ggdb"
ldflags_emit_llvm := "-S -emit-llvm"
ldflags_assembly := "-Wall -save-temps"
ldflags_fsanitize_address := "-O1 -g -fsanitize=address -fno-omit-frame-pointer -c"
ldflags_fsanitize_object := "-g -fsanitize=address"
ldflags_fsanitize_valgrind := "-fsanitize=address -g3"
# SDL3 세팅 최적화 O2
# ldflags_optimize :=  "-lSDL3 -MMD -MP -Wall -O2"
# raylib 세팅
ldflags_optimize :=  "-lraylib -lGL -lm -lpthread -ldl -lrt -lX11"
# ldflags_optimize :=  "-Wall -O3 -pedantic -pthread -pedantic-errors -lm -Wextra -ggdb"

# link_files := src_dir
# link_files02 := link_files+ \
# "/input.c " +  \
# link_files + "/init.c " + \
# link_files + "/draw.c "


# (C)clang compile
r:
	rm -rf target
	mkdir -p target
	clang {{ldflags_common}} {{source}}
	{{target}}

# (C)clang compile(Optimization)
ro:
	rm -rf {{target_dir}}
	mkdir -p {{target_dir}}
	clang {{source}} {{ldflags_optimize}}
	mv *.out target
	{{target_dir}}/./a.out

# zig C compile
zr:
	rm -rf target
	mkdir -p target
	zig {{ldflags_common}} -o {{target}} {{source}}
	{{target}}

# clang build
b:
	rm -rf target
	mkdir -p target
	clang {{ldflags_debug}} -o {{target}} {{source}}

# clang LLVM emit-file
ll:
	rm -rf target
	mkdir -p target
	cp -rf {{src_dir}}/main.c ./
	clang {{ldflags_emit_llvm}} main.c
	mv *.ll {{target_dir}}
	clang {{ldflags_common}} -o {{target}} {{source}}
	mv *.cpp {{target_dir}}
	rm -rf *.out

# Assembly emit-file
as:
	rm -rf target
	mkdir -p target
	clang {{ldflags_assembly}} -o {{target}} {{source}}
	mv *.i {{target_dir}}
	mv *.o {{target_dir}}
	mv *.s {{target_dir}}
	mv *.bc {{target_dir}}

# clang fsanitize_address
fsan:
	rm -rf target
	mkdir -p target
	clang {{ldflags_fsanitize_address}} {{source}} -o {{target}}
	clang {{ldflags_fsanitize_object}} {{target}}
	mv *.out {{target_dir}}

# leak memory check(valgrind)
mem:
	rm -rf target
	mkdir -p target
	clang {{ldflags_fsanitize_valgrind}} {{source}} -o {{target}}
	valgrind --leak-check=full {{target}}

# object file emit-file
obj:
	rm -rf target
	mkdir -p target
	clang {{ldflags_assembly}} -o {{target}} {{source}}
	mv *.ii {{target_dir}}
	mv *.o {{target_dir}}
	mv *.s {{target_dir}}
	mv *.bc {{target_dir}}
	objdump --disassemble -S -C {{target_dir}}/main.o

# hex view
xx:
	rm -rf target
	mkdir -p target
	clang {{ldflags_fsanitize_valgrind}} {{source}} -o {{target}}
	xxd -c 16 {{target}}

# clean files
clean:
	rm -rf {{target_dir}} *.out {{src_dir}}/*.out *.bc {{src_dir}}/target/ *.dSYM {{src_dir}}/*.dSYM *.i *.o *.s

# C init
init:
	mkdir -p src
	echo '#include <stdio.h>' > src/main.c
	echo '' >> src/main.c
	echo 'int main(void) {' >> src/main.c
	echo '    printf("Hello world C lang ");' >> src/main.c
	echo '    return 0;' >> src/main.c
	echo '}' >> src/main.c

# Debugging(VSCode)
vscode:
	rm -rf .vscode
	mkdir -p .vscode
	echo '{' > .vscode/launch.json
	echo '    "version": "0.2.0",' >> .vscode/launch.json
	echo '    "configurations": [' >> .vscode/launch.json
	echo '        {' >> .vscode/launch.json
	echo '            "type": "lldb",' >> .vscode/launch.json
	echo '            "request": "launch",' >> .vscode/launch.json
	echo '            "name": "Launch",' >> .vscode/launch.json
	echo '            "program": "${workspaceFolder}/target/${fileBasenameNoExtension}",' >> .vscode/launch.json
	echo '            "args": [],' >> .vscode/launch.json
	echo '            "cwd": "${workspaceFolder}"' >> .vscode/launch.json
	echo '            // "preLaunchTask": "C/C++: clang build active file"' >> .vscode/launch.json
	echo '        },' >> .vscode/launch.json
	echo '        {' >> .vscode/launch.json
	echo '            "name": "gcc - Build and debug active file",' >> .vscode/launch.json
	echo '            "type": "cppdbg",' >> .vscode/launch.json
	echo '            "request": "launch",' >> .vscode/launch.json
	echo '            "program": "${fileDirname}/target/${fileBasenameNoExtension}",' >> .vscode/launch.json
	echo '            "args": [],' >> .vscode/launch.json
	echo '            "stopAtEntry": false,' >> .vscode/launch.json
	echo '            "cwd": "${fileDirname}",' >> .vscode/launch.json
	echo '            "environment": [],' >> .vscode/launch.json
	echo '            "externalConsole": false,' >> .vscode/launch.json
	echo '            "MIMode": "lldb"' >> .vscode/launch.json
	echo '            // "tasks": "C/C++: clang build active file"' >> .vscode/launch.json
	echo '        }' >> .vscode/launch.json
	echo '    ]' >> .vscode/launch.json
	echo '}' >> .vscode/launch.json
	echo '{' > .vscode/tasks.json
	echo '    "tasks": [' >> .vscode/tasks.json
	echo '        {' >> .vscode/tasks.json
	echo '            "type": "cppbuild",' >> .vscode/tasks.json
	echo '            "label": "C/C++: clang build active file",' >> .vscode/tasks.json
	echo '            "command": "{{clang_which}}",' >> .vscode/tasks.json
	echo '            "args": [' >> .vscode/tasks.json
	echo '                "-c",' >> .vscode/tasks.json
	echo '                "-fcolor-diagnostics",' >> .vscode/tasks.json
	echo '                "-fansi-escape-codes",' >> .vscode/tasks.json
	echo '                "-g",' >> .vscode/tasks.json
	echo '                "${file}",' >> .vscode/tasks.json
	echo '                "-o",' >> .vscode/tasks.json
	echo '                "${fileDirname}/target/${fileBasenameNoExtension}"' >> .vscode/tasks.json
	echo '            ],' >> .vscode/tasks.json
	echo '            "options": {' >> .vscode/tasks.json
	echo '                "cwd": "${fileDirname}"' >> .vscode/tasks.json
	echo '            },' >> .vscode/tasks.json
	echo '            "problemMatcher": [' >> .vscode/tasks.json
	echo '                "$gcc"' >> .vscode/tasks.json
	echo '            ],' >> .vscode/tasks.json
	echo '            "group": {' >> .vscode/tasks.json
	echo '                "kind": "build",' >> .vscode/tasks.json
	echo '                "isDefault": true' >> .vscode/tasks.json
	echo '            },' >> .vscode/tasks.json
	echo '            "detail": "Task generated by Debugger."' >> .vscode/tasks.json
	echo '        }' >> .vscode/tasks.json
	echo '    ],' >> .vscode/tasks.json
	echo '    "version": "2.0.0"' >> .vscode/tasks.json
```

# raylib 장점[|🔝|](#link)

- FEATURES:
  - NO external dependencies, all required libraries included with raylib
  - Multiplatform: Windows, Linux, FreeBSD, OpenBSD, NetBSD, DragonFly, MacOS, Haiku, Android, Raspberry Pi, DRM native, HTML5.
  - Written in plain C code (C99) in PascalCase/camelCase notation
  - Hardware accelerated with OpenGL (1.1, 2.1, 3.3, 4.3, ES2, ES3 - choose at compile)
  - Unique OpenGL abstraction layer (usable as standalone module): [rlgl]
  - Multiple Fonts formats supported (TTF, OTF, FNT, BDF, Sprite fonts)
  - Outstanding texture formats support, including compressed formats (DXT, ETC, ASTC)
  - Full 3d support for 3d Shapes, Models, Billboards, Heightmaps and more!
  - Flexible Materials system, supporting classic maps and PBR maps
  - Animated 3D models supported (skeletal bones animation) (IQM, M3D, GLTF)
  - Shaders support, including Model shaders and Postprocessing shaders
  - Powerful math module for Vector, Matrix and Quaternion operations: [raymath]
  - Audio loading and playing with streaming support (WAV, OGG, MP3, FLAC, QOA, XM, MOD)
  - VR stereo rendering with configurable HMD device parameters
  - Bindings to multiple programming languages available!
  - 외부 종속성 없음, 레이리브에 포함된 모든 필수 라이브러리
  - 멀티플랫폼: Windows, Linux, FreeBSD, OpenBSD, NetBSD, DragonFly, MacOS, 하이쿠, 안드로이드, 라즈베리 파이, DRM 네이티브, HTML5.
  - PascalCase/camelCase 표기법으로 일반 C 코드(C99)로 작성됨
  - OpenGL로 가속화된 하드웨어(1.1, 2.1, 3.3, 4.3, ES2, ES3 - 컴파일 시 선택)
  - 고유 OpenGL 추상화 계층(독립형 모듈로 사용 가능): [rlgl]
  - 지원되는 여러 글꼴 형식(TTF, OTF, FNT, BDF, 스프라이트 글꼴)
  - 압축 형식(DXT, ETC, ASTC)을 포함한 뛰어난 텍스처 형식 지원
  - 3D 형상, 모델, 빌보드, 높이 지도 등을 위한 완벽한 3D 지원!
  - 클래식 맵과 PBR 맵을 지원하는 유연한 소재 시스템
  - 애니메이션 3D 모델 지원(골격 애니메이션)(IQM, M3D, GLTF)
  - 모델 셰이더 및 후처리 셰이더를 포함한 셰이더 지원 벡터, 행렬 및 쿼터니언 연산을 위한 강력한 수학 모듈: [레이매스]
  - 오디오 로딩 및 스트리밍 지원(WAV, OGG, MP3, FLAC, QOA, XM, MOD)
  - 구성 가능한 HMD 장치 매개변수를 사용한 VR 스테레오 렌더링
  - 여러 프로그래밍 언어에 대한 바인딩을 사용할 수 있습니다!
