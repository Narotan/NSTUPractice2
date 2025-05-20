package main

import (
	"bufio"
	"fmt"
	"os"
)

func bruteForce(input string, key byte) string {
	output := make([]byte, len(input))
	for i := 0; i < len(input); i++ {
		output[i] = input[i] ^ key
	}
	return string(output)
}

// Проверка осмысленности текста
func isValidText(text string) bool {
	for _, c := range text {
		if c < 32 || c > 126 {
			return false
		}
	}
	return true
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Введите текст: ")
	encrypted, _ := reader.ReadString('\n')
	encrypted = encrypted[:len(encrypted)-1] // Удаляем символ новой строки

	fmt.Println("\nЗапуск brute-force атаки для расшифровки текста...\n")

	for key := 0; key < 255; key++ {
		decryptedText := bruteForce(encrypted, byte(key))

		if isValidText(decryptedText) {
			fmt.Print("Возможный расшифрованный текст (с ключом ")
			fmt.Print(key)
			fmt.Print("): ")
			fmt.Println(decryptedText)
		}
	}
}
