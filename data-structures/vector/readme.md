# Vectors
Vectors are data structures that represent arrays which can change in size. In a naive approach, one would try to implement *vectors* as linked lists, providing linear dynamically sized structures. However, note that such method does not provide a contiguous chunk of memory, which would properly represent an array, but linked pieces of data scattered along the memory, resulting in a slower access time to a given element.

That said, vectors uses dynamic data allocation of contiguous portions of memory for data placement, as an array. As soon as this piece becomes insufficient, the vector container will be adapted to fit the new data. In summary, we can cite two main properties:

1. **Continuous placement:** providing a cheap way to directly access any elements over the vector, just like arrays, and relatively fast addition and removal of elements;
2. **Allocation awareness:** the container must dynamically adapt its size to handle the data it must hold.

### Reallocations

Observe that, for an initial constant sized vector, if we make `n` insertions of a single element which will need to reallocate the entire vector container, such operations will result in an `O(n²)` complexity. We justify this claim, stating that there would be `n` reallocations of `i` elements, where `i` is a range between the initial constant size of the vector and `n`.

Therefore, it is stated that a reallocation should double the size of the vector container, hence limiting the number of reallocations to `O(lg n)`.

## Operations

- **insert:**
- **erase:**
- **insert:**
