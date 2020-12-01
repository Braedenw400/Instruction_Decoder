#include <iostream>

void fetchNextInstruction()
{
    std::cout << "Instruction fetched\n";
}

void exexuteInstruction()
{
    std::cout << "Instruction executed\n";
}

int main() {
    fetchNextInstruction();
    exexuteInstruction();
    return 0;
}
