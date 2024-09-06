#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
#include <bitset>

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

void generateCodes(Node* root, std::unordered_map<char, std::string>& codes, std::string currentCode) {
    if (!root) return;

    if (root->ch != '\0') {
        codes[root->ch] = currentCode;
    }

    generateCodes(root->left, codes, currentCode + "0");
    generateCodes(root->right, codes, currentCode + "1");
}

inline void compressHuffman(const std::string &filePath) {
    std::unordered_map<char, int> freqTable;
    std::ifstream file(filePath, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return;
    }

    std::cout << "File opened successfully: " << filePath << std::endl;

    char ch;
    while (file.get(ch)) {
        freqTable[ch]++;
    }
    file.close();

    std::cout << "Frequency table constructed." << std::endl;

    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
    for (auto &pair : freqTable) {
        pq.push(new Node(pair.first, pair.second));
    }

    std::cout << "Priority queue populated." << std::endl;

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    Node* root = pq.top();
    if (!root) {
        std::cerr << "Error: Huffman Tree could not be constructed." << std::endl;
        return;
    }

    std::cout << "Huffman Tree constructed." << std::endl;

    std::unordered_map<char, std::string> huffmanCodes;
    generateCodes(root, huffmanCodes, "");

    std::ifstream inFile(filePath, std::ios::binary);
    std::ofstream outFile("compressed_huffman.dat", std::ios::binary);

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error: Could not open files for reading or writing." << std::endl;
        return;
    }

    std::cout << "Files opened for compression." << std::endl;

    std::string compressedData;
    while (inFile.get(ch)) {
        compressedData += huffmanCodes[ch];
    }

    inFile.close();
    std::cout << "File read and data compressed." << std::endl;

    while (compressedData.size() % 8 != 0) {
        compressedData += "0";  // Padding
    }

    for (size_t i = 0; i < compressedData.size(); i += 8) {
        std::bitset<8> byte(compressedData.substr(i, 8));
        outFile.put(static_cast<unsigned char>(byte.to_ulong()));
    }

    outFile.close();

    std::cout << "Compression completed and file written." << std::endl;

    std::ifstream compressedFile("compressed_huffman.dat", std::ios::binary);
    compressedFile.seekg(0, std::ios::end);
    std::streamsize compressedSize = compressedFile.tellg();
    compressedFile.close();

    std::ifstream originalFile(filePath, std::ios::binary);
    originalFile.seekg(0, std::ios::end);
    std::streamsize originalSize = originalFile.tellg();
    originalFile.close();

    std::cout << "Huffman compression completed for: " << filePath << std::endl;
    std::cout << "Original file size: " << originalSize << " bytes" << std::endl;
    std::cout << "Compressed file size: " << compressedSize << " bytes" << std::endl;
}

#endif
