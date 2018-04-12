# List
List is a data structure that provides a sequence access logic to its elements. Here we use the C++ `std::list`, which are implemented as doubly-linked lists, hence these structures provides constant time insertion and deletion of elements on its ends and along the structure, providing the appropriate iterator.

However, the memory allocation of these elements are not continuous. They reside scattered along the memory, but their order is preserved by the links inside each member, indicating the previous and next elements of the order.

Lists are very appropriate for inserting, extracting and moving elements along its container, thus they are great for sorting algorithms.

## Operations
- **push_front:** constant time
- **push_back:** constant time
- **pop_front:** constant time
- **pop_back:** constant time
- **insert:** constant time
- **erase:** constant time
- **operator[]:** constant time
- **Iteration over the structure:** linear
