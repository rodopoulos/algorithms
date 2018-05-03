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

func partition(a []int, l, r int) int {
  x := a[r]
  fmt.Println("oi")
  i := l - 1
  for j := l ; j < r-1; j++ {
    if a[j] <= x {
      i++
      // swap(a[i],a[j])
      a[i] = a[i] + a[j]
      a[j] = a[i] - a[j]
      a[i] = a[i] - a[j]
    }
  }
  // swap(a[i+1],a[r])
  a[i+1] = a[i+1] + a[r]
  a[r] = a[i+1] - a[r]
  a[i+1] = a[i+1] - a[r]

  return i + 1
}

func quicksort(a []int, l, r int) {
  if l < r {
    q := partition(a, l, r)
    quicksort(a, l, q-1)
    quicksort(a, q+1, r)
  }
}

func main() {
  var l int
  fmt.Printf("Select array size: ")
  fmt.Scanf("%d", &l)
  a := makeArray(l)
  fmt.Println(a)

  quicksort(a[:], 0, len(a)-1)

  fmt.Println(a)
}
