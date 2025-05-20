#include <iostream>
#include "include/math.h"
#include "include/crypto.h"
#include "include/main.h"

using namespace std;

enum Choice {
    FASTMODPOW = 1,
    EXTENDEDGCD,
    FINDINVERSE,
    MITM,
    DIOPHANTEQUATION,
    BRUT,
    CONTINUEDFRCTN,
    FASTMODPOWFERM,
    XOR,
    EXIT,
};

void showMenu() {
    cout << "\n–––––––––––––––––– Главное меню ––––––––––––––––––" << endl;
    cout << "1. Быстрое возведение в степень по модулю" << endl;
    cout << "2. Расширенный алгоритм Евклида" << endl;
    cout << "3. Нахождение обратного элемента" << endl;
    cout << "4. Демонстрация  MiTM на Diffie-Hellman" << endl;
    cout << "5. Решение дефиантовых уравнений" << endl;
    cout << "6. Brut атака с перебором ключа для XOR " << endl;
    cout << "7. Разложение в цепную дробь двух чисел" << endl;
    cout << "8. Быстрое возведение в степень по модулю c проверкой на малую теорема ферма" << endl;
    cout << "9. Шифрование текста XOR с указанием ключа" << endl;
    cout << "10. Выход" << endl;
    cout << "Выберите задание: ";
    cout << "\n––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int userInput;

    do {
        showMenu();
        cin >> userInput;

        Choice choice = static_cast<Choice>(userInput);

        switch (choice) {
            case FASTMODPOW: 
                fastNumMod(); 
                break;
            case EXTENDEDGCD:  
                extendedGCD(); 
                break;
            case FINDINVERSE: 
                inverseNum(); 
                break;
            case MITM: 
                mitm(); 
                break;
            case DIOPHANTEQUATION: 
                Equation(); 
                break;
            case BRUT: 
                BrutAttack(); 
                break;
            case CONTINUEDFRCTN: 
                Frctn(); 
                break;
            case FASTMODPOWFERM: {
                long a, x, p;
                cout << "Input number format: a^x mod p" << endl;
                cout << "Input p: "; cin >> p;
                if (!isPrime(p)) {
                    cout << "p must be a prime number" << endl;
                    break;
                }
                cout << "Input a: "; cin >> a;
                cout << "Input x: "; cin >> x;
                cout << "Result: " << smartModPow(a, x, p) << endl;
                break;
            }
            case XOR: {
                string DecryptText, EncryptText;
                int key;
                cout << "Input text: " << endl;
                cin >> DecryptText;
                cout << "Input key: " << endl;
                cin >> key;
                EncryptText = xorEncryptDecrypt(DecryptText, key); // Предполагая, что функция называется xorEncrypt
                cout << "Зашифрованный текст: " << EncryptText << endl;      
                break;
            }
            case EXIT: 
                cout << "Выход" << endl; 
                break;
            default:
                cout << "Ошибка" << endl;
        }

    } while (userInput != 10);

    return 0;
}