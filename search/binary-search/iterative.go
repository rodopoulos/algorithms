package main

import "fmt"

func binarysearch(v []int, key int) (int, bool) {
  l := 0
  r := len(v) - 1

  for l <= r {
    half := (l + r) / 2

    if v[half] == key {
      return half, true
    } else if v[half] < key {
      l = half + 1
    } else {
      r = half - 1
    }
  }

  return -1, false

}

func main() {
  v := [10]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

  var key int
  fmt.Printf("Select from 1 to 10: ")
  fmt.Scanf("%d", &key)
  
  pos, res := binarysearch(v[:], key)

  if res {
    fmt.Printf("%d is in position %d.", key, pos + 1)
  } else {
    fmt.Println("Number is not in array")
  }
}
