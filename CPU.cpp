#include <iostream>
#include <string>

class CPU
{
public:
    // Uh dont know what to call it but I guess the boxes that you saw in LMC.
    int registers[4], memory[256] = {0}, programCounter = 0, instruction,
                      accumulator = 0, memory_address;

    bool running = true;

    std::string operation;

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
        operation = "HALT";
    }
    else if (instruction == 901)
    {
        operation = "INPUT";
    }
    else if (instruction == 902)
    {
        operation = "OUTPUT";
    }
    else if (instruction / 100 == 1)
    {
        operation = "ADD";
    }
    else if (instruction / 100 == 5)
    {
        operation = "LDA";
    }
    else if (instruction / 100 == 6)
    {
        operation = "STO";
    }

    if (instruction / 100 != 9)
        memory_address = instruction % 100;
}

void CPU::execute() // Executes the instruction.
{
    int data;

    if (operation == "HALT")
    {
        running = false;
    }
    else if (operation == "INPUT")
    {
        std::cout << "Input: ";
        std::cin >> accumulator;

        programCounter++;
    }
    else if (operation == "OUTPUT")
    {
        std::cout << "Output: \n"
                  << accumulator;

        programCounter++;
    }
    else if (operation == "ADD")
    {
        data = memory[memory_address];

        accumulator += data;

        programCounter++;
    }
    else if (operation == "LDA")
    {
        accumulator = memory[memory_address];

        programCounter++;
    }
    else if (operation == "STO")
    {
        memory[memory_address] = accumulator;

        programCounter++;
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

    cpu.memory[0] = 901;
    cpu.memory[1] = 113;
    cpu.memory[2] = 550;
    cpu.memory[3] = 113;
    cpu.memory[4] = 614;
    cpu.memory[13] = 46;
    cpu.memory[50] = 10;

    cpu.run();

    std::cout << cpu.memory[14];

    return 0;
}