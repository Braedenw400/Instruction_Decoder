#include <iostream>
#include <fstream>
#include <cstring>
#include <string>


#define HALT_OPCODE "19"


//Global registers/memory
unsigned char memory[65536];
unsigned int PC = 0;     //program counter
//unsigned char IR;       //instruction register
std::string IR;
unsigned int MAR;       //memory address register
unsigned char ACC;      //accumulator


std::string hex2bin(unsigned char hex)  //converts hex to binary for opcodes, might need it later
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

    //IR = "0x";
    IR = "";
    std::string tmp1;
    std::string tmp2;
    tmp1 = memory[PC];
    IR.append(tmp1);
    tmp2 = memory[PC+=1];
    IR.append(tmp2);


    //does convert to char, but breaks down the line since its a ptr, also can't make IR unsigned
    //char *IR_c = &IR[0];
    //std::cout<<IR_c;

    //if the first digit begins with 1, it is a math operation
    if(tmp1 == "8" || tmp1 == "9" || tmp1 == "a" || tmp1 == "b" || tmp1 == "c" || tmp1 == "d" || tmp1 == "e" || tmp1 == "f")
    {
        if(tmp2 == "0")
        {
            //indirect mar used as ptr, indirect mar used as ptr
        }
        if(tmp2 == "1")
        {
            //indirect mar used as ptr, accumulator
        }
        if(tmp2 == "2")
        {
            //indirect mar used as ptr, 16 bit constant
        }
        if(tmp2 == "3")
        {
            //indirect mar used as ptr, 16 bit memory op
        }
        if(tmp2 == "4")
        {
            //acc, indirect mar used as ptr
        }
        if(tmp2 == "5")
        {
            //acc, acc
        }
        if(tmp2 == "6")
        {
            //acc, 8 bit const
        }
        if(tmp2 == "7")
        {
            //acc, 16 bit memory op
        }
        if(tmp2 == "8")
        {
            //address register mar, indirect mar used as pointer
        }
        if(tmp2 == "9")
        {
            //address register mar, acc
        }
        if(tmp2 == "a")
        {
            //address register mar, constant
        }
        if(tmp2 == "b")
        {
            //address register mar, memory
        }
        if(tmp2 == "c")
        {
            //memory, indirect mar used as ptr
        }
        if(tmp2 == "d")
        {
            //memory, acc
        }
        if(tmp2 == "e")
        {
            //memory, constant
        }
        if(tmp2 == "f")
        {
            //memory, memory
        }
    }
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
            //load MAR operand as const 01
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


