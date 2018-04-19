package main

import "fmt"
import "math"

func decide(w int) string {
	if math.Mod(float64(w), 2.0) == 0 && w != 2 {
		return "YES"
	}

	return "NO"
}

func main() {
	var w int
	fmt.Scanf("%d", &w)

	response := decide(w)

	fmt.Print(response)
}
