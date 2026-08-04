#pragma once
#include "Opcode.h"
#include <vector>
#include <string>

/*
1. Retrieve function that retrieves instructions.
2. Decode function that decodes the instruction and memory address (if there is one).
3. Convert to Machine Code.
*/

class Assembler
{
public:
    // Opcode converted to machine code and added to machine code vector.
    std::vector<int> machineCode;

    // Retrieved Opcode.
    Opcode code;

    // Retrieved Address.
    int address;

    // Useful Functions (You know what I am going to say.)
    void retrieve(), convert();
    Opcode decodeCode(std::string);
    int decodeAddress(std::string);
};