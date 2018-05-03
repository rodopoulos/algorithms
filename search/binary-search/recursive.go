package main

import "fmt"

func binarysearch(v []int, key, l, r int) int {
  half := (l + r) / 2
  fmt.Println(l, half, r)
  if v[half] == key  {
    return half
  }

  if (l >= r) {
    return -1
  } else if v[half] < key {
    return binarysearch(v, key, half + 1, r)
  } else { // v[half] < key
    return binarysearch(v, key, l, half - 1)
  }
}

func main() {
  v := [10]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

  var key int
  fmt.Printf("Select from 1 to 10: ")
  fmt.Scanf("%d", &key)

  pos := binarysearch(v[:], key, 0, len(v) - 1)

  if pos < 0 {
    fmt.Println("Number is not in array")
  } else {
    fmt.Printf("%d is in position %d.", key, pos + 1)
  }
}
