# MySTL - Custom C++ Data Structures Library

A generic, template-based C++ library that implements fundamental data structures from scratch. This project is designed to mirror the philosophy and architecture of the C++ Standard Template Library (STL).

All data structures are neatly encapsulated within the `MySTL` namespace to prevent naming collisions and use robust memory management techniques (such as the Rule of Three/Zero) to ensure safe dynamic memory handling.

---

## Features

- **Fully Generic**: Uses C++ templates (`template <typename T>`) to support any data type.
- **Memory Safe**: Implements deep copying, copy-and-swap idioms, and safe dynamic allocations to prevent memory leaks and double-free errors.
- **Exception Handling**: Throws standard C++ exceptions (`std::out_of_range`) for bounds checking and underflows.
- **Container Adaptors**: Uses Composition to build structures like Stacks efficiently (similar to `std::stack`).
- **Modular Design**: Separates declarations (`.hpp`) and template implementations (`.tpp`) for clean code organization.

---

## Implemented Data Structures

### 1. Vector (`MySTL::Vector`)
A dynamic array that automatically resizes itself when capacity is reached.
- **Methods**: 
  - `push_back(val)`, `pop_back()`
  - `size()`, `capacity()`
  - `operator[]` (with bounds checking)
- **Memory**: Doubles capacity upon reallocation. Uses the Copy-and-Swap idiom for safe assignment.

### 2. Doubly Linked List (`MySTL::list`)
A sequential container that allows constant time insert and erase operations anywhere within the sequence.
- **Methods**:
  - `push_front(val)`, `push_back(val)`
  - `pop_front()`, `pop_back()`
  - `insert(pos, val)`, `erase(pos)`, `remove(val)`
  - `front()`, `back()`, `size()`, `isEmpty()`, `clear()`
- **Memory**: Manages custom `Node` objects. Follows the Rule of Three for deep copying.

### 3. Singly Linked List (`MySTL::forward_list`)
A lightweight list where each node only points to the next node.
- **Methods**:
  - `push_front(val)`, `push_back(val)`, `push_at(pos, val)`
  - `pop_front()`, `pop_back()`, `pop_at(pos)`
  - `front()`, `back()`, `find(val)`, `reverse()`, `remove(val)`

### 4. Stack (`MySTL::stack`)
A LIFO (Last-In-First-Out) data structure.
- **Architecture**: Implemented as a **Container Adaptor** using `MySTL::Vector` under the hood.
- **Methods**:
  - `push(val)`, `pop()`
  - `top()`
  - `size()`, `isEmpty()`

### 5. Queue (`MySTL::queue`)
A FIFO (First-In-First-Out) data structure.
- **Architecture**: Implemented using a circular buffer array to prevent costly element shifting.
- **Methods**:
  - `push(val)`, `pop()`
  - `front()`
  - `size()`, `isEmpty()`

---

## Project Structure

```text
ds_library/
├── CMakeLists.txt        # CMake build configuration
├── README.md             # Project documentation
├── .gitignore            # Git ignore rules for build files
├── src/                  # Source files (.tpp template implementations & main entry)
│   ├── main.cpp          # Test runner executable
│   ├── forwardList/
│   ├── list/
│   ├── queue/
│   ├── stack/
│   └── vector/
├── include/              # Header files (.hpp declarations)
│   ├── forwardList/
│   ├── list/
│   ├── queue/
│   ├── stack/
│   └── vector/
└── tests/                # Unit tests for each data structure
    ├── forwardList.cpp
    ├── list.cpp
    ├── queue.cpp
    ├── stack.cpp
    └── vector.cpp
```

---

## Building the Project

This project uses **CMake** as its build system.

### Prerequisites
- C++ Compiler (GCC/MinGW, Clang, or MSVC) supporting C++11 or higher.
- CMake (v3.10 or higher)

### Build Instructions (Terminal / Command Prompt)

1. **Generate the build files:**
   ```bash
   cmake -S . -B build
   ```

2. **Compile the project:**
   ```bash
   cmake --build build
   ```

---

## Running Tests

The project includes a robust test suite utilizing `cassert` to verify bounds, standard behaviors, and deep copies. After building the project, you can run all tests sequentially by executing the main binary.

**On Windows (MinGW/PowerShell):**
```bash
.\build\ds_library.exe
```

**On Linux / macOS:**
```bash
./build/ds_library
```

*If successful, the console will output standard success messages for each module and conclude with "All Tests Completed Successfully!".*

---

## Usage Example

Because the library uses header and template inclusion (`.hpp` and `.tpp`), you can easily use these structures in your own files by including the appropriate header:

```cpp
#include <iostream>
#include "include/vector/vector.hpp"

using namespace MySTL;

int main() {
    Vector<std::string> names;
    
    names.push_back("Alice");
    names.push_back("Bob");
    
    std::cout << "First name: " << names[0] << "\n";
    std::cout << "Total elements: " << names.size() << "\n";
    
    return 0;
}
```

---
**Author**: [Your Name/Handle]  
**License**: MIT