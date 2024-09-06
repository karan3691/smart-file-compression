#include "file_handler.h"
#include <fstream>
#include <iostream>

void readFile(const std::string &filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (file) {
        std::cout << "File opened successfully." << std::endl;
        // Handle file reading logic
    } else {
        std::cerr << "Failed to open file!" << std::endl;
    }
    file.close();
}
