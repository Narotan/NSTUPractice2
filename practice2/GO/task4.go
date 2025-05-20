package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"strings"
	"time"
)

// Проверка на простое число
func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

// Возведение в степень по модулю
func modPow(base, exp, mod int) int {
	result := 1
	base = base % mod
	for exp > 0 {
		if exp%2 == 1 {
			result = (result * base) % mod
		}
		exp = exp >> 1
		base = (base * base) % mod
	}
	return result
}

// Проверка на первообразный корень
func isPrimitiveRoot(g, p int) bool {
	used := make(map[int]bool)
	var value int
	for i := 1; i < p; i++ {
		value = modPow(g, i, p)
		if used[value] {
			return false
		}
		used[value] = true
	}
	return true
}

// XOR-шифрование/дешифрование
func xorEncryptDecrypt(text string, key byte) string {
	result := make([]byte, len(text))
	for i := 0; i < len(text); i++ {
		result[i] = text[i] ^ key
	}
	return string(result)
}

func main() {
	rand.Seed(time.Now().UnixNano())
	reader := bufio.NewReader(os.Stdin)

	fmt.Print("Введите публичное значение p (простое число): ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	publicKey, _ := strconv.Atoi(input)

	if !isPrime(publicKey) {
		fmt.Println("p must be a prime number!")
		return
	}

	// Находим генератор
	var generator int
	for g := 1; g < publicKey; g++ {
		if isPrimitiveRoot(g, publicKey) {
			generator = g
			break
		}
	}

	fmt.Printf("\nPublic key p: %d\nPublic key g: %d\n", publicKey, generator)

	privateKeyA := rand.Intn(101)
	privateKeyB := rand.Intn(101)
	privateKeyEVAA := rand.Intn(101)
	privateKeyEVAB := rand.Intn(101)

	A := modPow(generator, privateKeyA, publicKey)
	fakeA := modPow(generator, privateKeyEVAA, publicKey)
	B := modPow(generator, privateKeyB, publicKey)
	fakeB := modPow(generator, privateKeyEVAB, publicKey)

	secretAlice := modPow(fakeA, privateKeyA, publicKey)
	secretBob := modPow(fakeB, privateKeyB, publicKey)

	secretEVAFromAlice := modPow(A, privateKeyEVAA, publicKey)
	secretEVAFromBob := modPow(B, privateKeyEVAB, publicKey)

	key := byte(secretAlice % 256)

	fmt.Print("\nАлиса вводит сообщение: ")
	text, _ := reader.ReadString('\n')
	text = strings.TrimSpace(text)

	encrypted := xorEncryptDecrypt(text, key)
	fmt.Println("Зашифрованный текст (от Алисы):", encrypted)

	keyEVA1 := byte(secretEVAFromAlice % 256)
	intercepted := xorEncryptDecrypt(encrypted, keyEVA1)
	fmt.Println("Ева перехватила сообщение:", intercepted)

	intercepted = "Привет боб"
	fmt.Println("Ева заменила сообщение на:", intercepted)

	keyEVA2 := byte(secretEVAFromBob % 256)
	reEncrypted := xorEncryptDecrypt(intercepted, keyEVA2)
	fmt.Println("Ева зашифровала сообщение обратно:", reEncrypted)

	keyBob := byte(secretBob % 256)
	decryptedByBob := xorEncryptDecrypt(reEncrypted, keyBob)
	fmt.Println("Боб получил сообщение:", decryptedByBob)
}
