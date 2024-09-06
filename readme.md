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
