#pragma once
#include <cstdint>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

class minirvEmulator
{
public:
    minirvEmulator()  = default;
    ~minirvEmulator() = default;
    void            Evaluate(uint32_t instruction);
    uint32_t        GetRegisterValue(uint8_t reg_num);
    uint32_t        GetPCValue();
    uint32_t        GetInstructionMemoryValue(uint32_t address);
    uint32_t        GetDataMemoryValue(uint32_t address);
	void 		    SetRegisterValue(uint8_t reg_num, uint32_t value);
	void            SetPCValue(uint32_t pc);
	void            SetInstructionMemoryValue(uint32_t address, uint32_t value);
    void            SetDataMemoryValue(uint32_t address, uint32_t value);
	void            ResetRegisters();
    void 		    ResetPC(); // Reset Program Counter to 0
	void            ResetInstructionMemory(); // Reset all memory to 0
	void            ResetDataMemory(); // Reset all memory to 0
	void            Step();
	bool 	        LoadInstructionMemoryFromFile(const std::string& filename, uint32_t start_address);
private:
    std::vector<uint32_t>       registers_          = std::vector<uint32_t>(32, 0); // 32 registers
    std::vector<uint32_t>       instruction_memory_ = std::vector<uint32_t>(16777216, 0); // 2^24 memory locations
    std::vector<uint32_t>       data_memory_        = std::vector<uint32_t>(1073741824, 0); // 2^30 memory locations
    uint32_t 	                pc_                 = 0; // Program Counter
};