# BigLogger

Simple logger that creates one file and then writes into it all info.

Written on [C++](https://cplusplus.com/) and built on [CMake](https://cmake.org/) with [Ninja](https://ninja-build.org/) build system.

New program execution will **truncate** log file.

**Debug** version using *std::cout* and *std::cerr* for logs at runtime. That's the only difference from **Release** version.

Installing files puts results to *bin\Debug* or *bin\Release* folder.

Testing runs [test](./test/test.cpp) file.

## Debug build

Configuring + Building:
```bash
cmake --workflow --preset Debug
```

Configuring CMake:
```bash
cmake --preset Debug
```

Building:
```bash
cmake --build Debug
```

Testing:
```bash
ctest --preset Debug
```

Installing:
```bash
cmake --install .\build\Debug
```

## Release build

Configuring + Building:
```bash
cmake --workflow --preset Release
```

Configuring CMake:
```bash
cmake --preset Release
```

Building:
```bash
cmake --build Release
```

Testing:
```bash
ctest --preset Release
```

Installing:
```bash
cmake --install .\build\Release
```