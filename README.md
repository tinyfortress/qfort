# QFort
QFort is the engine/core/kernel part of the planned videogame called TinyFortress.  

## Goals (QFort)
* Build with any compiler (at least GCC, Clang and MSVC)
* Build anywhere (at least GNU/Linux and Microsoft Windows)
* Compile the game code alongside the engine. Slower build times but much more control for the game development side of things
* At least run under any GPU that supports OpenGL 3.3

## Goals (TinyFortress)
* Run smoothly on a decently old hardware in most cases
* Run smoothly on a decently new hardware in the worst case scenario
* Replicate the visual style and feel of TF2 sans hats and bots

## Building
### Prerequisites
- [x] CMake version 3.14 or higher
- [x] An ISO C99 and C++17 compiler
- [x] Basic knowledge of command line work

### Commands
```
git clone https://github.com/tinyfortress/qfort.git
```  
```
cd qfort
```  
```
cmake -B build -DCMAKE_BUILD_TYPE=Release .
```  
```
cmake --build build
```

## Notes
1. A system-managed installation of [GLFW]() is recommended. It's not required though, if CMake doesn't find GLFW installed, it will clone and build it automatically.  

2. I haven't once tested my code on a 32-bit processor/system and I do not intend on doing so. By default I consider my code to be 64-bit even if it works fine on 32-bit it still might stumble upon some pitfalls like 64-bit math being loads slower.  
