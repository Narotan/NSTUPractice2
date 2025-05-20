package main

import "fmt"

// Задание 2. Реализовать алгоритм Евклида для вычисления с*d
// mod m=1 (через u и v).

// Функция расширенного алгоритма Евклида
func extendedGcd(a, b int) (int, int, int) {
	x := [3]int{a, 1, 0}
	y := [3]int{b, 0, 1}
	t := [3]int{0, 0, 0}

	for y[0] != 0 {
		q := x[0] / y[0]
		t = [3]int{x[0] - q*y[0], x[1] - q*y[1], x[2] - q*y[2]}
		x = y
		y = t
	}

	return x[0], x[1], x[2]
}

func main() {
	var num1, num2 int
	fmt.Println("Input first number: ")
	fmt.Scan(&num1)
	fmt.Println("Input second number: ")
	fmt.Scan(&num2)

	gcd, x, y := extendedGcd(num1, num2)

	fmt.Println(gcd, x, y)
}
