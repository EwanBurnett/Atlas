# Overview
Atlas is an open source Game Engine, intended to carry out modern rendering practices and performance techniques. Atlas' core is written in C++, and is intended as a personal learning project. 

- [Documentation](https://EwanBurnett.github.io/#) <!--Link to HTML Docs-->
- [Devlogs](https://EwanBurnett.github.io/#) <!---Link to Portfolio Website Devlog page-->

Atlas is Open Source, and is licensed under the [MIT License](./Licence.md). Feel free to use this code however you wish. 

the `master` branch is the main stable branch, and should always build and run on all supported platforms. Accordingly, new features and bug fixes are present in other branches, and the bleeding edge version of the source is available under the branch `latest`. 

## Platforms
- Windows [x64] [x86] (_WIN32)
- Linux [x64] (\_\_linux__)

Atlas consists of 3 main modules:
1. Atlas Framework
    - A C++ Static Library, containing the core logic of the program.
2. Atlas Interface
    - A C++ Dynamic Library, acting as an interface to other programs. Primarily used for Interop.
3. Atlas Editor
    - A DotNet 6.0 C# GUI frontend, written using Avalonia for cross platform GUI.

## Dependencies
### C++
- [GLFW](https://github.com/glfw/glfw)
A Cross Platform Windowing Library
- [ASSIMP](https://github.com/assimp/assimp) 
A 3D Model / Scene parser
- [TinyXML2](https://github.com/leethomason/tinyxml2)
A lightweight XML file parser
- [OpenAL Soft](https://github.com/kcat/openal-soft)
A 3D audio library. Essentially a mirror of OpenAL.
- [Lua](https://github.com/lua/lua)
A Modern Scripting Language.

### C#
- [Avalonia UI](https://github.com/AvaloniaUI/Avalonia)
A Cross Platform GUI Frontend, using .net 6.0

### Other
- [Doxygen](https://github.com/doxygen/doxygen)
an Inline HTML Documentation generator, which supports C++ and C#.

## Directory Structure
```
Atlas/
│   README.md
│   CMakeLists.txt    
│
└───Atlas/
│   │
│   └───Framework/
│   │   └──src/
│   │   └──inc/
│   │   │   ...
│   │ 
│   └───Interface/
│   │  └──src/
│   │  └──inc/
│   │  │   ...
│   │
│   └───Editor/
│      │   ... 
│ 
└───Docs/
│      │   ... 
│ 
└───Examples/
       │   ... 
```


---
# Build Instructions

## Prerequisites
Install [CMake](https://cmake.org/install/), following the instructions for your platform.

## Building
To build Atlas, just run CMake

    mkdir Build && cd Build
    cmake ..

---
# Changelog



