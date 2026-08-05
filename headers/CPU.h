#pragma once
#include "Opcode.h"
#include <vector>

class CPU
{
public:
    // Uh dont know what to call it but I guess the boxes that you saw in LMC.
    int registers[4], programCounter = 0, instruction, memory_address;

    long long memory[256] = {0}, accumulator = 0;

    bool running = true;

    Opcode operation;

    // Useful Functions (No I am not going to explain them here)
    void run(), fetch(), decode(), execute(), addToMemory(std::vector<int>);
};