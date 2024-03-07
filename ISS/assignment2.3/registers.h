#ifndef _REGISTERS_H_
#define _REGISTERS_H_


class Registers
{
public:
    // constructor
    Registers ();
    void setRegister (int regNum, int value);
    int getRegister (int regNum);
    void setPC (int value);
    int getPC ();

    void print ();
private:
    int registers[32];
    int PC;
};

#endif	/* _REGISTERS_H_ */
