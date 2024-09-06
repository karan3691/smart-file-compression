#include "benchmark.h"
#include <iostream>
#include <chrono>

void benchmarkCompression() {
    auto start = std::chrono::high_resolution_clock::now();
    
    // Call your compression function here, e.g.:
    // compressHuffman();
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    
    std::cout << "Compression time: " << duration.count() << " seconds" << std::endl;
}
