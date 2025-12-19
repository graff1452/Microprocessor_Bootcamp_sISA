#include "scpu_generator.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <random>

uint8_t ScpuInstructionGenerator::Generate() {
    return static_cast<uint8_t>(std::rand() & 0xFF);  // Generate a random 8-bit instruction
}

int main(int argc, char* argv[])
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));  // Seed for random values
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <number_of_instructions>" << std::endl;
        return 1;
    }

    int num_instructions = std::atoi(argv[1]);
    if (num_instructions <= 0)
    {
        std::cerr << "Number of instructions must be a positive integer." << std::endl;
        return 1;
    }
    std::ofstream output_file("instructions.txt");
    if (!output_file)
    {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }
    ScpuInstructionGenerator generator;
    for (int i = 0; i < num_instructions; ++i)
    {
        uint8_t instruction = generator.Generate();
        output_file << std::hex << std::uppercase << static_cast<int>(instruction) << std::endl;
    }
    output_file.close();
    std::cout << "Generated " << num_instructions << " instructions and saved to instructions.txt" << std::endl;
    return 0;
}