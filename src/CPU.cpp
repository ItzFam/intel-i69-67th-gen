#include <iostream>
#include "D:\Pointers\headers\CPU.h"

void CPU::fetch() // Retrieves the instruction in the memory.
{
    instruction = memory[programCounter];
}

void CPU::decode() // Decodes instruction.
{

    if (instruction == 0)
    {
        operation = Opcode::HALT;
    }
    else if (instruction == 901)
    {
        operation = Opcode::INPUT;
    }
    else if (instruction == 902)
    {
        operation = Opcode::OUTPUT;
    }
    else if (instruction / 100 == 1)
    {
        operation = Opcode::ADD;
    }
    else if (instruction / 100 == 2)
    {
        operation = Opcode::SUB;
    }
    else if (instruction / 100 == 5)
    {
        operation = Opcode::LDA;
    }
    else if (instruction / 100 == 6)
    {
        operation = Opcode::STO;
    }
    else if (instruction / 100 == 7)
    {
        operation = Opcode::BRA;
    }
    else if (instruction / 100 == 8)
    {
        operation = Opcode::BRZ;
    }
    else
    {
        operation = Opcode::INVALID;
    }

    if (instruction / 100 != 9)
        memory_address = instruction % 100;
}

void CPU::execute() // Executes the instruction.
{
    if (operation == Opcode::HALT)
    {
        running = false;
    }
    else if (operation == Opcode::INPUT)
    {
        std::cout << "Input: ";
        std::cin >> accumulator;

        programCounter++;
    }
    else if (operation == Opcode::OUTPUT)
    {
        std::cout << "Output: \n"
                  << accumulator << std::endl;

        programCounter++;
    }
    else if (operation == Opcode::ADD)
    {
        accumulator += memory[memory_address];

        programCounter++;
    }
    else if (operation == Opcode::SUB)
    {
        accumulator -= memory[memory_address];

        programCounter++;
    }
    else if (operation == Opcode::LDA)
    {
        accumulator = memory[memory_address];

        programCounter++;
    }
    else if (operation == Opcode::STO)
    {
        memory[memory_address] = accumulator;

        programCounter++;
    }
    else if (operation == Opcode::BRA)
    {
        programCounter = memory_address;
    }
    else if (operation == Opcode::BRZ)
    {
        if (accumulator == 0)
        {
            programCounter = memory_address;
        }
        else
        {
            programCounter++;
        }
    }
    else if (operation == Opcode::INVALID)
    {
        std::cout << "Invalid instruction.";
        running = false;
    }
}

void CPU::run()
{
    while (running)
    {
        fetch();
        decode();
        execute();
    }
}