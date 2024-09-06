#include <iostream>
#include "file_handler.h"
#include "huffman.h"
#include "rle.h"
#include "utils.h"

int main() {
    std::string filePath = "example.txt";

    // Determine the file extension and choose compression method
    std::string ext = getFileExtension(filePath);
    
    if (ext == "txt") {
        std::cout << "Using Huffman compression for text file." << std::endl;
        compressHuffman(filePath);
    } else if (ext == "bmp") {
        std::cout << "Using RLE compression for image file." << std::endl;
        compressRLE(filePath);
    } else {
        std::cout << "Unsupported file type." << std::endl;
    }
    
    return 0;
}
