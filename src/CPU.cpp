#include <iostream>
#include "..\headers\CPU.h"
#include "..\headers\Assembler.h"

void CPU::fetch() // Retrieves the instruction in the memory.
{
    instruction = memory[programCounter];
}

void CPU::decode() // Decodes instruction.
{
    if (instruction == 0)
    {
        operation = Opcode::HLT;
    }
    else if (instruction == 901)
    {
        operation = Opcode::INP;
    }
    else if (instruction == 902)
    {
        operation = Opcode::OUT;
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
        operation = Opcode::INV;
    }

    if (instruction / 100 != 9)
        memory_address = instruction % 100;
}

void CPU::execute() // Executes the instruction.
{
    if (operation == Opcode::HLT)
    {
        running = false;
    }
    else if (operation == Opcode::INP)
    {
        std::cout << "Input: ";
        std::cin >> accumulator;

        programCounter++;
    }
    else if (operation == Opcode::OUT)
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
    else if (operation == Opcode::INV)
    {
        std::cout << "Invalid instruction.";
        running = false;
    }
}

void CPU::run()
{
    addToMemory();

    while (running)
    {
        fetch();
        decode();
        execute();
    }
}

void CPU::addToMemory()
{
    Assembler con;

    con.retrieve();

    for (size_t i = 0; i < con.machineCode.size(); i++)
    {
        memory[i] = con.machineCode[i];
    }
}