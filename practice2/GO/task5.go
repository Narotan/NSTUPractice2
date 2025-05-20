package main

import "fmt"

func continuedFraction(p, q int, res *[]int) {
	if q == 0 {
		return
	}
	*res = append(*res, p/q)
	continuedFraction(q, p%q, res)
}

func extendedGCD(a, b int) (int, int, int) {
	x := [3]int{a, 1, 0}
	y := [3]int{b, 0, 1}
	var t [3]int

	for y[0] != 0 {
		q := x[0] / y[0]
		t = [3]int{x[0] - q*y[0], x[1] - q*y[1], x[2] - q*y[2]}
		x = y
		y = t
	}

	return x[0], x[1], x[2]
}

func main() {
	var num1, num2, answer int

	fmt.Println("Введите диофантовое уравнение вида a*num1 + b*num2 = answer")
	fmt.Println("Введите первое число: ")
	fmt.Scan(&num1)
	fmt.Println("Введите второе число: ")
	fmt.Scan(&num2)
	fmt.Println("Введите ответ: ")
	fmt.Scan(&answer)

	gcd, a, b := extendedGCD(num1, num2)

	fmt.Println("НОД для:", num1, "и", num2, ":", gcd)
	if answer%gcd == 0 {
		fmt.Println(answer, "%", gcd, "=", gcd%answer, "-> решение есть")
	} else {
		fmt.Println(answer, "%", gcd, "!= 0 -> решения нет")
		return
	}

	fmt.Println("множитель а:", a)
	fmt.Println("множитель b:", b)

	fmt.Printf("%d*(%d) + %d*(%d) = %d\n", num1, a*(answer/gcd), num2, b*(answer/gcd), answer)
}
