#ifndef CRYPTO_H
#define CRYPTO_H

using namespace std;

// Шифрование/дешифрование XOR
string xorEncryptDecrypt(const string& input, char key);

// Перебор ключей 
string bruteForce(const std::string& input, char key);

// проверка текста на читаемость 
bool isValidText(const string& text);

// crypto.h
bool isPrimitiveRoot(long g, long p);

#endif