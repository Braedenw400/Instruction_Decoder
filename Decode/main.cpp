#include <iostream>
#include <fstream>


#define HALT_OPCODE 0x19


//Global registers/memory
unsigned char memory[65536];
unsigned int PC;    //program counter
unsigned char IR;     //instruction register
unsigned int MAR;   //memory address register
unsigned char ACC;    //accumulator


void fetchNextInstruction()
{
    /*
     * fetch function steps
     * use PC as an index to retrieve an instruction from memory[]
     * store the retrieved instruction to the IR
     * determine from the instruction how much to increment PC so that it points to the next instruction in memory[]
     * perform the increment
    */

    std::cout << "Instruction fetched\n";
}

void executeInstruction()
{
    /*
     * execute instruction steps
     * examine IR to determine which operation to perform
     * perform operation on data in the registers and in memory[]
     */
    std::cout << "Instruction executed\n";
}

int main() {
    //load memory
    FILE * file = fopen("mem_in.txt", "r+");
    if (file == nullptr) std::cout<<"file not found";

    /*while (memory[PC] != HALT_OPCODE)
    {
        fetchNextInstruction();
        executeInstruction();
    }*/
    return 0;
}
