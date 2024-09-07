# Smart File Compression System

## Overview

The Smart File Compression System is a C++ application designed to compress files using a custom Huffman compression algorithm. The system reads a text file, computes character frequencies, builds a Huffman tree, generates Huffman codes, and compresses the file based on these codes. The result is a compressed binary file with reduced size.

## Features

- **Custom Huffman Compression**: Implements Huffman coding to compress text files.
- **File Handling**: Handles file reading and writing with error checking.
- **Compression Metrics**: Provides information on the original and compressed file sizes.

## Prerequisites

- **C++ Compiler**: Requires a C++11 compatible compiler (e.g., `g++`).
- **Operating System**: Tested on macOS.

## Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/karan3691/smart-file-compression.git
   cd smart-file-compression
   ```

2. **Compile the code**:
   ```bash
   g++ -std=c++11 main.cpp -o main
   ```

## Usage

- **Prepare Your File:** Ensure you have a text file named example.txt in the same directory as the executable.
- **Run the Program:**
  ```bash
  g++ -std=c++11 main.cpp -o main
  ```
  The program will output the results of the compression and display the sizes of the original and compressed files.


  ## Example Output

  ```bash
  Starting compression for file: example.txt
  File opened successfully.
  Character frequencies calculated.
  Priority queue created.
  Huffman Tree constructed.
  Huffman codes generated.
  Compression completed and file saved.
  Huffman compression completed for: example.txt
  Original file size: 39 bytes
  Compressed file size: 25 bytes
  ```


  ## Contributing

  If you have suggestions or improvements, feel free to open an issue or submit a pull request.


  

  
