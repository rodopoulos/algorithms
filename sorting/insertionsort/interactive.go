package main

import (
  "fmt"
  "time"
  "math/rand"
)

func makeArray(len int) []int {
  a := make([]int, len)
  rand.Seed(time.Now().UnixNano())

  for i, value := range rand.Perm(len) {
    a[i] = value
  }
  return a
}

func main() {
  var l int
  fmt.Printf("Select array size: ")
  fmt.Scanf("%d", &l)
  v := makeArray(l)
  fmt.Println(v)

  for j := 1; j < len(v); j++ {
    key := v[j]
    i := j - 1

    for i >= 0 && key < v[i] {
      v[i + 1] = v[i]
      i--
    }
    v[i+1] = key
  }

  fmt.Println(v)
}
