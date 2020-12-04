#include <iostream>
#include <fstream>
#include <cstring>
#include <string>


#define HALT_OPCODE "19"


//Global registers/memory
unsigned char memory[65536];
unsigned int PC = 0;     //program counter
std::string IR;       //instruction register
unsigned int MAR;       //memory address register
unsigned char ACC;      //accumulator

std::string hex2bin(unsigned char hex)  //converts hex to binary for opcodes
{
    switch(hex)
    {
        case '0':
            return "0000";
        case '1':
            return "0001";
        case '2':
            return "0010";
        case '3':
            return "0011";
        case '4':
            return "0100";
        case '5':
            return "0101";
        case '6':
            return "0110";
        case '7':
            return "0111";
        case '8':
            return "1000";
        case '9':
            return "1001";
        case 'a':
            return "1010";
        case 'b':
            return "1011";
        case 'c':
            return "1100";
        case 'd':
            return "1101";
        case 'e':
            return "1110";
        case 'f':
            return "1111";
        default:
            std::cout<<"\nInvalid hex input\n";
    }
    return nullptr;
}


void fetchNextInstruction()
{
    //load memory from file into char array
    std::ifstream myfile ("mem_in", std::ios::in|std::ios::binary|std::ios::ate);
    if(myfile.is_open())
    {
        std::streampos size = myfile.tellg();
        myfile.seekg(0, std::ios::beg);
        myfile.read(reinterpret_cast<char *>(memory), size);
        myfile.close();
    }
    else
    {
        std::cout<<"file not found";
    }
    /*
     * fetch function steps
     * use PC as an index to retrieve an instruction from memory[]
     * store the retrieved instruction to the IR
     * determine from the instruction how much to increment PC so that it points to the next instruction in memory[]
     * perform the increment
    */
    IR = "";
    std::string tmp;
    tmp = memory[PC];
    IR.append(tmp);
    tmp = memory[PC+=1];
    IR.append(tmp);
    PC+=2;
    std::cout<<IR;
}

void executeInstruction()
{
    /*
     * execute instruction steps
     * examine IR to determine which operation to perform
     * perform operation on data in the registers and in memory[]
     */

    // memory operations
    if(IR.substr(0, 1) == "0")
    {
        if(IR.substr(1,1) == "0")
        {
            //store acc operand used as address 00
        }
        else if (IR.substr(1, 1) == "1")
        {
            //store acc operand used as constant 01
        }
        else if (IR.substr(1, 1) == "2")
        {
            //store acc MAR used as pointer
        }
        else if (IR.substr(1, 1) == "4")
        {
            //store index register operand used as address 00
        }
        else if (IR.substr(1, 1) == "5")
        {
            //store index register MAR operand used as const 01
        }
        else if (IR.substr(1, 1) == "6")
        {
            //store index register MAR indirect (MAR used as pointer)
        }
        else if (IR.substr(1, 1) == "8")
        {
            //load acc operand used as address 00
        }
        else if (IR.substr(1, 1) == "9")
        {
            //load acc operand used as const 01
        }
        else if (IR.substr(1, 1) == "a")
        {
            //load acc indirect (MAR used as pointer)
        }
        else if (IR.substr(1, 1) == "c")
        {
            //load MAR operand as address 00
        }
        else if (IR.substr(1, 1) == "d")
        {
            //load MAR opearnd as const 01
        }
        else if (IR.substr(1, 1) == "e")
        {
            //load MAR indirect (MAR used as ptr)
        }
    }
    else if(IR.substr(0, 1) != "0")
    {

    }

}

int main() {

    while (IR != HALT_OPCODE)
    {
        fetchNextInstruction();
        std::cout<<"\n";
        executeInstruction();
    }
    return 0;
}


