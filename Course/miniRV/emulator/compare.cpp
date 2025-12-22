#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

bool compare_one_line_files(const std::filesystem::path& path1,
                            const std::filesystem::path& path2,
                            const char* label)
{
    std::ifstream f1(path1);
    std::ifstream f2(path2);

    if (!f1 || !f2) {
        std::cerr << "Failed to open files for " << label << "\n";
        std::cerr << "  path1: " << path1 << "\n";
        std::cerr << "  path2: " << path2 << "\n";
        return false;
    }

    std::string line1, line2;
    std::getline(f1, line1);
    std::getline(f2, line2);

    if (line1 != line2) {
        std::cerr << label << " MISMATCH\n";
        return false;
    }

    std::cout << label << " MATCH\n";
    return true;
}

int main()
{
    bool instruction_ok = compare_one_line_files(
        std::filesystem::current_path() / "txt" / "golden_model_instruction.txt",
        std::filesystem::current_path() / "txt" / "top_module_instruction.txt",
        "INSTRUCTION"
    );

    bool pc_ok = compare_one_line_files(
        std::filesystem::current_path() / "txt" / "golden_model_pc.txt",
        std::filesystem::current_path() / "txt" / "top_module_pc.txt",
        "PC"
    );

    bool reg_ok = compare_one_line_files(
        std::filesystem::current_path() / "txt" / "golden_model_register.txt",
        std::filesystem::current_path() / "txt" / "top_module_register.txt",
        "REGISTERS"
    );

    if (pc_ok && reg_ok && instruction_ok) {
        std::cout << "\nALL CHECKS PASSED\n";
        return 0;
    } else {
        std::cerr << "\nCHECK FAILED\n";
        return 1;
    }
}