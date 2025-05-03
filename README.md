# computer_club
YADRO Impulse 2025 test assignment

## Build info(draft)  

### Windows  
**requirements:**  
- cmake 3.28+
- mingw
  
**command:**  
```
$ cmake.exe -G "MinGW Makefiles" -S . -B .\build
$ cd build
$ make.exe
```
### Linux  
**requirements:**  
- cmake 3.28+
- make 4.2.1+
- g++ 13+
  
**command:**  
```
$ cmake -S . -B build_linux
$ cd build
$ make
```
