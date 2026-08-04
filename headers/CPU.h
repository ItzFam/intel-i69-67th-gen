#pragma once
#include "Opcode.h"

class CPU
{
public:
    // Uh dont know what to call it but I guess the boxes that you saw in LMC.
    int registers[4], memory[256] = {0}, programCounter = 0, instruction,
                      accumulator = 0, memory_address;

    bool running = true;

    Opcode operation;

    // Useful Functions (No I am not going to explain them here)
    void run(), fetch(), decode(), execute(), addToMemory();
};