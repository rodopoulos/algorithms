# Map
Maps are associative data structures, storing elements as key-value pairs, following a specific order. Therefore, the *key* values are used both to sort and uniquely identify **pairs**. That said, observe that a value can be mapped to many keys (*ex: m[1] = "hello"; m[2] = "hello"*). The initial sort order is based in a strict weak ordering.

Maps are generally implemented as *binary search trees (BST)*, but here, we'll extend the discussion to implementations using *self-balancing BSTs*, which will provide better complexities.

## As a BST
Using binary search trees, we have a simpler map implementation. Each map pair will correspond to a tree node, indexed by the key value only.

### Operations

## As a Treap
Treap (tree + heaps) is a data structure that combines BST and heaps and can be used in manner that behaves as a self-balancing BST. Here, each map pair will correspond to a treap node, indexed both by the key value and mapped value.

### Operations
