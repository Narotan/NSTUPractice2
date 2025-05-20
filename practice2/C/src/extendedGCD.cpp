#include <iostream>
#include "../include/math.h"
#include "../include/crypto.h"

using namespace std;

// расширенный алгоритм евклида 
int extendedGCD() {
    int num1, num2;
    cout << "Input first number: "; cin >> num1;
    cout << "Input second number: "; cin >> num2;
    auto [gcd, u, v] = extended_gcd(num1, num2);
    cout << "GCD: " << gcd << ", u: " << u << ", v: " << v << endl;

    // runTests();

    return 0;
}