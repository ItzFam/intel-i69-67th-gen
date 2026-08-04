#pragma once

enum class Opcode
{
    INV = -1,
    HLT = 0,
    ADD = 1,
    SUB = 2,
    LDA = 5,
    STO = 6,
    BRA = 7,
    BRZ = 8,
    INP = 901,
    OUT = 902
};