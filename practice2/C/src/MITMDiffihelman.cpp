#include <iostream>
#include "../include/math.h"
#include "../include/crypto.h"

using namespace std;


int mitm() {
    long publicKey,generator;
    cout << "Введите публичное значение p(простое число): ";
    cin >> publicKey; // публичные значения
    cin.ignore();

    if (!isPrime(publicKey)) {
        cout << "p must be a prime number" << endl;
        return 1;
    }
    
    // Ищем generator под publicKey 
    for (int g = 1; g < publicKey; g++) {
        if (isPrimitiveRoot(g, publicKey)) {
            generator = g;
            break;
        }
    }

    cout << "\n" << "Public key p: " << publicKey << "\n"<<"Public key g: " << generator  << endl;

    int privateKeyA  = rand() % 101;
    int privateKeyB = rand() % 101;

    int privateKeyEVAA = rand() % 101;
    int privateKeyEVAB = rand() % 101;

    // Алиса вычисляет и отправляет бобу
    long A = modPow(generator, privateKeyA, publicKey);
    
    // ЕВА перехватывает A и подменяет на A' = g^m1
    long fakeA = modPow(generator, privateKeyEVAA, publicKey);

    // БОБ вычисляет и отправляет Алисе
    long B = modPow(generator, privateKeyB, publicKey);

    // перехватывает B и подменяет на B' = g^m2
    long fakeB = modPow(generator, privateKeyEVAB, publicKey);

    // Алиса вычисляет общий ключ 
    long secretAlice = modPow(fakeA, privateKeyA, publicKey);

    // БОБ вычисляет общий ключ 
    long secretBob = modPow(fakeB, privateKeyB, publicKey);

    
    long secretEVAFromAlice = modPow(A, privateKeyEVAA, publicKey);
    long secretEVAFromBob = modPow(B, privateKeyEVAB, publicKey);
    

    // if (secretAlice == secretBob) {
    //     cout << "\n" << "Key is equal! " << secretAlice << endl;
    // } else {
    //     cout << "\n" << "key is not equal!" << endl;
    //     return -1;
    // }

    // получаем ключ для шифрования 
    char key = secretAlice % 256;
    
    ifstream file("/Users/danil/proga/practice2/C/data/input.txt");
    string text;

    getline(file, text, '\0');
    file.close();

    cout << "\nАлиса считывает сообщение из файла: ";
    cout << text << endl;
    
    // Алиса шифрует сообщение
    char keyAlice = secretAlice % 256;

    string encrypted = xorEncryptDecrypt(text, keyAlice);
    ofstream outFile("/Users/danil/proga/practice2/C/data/encrypted.txt");  
    outFile << encrypted;
    outFile.close();
    cout << "Зашифрованный текст записан в файл encrypted.txt" << endl;

    
    // Ева перехватывает и расшифровывает
    char keyEVA1 = secretEVAFromAlice % 256;
    string intercepted = xorEncryptDecrypt(encrypted, keyEVA1);
    cout << "Ева перехватила сообщение: " << intercepted << endl;
    
    // Ева может изменить сообщение
    intercepted = "Привет боб";
    cout << "Ева заменила сообщение на: " << intercepted << endl;
    
    // Ева перешифровывает с ключом к Бобу
    char keyEVA2 = secretEVAFromBob % 256;
    string reEncrypted = xorEncryptDecrypt(intercepted, keyEVA2);
    cout << "Ева зашифровала сообщение обратно: " << reEncrypted << endl;
    
    // Боб получает и расшифровывает
    char keyBob = secretBob % 256;
    string decryptedByBob = xorEncryptDecrypt(reEncrypted, keyBob);
    cout << "Боб получил сообщение: " << decryptedByBob << endl;


    return 0;
}
