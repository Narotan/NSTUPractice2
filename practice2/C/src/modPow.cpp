#include <iostream>
#include "../include/math.h"
#include "../include/crypto.h"
using namespace std;

int fastNumMod() {
    long a, x, p;
    cout << "Input number format: a^x mod p" << endl;
    cout << "Input p: "; cin >> p;
    if (!isPrime(p)) {
        cout << "p must be a prime number" << endl;
        return 1;
    }
    cout << "Input a: "; cin >> a;
    cout << "Input x: "; cin >> x;
    cout << "Result: " << modPow(a, x, p) << endl;
    return 0;
}