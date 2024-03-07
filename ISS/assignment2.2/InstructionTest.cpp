#include "instruction.h"
#include "registers.h"
#include "registers.cpp"

int main() 
{
    Registers regs;

    // Set the value of some registers
    regs.setRegister(1, 10);
    regs.setRegister(2, 20);
    regs.setRegister(3, 30);
    regs.setRegister(4, 40);

    // Test AddInstruction
    AddInstruction addInst(1, 2, 3);
    int nextInstruction = addInst.execute(&regs);
    addInst.dissassemble();
    // Check the value of nextInstruction and the state of regs
    regs.print();

    // Test SubInstruction
    SubInstruction subInst(1, 2, 3);
    subInst.dissassemble();
    nextInstruction = subInst.execute(&regs);
    // Check the value of nextInstruction and the state of regs
    regs.print();

    // Test OriInstruction
    OriInstruction oriInst(1, 2, 3);
    oriInst.dissassemble();
    nextInstruction = oriInst.execute(&regs);
    // Check the value of nextInstruction and the state of regs
    regs.print();

    return 0;
}