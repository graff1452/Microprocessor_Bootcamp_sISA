#pragma once
#include <cstdint>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

class ScpuEmulator
{
public:
    ScpuEmulator()  = default;
    ~ScpuEmulator() = default;
    void        Evaluate(uint8_t instruction);
    uint8_t     GetRegisterValue(uint8_t reg_num);
    uint8_t     GetPCValue();
    uint8_t     GetInstructionMemoryValue(uint8_t address);
    uint8_t     GetAluValue();
	void 		SetRegisterValue(uint8_t reg_num, uint8_t value);
	void        SetPCValue(uint8_t pc);
	void        SetInstructionMemoryValue(uint8_t address, uint8_t value);
    void        SetAluValue(uint8_t value);
	void        ResetRegisters();
    void 		ResetPC(); // Reset Program Counter to 0
	void        ResetInstructionMemory(); // Reset all memory to 0
    void        ResetAlu();
	void        Step();
	bool 	    LoadInstructionMemoryFromFile(const std::string& filename, uint8_t start_address);
private:
    std::vector<uint8_t>    registers_          = std::vector<uint8_t>(4, 0); // 4 registers
    std::vector<uint8_t>    instruction_memory_ = std::vector<uint8_t>(16, 0); // 16 memory locations
    uint8_t 	            pc_                 = 0; // Program Counter
    uint8_t                 alu_                = 0;
};