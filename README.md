# computer_club
YADRO Impulse 2025 test assignment

## Architecture  
![system drawio (3)](https://github.com/user-attachments/assets/9e10f89c-ef71-46bc-91b6-236a6c5498b1)
## Core moments  
- 3 main units: Parser, EventHandler, Outputter.  
- EventFactory to separate building process from parsing and handling logic. Easy to add new events.  
- Visiter pattern for building events. Allows more various EventConfig types to be handled.  

## Event types  
- **ClientEvent** - client related events. ID: 1, 3, 4, 11  
- **TableEvent** - table related events. ID: 2, 12
- **ErrorEvent** - errors. ID: 13
- **InfoEvent** - info messages. Created for debug purposes, but can be used for transfering messages between modules.  

**Tests are provided in test_files directory.**  

## Build info   

### Windows  
**requirements:**  
- cmake 3.28+
- mingw32-make
  
**command:**  
```
$ cmake.exe -G "MinGW Makefiles" -S . -B .\build
$ cd build
$ mingw32-make.exe
```
### Linux  
**requirements:**  
- cmake 3.28+
- make 4.2.1+
- clang 10.0+
  
**command:**  
```
$ cmake -S . -B build_linux
$ cd build
$ make
```
