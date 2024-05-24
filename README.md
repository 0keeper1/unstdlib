# unstdlib

**unstdlib** is a modern and evolving C (un)standard library designed to enhance productivity and performance in C
programming. By providing a robust set of abstractions and utilities, unstdlib aims to simplify common tasks and reduce
boilerplate code, allowing developers to focus on writing efficient and maintainable code.

## Key Features

- **Enhanced Abstractions**: Intuitive abstractions for common data structures and algorithms to streamline development.
- **Performance-Oriented**: Optimized for speed and memory efficiency as much as possible, ensuring minimal overhead.
- **Ease of Use**: Designed with simplicity in mind, making C development more accessible and enjoyable.
- **Modular Design**: Flexible and modular architecture, enabling developers to use only the components they need.
- **Rich Function Support**: Functions that support a wide range of data types, providing versatility and flexibility.
- **Comprehensive Documentation**: Each function comes with complete documentation to facilitate easy usage and
  integration.

## Build

To build unstdlib, follow these steps:

1. **Ensure you have CMake installed.** If not, download and install it from [cmake.org](https://cmake.org/).
2. **Open your terminal and navigate to the project directory.**
3. **Run the following command:**
   ```sh
   cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -G "Unix Makefiles" -S ./ -B ./cmake-build-release
   ```
4. **Build the project by running:**
   ```sh
   cmake --build ./cmake-build-release
   ```

This will configure and build the project in the `cmake-build-release` directory.

## Getting Started

Currently in active development, unstdlib welcomes contributions and feedback from the community. Stay tuned for
upcoming releases :)

## Compatibility

**unstdlib** is based on GCC version 11. Ensure that you have GCC 11 installed on your system to avoid compatibility
issues.

## Contributing

I would even appreciate a cat's help.

---

###### So that one day I can leave it behind as part of my legacy.