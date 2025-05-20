#include <iostream>
#include "../include/math.h"
#include "../include/crypto.h"

using namespace std;

int BrutAttack() {
    string encrypted; 
    cout << "Input text: ";
    getline(cin, encrypted);


    cout << "\nЗапуск brute-force для расшифровки текста...\n" << endl;
    
    for (unsigned char key = 0; key < 255; key++) {
        string decryptedText = bruteForce(encrypted, key);
        
        if (isValidText(decryptedText)) {
            cout << "Возможный расшифрованный текст (с ключом " << (int)key << "): " << decryptedText << endl;
        }
    }

    return 0;
}
