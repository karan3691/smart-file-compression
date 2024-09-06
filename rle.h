#ifndef RLE_H
#define RLE_H

#include <iostream>
#include <fstream>

inline void compressRLE(const std::string &filePath) {
    std::ifstream file(filePath, std::ios::binary);
    std::ofstream outFile("compressed_rle.dat", std::ios::binary);
    
    char currentChar, prevChar;
    int count = 1;

    if (file.get(prevChar)) {
        while (file.get(currentChar)) {
            if (currentChar == prevChar) {
                count++;
            } else {
                outFile << prevChar << count;
                prevChar = currentChar;
                count = 1;
            }
        }
        outFile << prevChar << count;  // Write the last sequence
    }

    file.close();
    outFile.close();
    std::cout << "RLE compression completed for: " << filePath << std::endl;
}

#endif
