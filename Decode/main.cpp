#include <iostream>

void fetchNextInstruction()
{
    std::cout << "Instruction fetched\n";
}

void executeInstruction()
{
    std::cout << "Instruction executed\n";
}

int main() {
    fetchNextInstruction();
    executeInstruction();
    return 0;
}
