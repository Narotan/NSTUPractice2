package main

import (
	"fmt"
	"math"
)

// Функция для проверки, является ли число простым
func isPrime(modul int) bool {
	if modul <= 1 {
		return false
	}

	// Проверка делителей от 2 до квадратного корня из числа
	for i := 2; i <= int(math.Sqrt(float64(modul))); i++ {
		if modul%i == 0 {
			return false
		}
	}
	return true
}

// Функция для быстрого возведения в степень по модулю
func modPow(a, x, p int) int {
	result := 1
	a = a % p

	for x > 0 {
		if x%2 == 1 {
			result = (result * a) % p
		}
		a = (a * a) % p
		x = x / 2
	}
	return result
}

// Вычисление a^x mod p по малой теореме Ферма (если условия соблюдены)
func smartModPow(a, x, p int) int {
	if !isPrime(p) || a%p == 0 {
		return modPow(a, x, p)
	}
	reducedPower := x % (p - 1) // применяем теорему Ферма
	return modPow(a, reducedPower, p)
}

func main() {
	var a, x, p int
	fmt.Println("Input number format: a^x mod p")

	// Ввод значения p
	fmt.Print("Input p: ")
	fmt.Scan(&p)

	// Проверка, что p — простое число
	if !isPrime(p) {
		fmt.Println("p must be a prime number!")
		return
	}

	// Ввод значений a и x
	fmt.Print("Input a: ")
	fmt.Scan(&a)
	fmt.Print("Input x: ")
	fmt.Scan(&x)

	fmt.Println(smartModPow(a, x, p))
}
