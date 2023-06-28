# SDL2 and Emscripten WebGL Demo

This repository is a simple demonstration of compiling SDL2 C++ code into WebAssembly using the Emscripten compiler, which can then be executed in a web browser using WebGL. The demo showcases a bouncing square which starts from the centre of the window and move in a random direction. When it collides with the window border, it will bounce back, changing its colour randomly.

## Technology Stack

The application is built using the following technologies:

1. **SDL2**: Simple DirectMedia Layer is a cross-platform development library designed to provide low-level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D.
2. **C++**: The application logic is written in C++.
3. **Emscripten**: Emscripten is an LLVM-to-Web Compiler. It takes LLVM bytecode (e.g., compiled from C/C++ using Clang, or from another language) and compiles that into WebAssembly, which can be run on the web.
4. **WebAssembly (Wasm)**: Wasm is a binary instruction format for a stack-based virtual machine. Wasm is designed as a portable target for the compilation of high-level languages like C++, enabling deployment on the web for client and server applications.
5. **WebGL**: WebGL (Web Graphics Library) is a JavaScript API for rendering interactive 2D and 3D graphics within any compatible web browser without the use of plug-ins.

## Running the Project

Follow the steps outlined in the project's Makefile to compile and run the application in your web browser. Or view the project via the hosted demo site: [https://bouncing-square-demo.pages.dev/](https://bouncing-square-demo.pages.dev/)
