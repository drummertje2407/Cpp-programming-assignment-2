#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#include <iostream>
#include "registers.h"
//#include "registers.cpp"

using namespace std;

class Instruction
{
    public:
    Instruction(int arg_a, int arg_b, int arg_c)
    {
        a = arg_a;
        b = arg_b;
        c = arg_c;
    }

    // get a b c
    int getA() { return a; }
    int getB() { return b; }
    int getC() { return c; }


    virtual void dissassemble() = 0;

    //Implement the member function int execute (Registers *) as a pure virtual function
    virtual int execute(Registers *) = 0;

    // implement the destructor. as a virtual function
    //virtual ~Instruction();
  

    private:
        int a, b, c;

};

//Use the abstract base class Instruction to create the derived classes AddInstruction, SubInstruction, and OriInstruction
class AddInstruction : public Instruction
{
    public:	
    AddInstruction(int arg_a, int arg_b, int arg_c) : Instruction(arg_a, arg_b, arg_c) 
    {
        a = arg_a;
        b = arg_b;
        c = arg_c;
    }

    void dissassemble()
    {
        cout << "add " << a << ", " << b << ", " << c << endl;
    }

    int execute(Registers *registers)
    {
        registers->setRegister(a, registers->getRegister(b) + registers->getRegister(c));
        return registers->getPC() + 1;
    }


    private:
        int a, b, c;
};

class SubInstruction : public Instruction
{
    public:
    SubInstruction(int arg_a, int arg_b, int arg_c) : Instruction(arg_a, arg_b, arg_c) 
    {
        a = arg_a;
        b = arg_b;
        c = arg_c;
    }

    void dissassemble()
    {
        cout << "sub " << a << ", " << b << ", " << c << endl;
    }

    int execute(Registers *registers)
    {
        registers->setRegister(a, registers->getRegister(b) - registers->getRegister(c));
        return registers->getPC() + 1;
    }
    private:
        int a, b, c;
};

class OriInstruction : public Instruction
{
    public:
    OriInstruction(int arg_a, int arg_b, int arg_c) : Instruction(arg_a, arg_b, arg_c) 
    {
        a = arg_a;
        b = arg_b;
        c = arg_c;
    }

    void dissassemble()
    {
        cout << "ori " << a << ", " << b << ", " << c << endl;
    }

    int execute(Registers *registers)
    {
        registers->setRegister(a, registers->getRegister(b) | c);
        return registers->getPC() + 1;
    }
    private:
        int a, b, c;
};

/* The MIPS brne instruction is a branch instruction. The brne instruction encodes the destination address as a number relative to the current value of the program counter + 4 (PC-relative addressing). In this simple simulator the program counter counts instructions and not actual addresses. The destination address is thus encoded as a number
relative to the current value of the program counter + 1.*/
class BrneInstruction : public Instruction
{
    public:
    BrneInstruction(int arg_a, int arg_b, int arg_c) : Instruction(arg_a, arg_b, arg_c) 
    {
        a = arg_a;
        b = arg_b;
        c = arg_c;
    }

    void dissassemble()
    {
        cout << "brne " << a << ", " << b << ", " << c << endl;
    }

    int execute(Registers *registers)
    {
        if (registers->getRegister(a) != registers->getRegister(b))
        {
            return registers->getPC() + c;
        }
        else
        {
            return registers->getPC() + 1;
        }
    }
    private:
        int a, b, c;
};


#endif /* _INSTRUCTION_H_ */


