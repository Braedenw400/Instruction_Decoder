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

    for(int i = 0; i<sizeof(memory); i++)
    {
        i = IR;
        std::cout<<IR;
    }

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
    std::ifstream myfile ("mem_in", std::ios::in|std::ios::binary|std::ios::ate);
    if(myfile.is_open())
    {
        std::streampos size = myfile.tellg();
        myfile.seekg(0, std::ios::beg);
        myfile.read(reinterpret_cast<char *>(memory), size);
        myfile.close();

        while (memory[PC] != HALT_OPCODE)
        {
            fetchNextInstruction();
            //executeInstruction();
        }

    }
    else
    {
        std::cout<<"file not found";
    }

    return 0;
}
