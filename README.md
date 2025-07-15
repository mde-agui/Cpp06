# C++ Module 06 - C++ Casts

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![macOS](https://img.shields.io/badge/macOS-000000?style=for-the-badge&logo=apple&logoColor=white)
![42](https://img.shields.io/badge/42-Project-00BABC?style=for-the-badge)
![Score](https://img.shields.io/badge/Score-100%25-brightgreen?style=for-the-badge)

## 📋 Project Overview

C++ Module 06 is the seventh project in the 42 school C++ curriculum, focusing on **C++ casts** (`static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`) in C++98. Through three exercises—**Scalar Converter**, **Serialization**, and **Identify Real Type**—this module teaches explicit type conversions, runtime type identification (RTTI), and exception handling. It enforces strict coding standards: no forbidden functions (`printf`, `alloc`, `free`), no STL containers/algorithms, explicit namespace usage, and no `<typeinfo>` header in ex02. The module prepares students for safe type manipulation, verified with `valgrind` for memory leaks.

## ✨ Key Features

- **Exercise 00: Scalar Converter**:
  - Implements a `ScalarConverter` class that converts a string literal (`char`, `int`, `float`, `double`) into all four types.
  - Handles edge cases: non-displayable characters, overflow (`2147483648`), pseudo-literals (`nan`, `inf`).
  - Uses `static_cast` for safe conversions and `std::fixed`/`std::setprecision(1)` for output formatting.
- **Exercise 01: Serialization**:
  - Implements a `Serializer` class to serialize a `Data*` pointer to a `uintptr_t` and deserialize it back.
  - Uses `reinterpret_cast` for pointer-to-integer conversions.
  - Demonstrates deep copying and memory safety.
- **Exercise 02: Identify Real Type**:
  - Implements `identify` functions to determine the type (`A`, `B`, `C`) of a `Base` object using `dynamic_cast`.
  - Handles pointer (`NULL` on failure) and reference (exception on failure) casts, catching `std::exception&` due to `<typeinfo>` restriction.
  - Uses polymorphic hierarchy with virtual destructor.
- **C++98 Compliance**:
  - Compiled with `-Wall -Wextra -Werror -std=c++98`.
  - No `using namespace`, `friend`, or forbidden functions (`printf`, `alloc`, `free`).
- **Norm Compliance**:
  - Adheres to 42’s coding standards, with newline-terminated outputs and no memory leaks (verified with `valgrind`).

## 🛠️ Prerequisites

- **Operating System**: UNIX-based (Linux, macOS, etc.).
- **Compiler**: `c++` (GCC or Clang, C++98 compatible).
- **Build Tool**: `make`.
- **Debugger**: `valgrind` for memory leak detection.

## 🚀 Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/mde-agui/Cpp06.git
   cd Cpp06
   ```

2. Navigate to an exercise directory and compile:
   ```bash
   cd ex00
   make
   ```
   Repeat for `ex01`, `ex02`. This creates executables (e.g., `convert`, `serialize`, `identify`).

## 📖 Usage

Each exercise is independent and run from its respective directory.

### Exercise 00: Scalar Converter
```bash
cd ex00
./convert 42
```
Output:
```
char: '*'
int: 42
float: 42.0f
double: 42.0
```
Tests: `9`, `2147483647`, `2147483648`, `'a'`, `nan`, `4.2f`.

### Exercise 01: Serialization
```bash
cd ex01
./serialize
```
Output:
```
Original Data:
Name: Test
Value: 42

Deserialized Data:
Name: Test
Value: 42
```

### Exercise 02: Identify Real Type
```bash
cd ex02
./identify
```
Output:
```
Testing pointers:
Pointer 0: A
Pointer 1: B
Pointer 2: C
Pointer 3: Null pointer

Testing references:
Reference 0: A
Reference 1: B
Reference 2: C
```

Check for memory leaks:
```bash
valgrind ./identify
```

## 📂 Project Structure

```
cpp_module_06/
├── ex00/                   # Scalar Converter: static_cast for type conversions
│   ├── Makefile
│   ├── ScalarConverter.hpp
│   ├── ScalarConverter.cpp
│   └── main.cpp
├── ex01/                   # Serialization: reinterpret_cast for pointer-integer conversion
│   ├── Makefile
│   ├── Data.hpp
│   ├── Serializer.hpp
│   ├── Serializer.cpp
│   └── main.cpp
├── ex02/                   # Identify Real Type: dynamic_cast with RTTI
│   ├── Makefile
│   ├── Base.hpp
│   ├── A.hpp
│   ├── B.hpp
│   ├── C.hpp
│   └── main.cpp
└── README.md               # This file
```

## 🛠️ Makefile Commands

Each exercise has its own `Makefile` with the following commands:

| Command       | Description                              |
|---------------|------------------------------------------|
| `make`        | Builds the executable (e.g., `convert`, `serialize`, `identify`). |
| `make clean`  | Removes object files.                    |
| `make fclean` | Removes object files and executable.     |
| `make re`     | Rebuilds the project from scratch.       |

## 🔍 Technical Details

- **C++ Concepts Covered**:
  - **C++ Casts**: Explicit type conversions using `static_cast`, `dynamic_cast`, `reinterpret_cast`, and understanding `const_cast`.
  - **Run-Time Type Information (RTTI)**: Enables `dynamic_cast` for type checking in ex02.
  - **Polymorphism**: Uses virtual destructors for safe deletion in ex02.
  - **Exception Handling**: Manages `dynamic_cast` reference failures in ex02 with `std::exception&` due to `<typeinfo>` ban.
  - **Memory Management**: Uses `new`/`delete` with `valgrind` verification.
- **Constraints**:
  - Compiled with `-Wall -Wextra -Werror -std=c++98`.
  - No `using namespace`, `friend`, or forbidden functions (`printf`, `alloc`, `free`).
  - No STL containers/algorithms.
  - No `<typeinfo>` in ex02, requiring `std::exception&` for `dynamic_cast` failures.
  - Outputs end with newlines.
- **External Functions**:
  - Allowed: `new`, `delete`, `std::string`, `std::cout`, `std::endl`, `std::istringstream`, `std::fixed`, `std::setprecision`, `std::exception`.
- **Error Handling**:
  - Validates inputs (e.g., overflow in ex00, NULL pointers in ex02).
  - Handles pseudo-literals (`nan`, `inf`) and non-displayable characters in ex00.

### Explanation of C++ Casts

C++ casts (`static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`) replace C-style casts (`(type)expression`) for safer, explicit type conversions. They are central to Module 06, used across all exercises.

- **static_cast**:
  - **Definition**: Performs compile-time conversions between related types (e.g., `int` to `float`, `char` to `int`, up/downcasting in known hierarchies).
  - **Usage in Module 06**: In ex00, `static_cast` converts parsed values to `char`, `int`, `float`, and `double` (e.g., `static_cast<float>(42)` for `42.0f`).
  - **Safety**: Safe for well-defined conversions; unsafe for overflow (e.g., large `double` to `int`) or incorrect downcasts.
  - **Example**:
    ```cpp
    int value = 42;
    std::cout << "float: " << static_cast<float>(value) << "f\n"; // Outputs: 42.0f
    ```
  - **Why Used**: Fast, explicit, and safe when types are validated (e.g., `isInt` in ex00).

- **dynamic_cast**:
  - **Definition**: Performs runtime type checking in polymorphic class hierarchies using RTTI, for safe downcasting or cross-casting.
  - **Usage in Module 06**: In ex02, `dynamic_cast` identifies if a `Base*` or `Base&` is an `A`, `B`, or `C` (e.g., `dynamic_cast<A*>(p)`).
  - **Safety**: Safe; returns `NULL` for pointers or throws `std::bad_cast` for references (caught as `std::exception&` in ex02 due to `<typeinfo>` ban).
  - **Example**:
    ```cpp
    Base* p = new A;
    if (dynamic_cast<A*>(p)) std::cout << "A\n"; // Outputs: A
    ```
  - **Why Used**: Ensures correct type casting at runtime, preventing undefined behavior.

- **const_cast**:
  - **Definition**: Adds or removes `const` or `volatile` qualifiers from a variable.
  - **Usage in Module 06**: Not used directly, but important to understand for completeness.
  - **Safety**: Safe only if the object wasn’t originally `const`; otherwise, undefined behavior.
  - **Example**:
    ```cpp
    const int x = 42;
    int* y = const_cast<int*>(&x); // Dangerous if x is truly const
    ```
  - **Why Used**: Rarely needed, but useful for legacy code or specific const modifications.

- **reinterpret_cast**:
  - **Definition**: Performs low-level, unsafe conversions between unrelated types (e.g., pointer to integer).
  - **Usage in Module 06**: In ex01, `reinterpret_cast` converts `Data*` to `uintptr_t` and back for serialization.
  - **Safety**: Unsafe; assumes the programmer knows the types are compatible. Invalid casts cause undefined behavior.
  - **Example**:
    ```cpp
    Data* ptr = new Data;
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr); // Serializes address
    ```
  - **Why Used**: Necessary for pointer-to-integer conversions in ex01.

**Comparison**:
- `static_cast` is fast and compile-time, used in ex00 for numeric conversions.
- `dynamic_cast` is runtime and safe, used in ex02 for polymorphic type checking.
- `const_cast` modifies constness, not used in Module 06.
- `reinterpret_cast` is unsafe, used in ex01 for serialization.
- Unlike C-style casts, these are explicit, safer, and easier to debug.

## 📝 Notes

- **Implementation Details**:
  - ex00: Uses `std::istringstream` for parsing and `static_cast` for conversions, with robust checks for overflow and non-printable chars.
  - ex01: Ensures `Data` fields are preserved after serialization/deserialization, using `reinterpret_cast` safely.
  - ex02: Handles `dynamic_cast` failures without `<typeinfo>`, using `std::exception&` for references and `NULL` for pointers.

## 📜 License

This project is licensed under the [MIT License](LICENSE).

## 👤 Author

**mde-agui**  
GitHub: [mde-agui](https://github.com/mde-agui)

---

⭐️ If you find this project useful, consider giving it a star on GitHub!
