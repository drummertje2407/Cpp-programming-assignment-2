#include <iostream>
#include "registers.h"
#include "registers.cpp"

using namespace std;

int main()
{
    Registers A;
    A.print();
    A.setRegister(20, 2);
    A.setPC(102);
    A.print();
}