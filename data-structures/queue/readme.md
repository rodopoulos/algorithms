# Queue
Queue is a sequence data structure that follows the First In, First Out (FIFO) principle, hence the first element that is inserted in a queue must be the first to come out. In other words, the element enters at one end and exit through the other one.

The simpler implementation of a queue resembles a stack logic, but following the FIFO directive. Thus, elements are scattered in the memory, but their order is preserved with the pointers along them.

### Operations
Concerning the implementation described above, we have the following costs:

- **push:** constant
- **pop:** linear
- **front:** constant
- **back:** linear
- **Iterate over structure:** linear

## C++ Queue
The C++ implementation of queues are way different. Normally, they use a structure called **deque**, which is basically a vector with constant time insertion at the beginning, as well. You can also indicate the container to implement the structure with `std::list`, but `std::deque` is the default.

With this structure, the complexities of operations change:

- **push:** constant
- **pop:** constant
- **front:** constant
- **back:** constant
- **Iterate over structure:** linear
