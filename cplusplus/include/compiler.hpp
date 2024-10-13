#ifndef COMPILER_HPP
#define COMPILER_HPP

// This compiler needs a C compiler (GCC as default)

#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <cstring>

#include "find_brackets.hpp"
#include "types.h"

// Change this if you are using a compiler other than GCC (at least the GCC C Compiler, you don't need the GCC Compiler Collection in full)
// Make sure that you know what you're doing when changing this commands
#define COMPILE_COMMAND "gcc -O3 output.c -o output -static -static-libgcc"
#define RUN_COMMAND "output.exe && echo."


/* Main function
 * Todo: change from "argc" and "argv" to the proper arguments
 * for now, it is just an extension of the main.cpp at the `src/` folder
 * that is executed based on a conditional
 */
int compile(int argc, const char ** argv);


#endif  // COMPILER_HPP
