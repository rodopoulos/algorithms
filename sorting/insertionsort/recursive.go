package main

import (
  "fmt"
  "time"
  "math/rand"
)

func makeArray(len int) []int {
  a := make([]int, len)
  rand.Seed(time.Now().UnixNano()) // really random, please

  for i, value := range rand.Perm(len) {
    a[i] = value
  }
  return a
}

func insertionSort(v []int, n int) {
	if n > 1 {
		insertionSort(v, n-1)
		key := v[n]
    i := n - 1
    for i >= 0 && v[i] > key{
      v[i+1] = v[i]
      i--
    }
    v[i+1] = key
	}
}

func main() {
	var l int
  fmt.Printf("Select array size: ")
  fmt.Scanf("%d", &l)

  v := makeArray(l)
  n := len(v) - 1
	fmt.Println(v)

	insertionSort(v[:], n)

	fmt.Println(v)
}
