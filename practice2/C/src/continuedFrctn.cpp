#include <iostream>
#include "../include/math.h"
#include "../include/crypto.h"

using namespace std;

int Frctn() {
    long num1, num2, answer;
    cout << "Введите диофантовое уравнение вида a*num1 + b*num2 = answer" << endl;
    cout << "Input a:: ";
    cin >> num1;
    cout << "Input b: ";
    cin >> num2;
    cout << "Input c:";
    cin >> answer;

    // Вектор для хранения разложения в виде цепной дроби
    vector<long> result;

    // Получаем разложение в виде цепной дроби для num1 и num2
    continuedFrctn(num1, num2, result);

    cout << "Цепная дробь для " << num1 << " и " << num2 << ": ";
    for (long r : result) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
