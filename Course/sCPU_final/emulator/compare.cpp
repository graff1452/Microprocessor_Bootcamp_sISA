#include <iostream>
#include <fstream>
#include <string>

#define PCOUTGOLDENMODELFILEPATH       "/home/graff145/Desktop/Microprocessor_Bootcamp_sISA/Course/sCPU_final/emulator/txt/pc_out_golden_model.txt"
#define PCOUTTOPMODULEFILEPATH         "/home/graff145/Desktop/Microprocessor_Bootcamp_sISA/Course/sCPU_final/emulator/txt/pc_out_top_module.txt"
#define REGISTERGOLDENMODELFILEPATH    "/home/graff145/Desktop/Microprocessor_Bootcamp_sISA/Course/sCPU_final/emulator/txt/register_golden_model.txt"
#define REGISTERTOPMODULEFILEPATH      "/home/graff145/Desktop/Microprocessor_Bootcamp_sISA/Course/sCPU_final/emulator/txt/register_top_module.txt"

bool compare_one_line_files(const char* path1, const char* path2, const char* label)
{
    std::ifstream f1(path1);
    std::ifstream f2(path2);

    if (!f1 || !f2) {
        std::cerr << "Failed to open files for " << label << "\n";
        return false;
    }

    std::string line1, line2;

    std::getline(f1, line1);
    std::getline(f2, line2);

    if (line1 != line2) {
        std::cerr << label << " MISMATCH\n";
        std::cerr << "Golden : " << line1 << "\n";
        std::cerr << "Top    : " << line2 << "\n";
        return false;
    }

    std::cout << label << " MATCH\n";
    return true;
}

int main()
{
    bool pc_ok = compare_one_line_files(
        PCOUTGOLDENMODELFILEPATH,
        PCOUTTOPMODULEFILEPATH,
        "PC"
    );

    bool reg_ok = compare_one_line_files(
        REGISTERGOLDENMODELFILEPATH,
        REGISTERTOPMODULEFILEPATH,
        "REGISTERS"
    );

    if (pc_ok && reg_ok) {
        std::cout << "\nALL CHECKS PASSED\n";
        return 0;
    } else {
        std::cerr << "\nCHECK FAILED\n";
        return 1;
    }
}
