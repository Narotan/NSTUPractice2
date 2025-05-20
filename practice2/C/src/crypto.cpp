#include <iostream>
#include "../include/crypto.h"


string xorEncryptDecrypt(const string& input, char key) {
    string output = input;
    for (size_t i = 0; i < input.size(); ++i)
        output[i] ^= key;
    return output;
}

string bruteForce(const string& input, char key) {
    string output = input;
    for (size_t i = 0; i < input.size(); ++i) {
        output[i] = input[i] ^ key;
    }
    return output;
}

// Проверка осмысленности текста
bool isValidText(const string& text) {
    for (char c : text) {
        if (c < 32 || c > 126) { 
            return false;
        }
    }
    return true;
}