#include <iostream>

enum class Opcode
{
    INVALID = -1,
    HALT = 0,
    ADD = 1,
    SUB = 2,
    LDA = 5,
    STO = 6,
    BRA = 7,
    BRZ = 8,
    INPUT = 901,
    OUTPUT = 902
};

class CPU
{
public:
    // Uh dont know what to call it but I guess the boxes that you saw in LMC.
    int registers[4], memory[256] = {0}, programCounter = 0, instruction,
                      accumulator = 0, memory_address;

    bool running = true;

    Opcode operation;

    // Useful Functions (No I am not going to explain them here)
    void run(), fetch(), decode(), execute();
};

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

int main()
{
    CPU cpu;

    cpu.memory[0] = 901; // Input 520
    cpu.memory[1] = 713;
    cpu.memory[13] = 605;
    cpu.memory[14] = 705;
    cpu.memory[6] = 878;
    cpu.memory[78] = 902;

    cpu.run();

    return 0;
}