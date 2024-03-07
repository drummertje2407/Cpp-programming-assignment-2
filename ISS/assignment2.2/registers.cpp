#include <iostream>
#include "registers.h"
using namespace std;

Registers::Registers()
{
    // initialize the registers
    for (int i = 0; i < 32; i++)
    {
        registers[i] = 0;
    }
    // initialize the program counter
    PC = 0;
}

void Registers::setRegister(int regNum, int value)
{
    // set the value of the register
    if (regNum == 0) // zero register must always remain zero
    {
        return;
    }
    registers[regNum] = value;
}

int Registers::getRegister(int regNum)
{
    // get the value of the register
    return registers[regNum];
}

void Registers::setPC(int value)
{
    // set the value of the program counter
    PC = value;
}

int Registers::getPC()
{
    // get the value of the program counter
    return PC;
}

void Registers::print()
{
    // print the values of the registers
    cout << "Registers:" << endl;
    for (int i = 0; i < 32; i++)
    {
        cout << "R" << i << ": " << registers[i] << endl;
    }
    cout << "PC: " << PC << endl;
}
