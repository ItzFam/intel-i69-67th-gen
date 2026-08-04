#include <iostream>
#include "..\headers\CPU.h"
#include "..\headers\Assembler.h"

int main()
{
    CPU cpu;
    Assembler code;

    // Retrieving the machine code.
    code.retrieve();

    // Adding it to memory.
    cpu.addToMemory(code.machineCode);

    // Runs the CPU.
    cpu.run();

    return 0;
}