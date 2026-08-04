#pragma once

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