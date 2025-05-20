#include "../include/math.h"
#include "../include/crypto.h"
#include <iostream>
#include <set>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

// проверка на простое число 
bool isPrime(long num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0) return false;
    return true;
}

// быстрое возведение в степень 
long modPow(long a, long x, long p) {
    long result = 1;
    a %= p;
    while (x > 0) {
        if (x % 2 == 1)
            result = (result * a) % p;
        a = (a * a) % p;
        x /= 2;
    }
    return result;
}

// возведение в степень с проверкой малой теоремы ферма 
int smartModPow(long a, long x, long p) {
    if (!isPrime(p) || a % p == 0) {
        cout << "Малая теорема Ферма была применена" << endl;
        return modPow(a, x, p);
    } else {
        int reducedPower = x % (p - 1);
        return modPow(a, reducedPower, p);
    }
}

// расширенный алгоритм Евклида с решением 
tuple<int, int, int> extended_gcd(int a, int b) {
    tuple<int, int, int> x = {a, 1, 0};  
    tuple<int, int, int> y = {b, 0, 1};
    tuple<int, int, int> t = {0, 0 ,0};

    cout << "q\tОстаток r\tКоэффициенты (x, y)\n";

    int step = 0;
    while (get<0>(y) != 0) {
        int q = get<0>(x) / get<0>(y);
        t = {
            get<0>(x) - q * get<0>(y),
            get<1>(x) - q * get<1>(y),
            get<2>(x) - q * get<2>(y)
        };

        cout << q << "\t" << get<0>(y)
             << "\t\t(" << get<1>(y) << ", " << get<2>(y) << ")"<< endl;

        x = y;
        y = t;
    }

    cout << "-\t" << get<0>(x)
         << "\t\t(" << get<1>(x) << ", " << get<2>(x) << ")"<< endl;
    cout << "==============================================" << endl;

    return x;
}

// нахождение обратного по модулю 
int findInverse(int a, int p) {
    int x1 = p, x2 = 0, y1 = a, y2 = 1;

    while (y1 != 0) {
        int q = x1 / y1;
        int t1 = x1 - q * y1;
        int t2 = x2 - q * y2;
        x1 = y1;
        x2 = y2;

        y1 = t1;
        y2 = t2;
    }

    if (x1 != 1) {
        cout << "Обратного элемента не существует" << endl;
        return -1;
    } else {
        return (x2 % p + p) % p;
    }
}

// проверка на первообразный корень (типо чекаем что у нас из a^k составится множество до (а-1))
bool isPrimitiveRoot(long g, long p) {
    set<int> check;
    for (int i = 1; i < p; ++i) {
        int val = modPow(g, i, p);
        if (check.count(val)) return false;
        check.insert(val);
    }
    return true;
}

// Разложение в виде цепной дроби
void continuedFrctn(long p, long q, vector<long>& res) {
    while (q != 0) {
        res.push_back(p / q);  // Получаем очередной элемент цепной дроби
        p = p % q;  // Получаем остаток
        swap(p, q); // Меняем p и q местами
    }
}
