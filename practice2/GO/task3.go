// Задание 3. Реализовать алгоритм Евклида для вычисления
// взаимообратного числа с^-1 mod m=d.

package main

import (
	"fmt"
)

// нахождение обратного элеменьа
func findInverse(a int, p int) int {
	x1 := p
	x2 := 0
	y1 := a
	y2 := 1

	for y1 != 0 {
		q := x1 / y1
		t1 := x1 - q*y1
		t2 := x2 - q*y2

		x1 = y1
		x2 = y2

		y1 = t1
		y2 = t2
	}

	if x1 != 1 {
		return -1
	} else {
		return (x2%p + p) % p
	}
}

func main() {
	var a, p int
	fmt.Println("Input number format: a^-1 mod p")

	fmt.Print("Input p: ")
	fmt.Scan(&p)

	fmt.Print("Input a: ")
	fmt.Scan(&a)

	fmt.Println(findInverse(a, p))
}
