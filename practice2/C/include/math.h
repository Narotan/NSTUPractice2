#ifndef FUNC_H
#define FUNC_H

#include <tuple>
#include <string>
#include <set>
#include <cassert>
#include <fstream>
#include <cmath>

using namespace std;

// Проверка на простое число
bool isPrime(long num);

// Быстрое возведение в степень по модулю
long modPow(long a, long x, long p);

// быстрое возвдение в степень с проверкой по малой теореме ферма
int smartModPow(long a, long x, long p);

// Расширенный алгоритм Евклида 
tuple<int, int, int> extended_gcd(int a, int b);

// Поиск обратного элемента по модулю
int findInverse(int a, int p);

// Проверка на первообразный корень
bool isPrimitiveRoot(long g, long p);

//Цепные дроби 
void continuedFrctn(long p, long q, vector<long>& res);

#endif