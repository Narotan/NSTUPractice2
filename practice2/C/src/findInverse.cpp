#include <iostream>
#include "../include/math.h"
#include "../include/crypto.h"

using namespace std;

void inverseNum() {
    long a, p;
    cout << "Input number format: a^-1 mod p" << endl;
    cout << "Input p: "; cin >> p;
    cout << "Input a: "; cin >> a;
    cout << findInverse(a, p) << endl;
}