#include <iostream>
#include "../include/math.h"
#include "../include/crypto.h"

using namespace std;

int Equation() {
    long num1, num2, answer;
    cout << "Введите диофантовое уравнение вида a*num1 + b*num2 = answer\n";
    cout << "Input a: ";
    cin >> num1;
    cout << "Input b:";
    cin >> num2;
    cout << "Input c: ";
    cin >> answer;

    auto result = extended_gcd(num1, num2);
    long nod = get<0>(result);

    cout << "\nНОД(" << num1 << ", " << num2 << ") = " << nod << endl;

    if (answer % nod != 0) {
        cout << "Поскольку " << answer << " не делится на НОД " << nod << ", решений нет.\n";
        return -1;
    }
    
    long x0 = get<1>(result) * (answer / nod);
    long y0 = get<2>(result) * (answer / nod);

    cout << "Частное решение уравнения:\n";
    cout << num1 << " * (" << x0 << ") + " << num2 << " * (" << y0 << ") = " << answer << endl;

    return 0;
}
