#include "..\headers\Assembler.h"
#include "..\headers\Opcode.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

/*
1. Retrieve function that retrieves instructions.
2. Decode the instruction and memory address (if there is one).
3. Convert to Machine Code.
*/

void Assembler::retrieve()
{
    std::ifstream instructions("instructions.asm");
    std::string line;

    while (getline(instructions, line))
    {
        // Finds the opCode.
        code = decodeCode(line);

        // Finds the memory address.
        address = decodeAddress(line);

        if (static_cast<int>(code) / 100 == 9)
        {
            machineCode.push_back(static_cast<int>(code));
        }
        else
        {
            int mcode = static_cast<int>(code) * 100 + static_cast<int>(address);
            machineCode.push_back(mcode);
        }
    }
}

Opcode Assembler::decodeCode(std::string line)
{
    if (line.substr(0, 3) == "HLT")
    {
        return Opcode::HLT;
    }
    else if (line.substr(0, 3) == "ADD")
    {
        return Opcode::ADD;
    }
    else if (line.substr(0, 3) == "SUB")
    {
        return Opcode::SUB;
    }
    else if (line.substr(0, 3) == "LDA")
    {
        return Opcode::LDA;
    }
    else if (line.substr(0, 3) == "STO")
    {
        return Opcode::STO;
    }
    else if (line.substr(0, 3) == "BRA")
    {
        return Opcode::BRA;
    }
    else if (line.substr(0, 3) == "BRZ")
    {
        return Opcode::BRZ;
    }
    else if (line.substr(0, 3) == "INP")
    {
        return Opcode::INP;
    }
    else if (line.substr(0, 3) == "OUT")
    {
        return Opcode::OUT;
    }

    return Opcode::INV;
}

int Assembler::decodeAddress(std::string line)
{
    if (line == "INP" || line == "OUT" || line == "HLT")
    {
        return 0;
    }
    else
    {
        address = std::stoi(line.substr(4, line.length() - 4));
        return address;
    }
}
