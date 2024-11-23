// ListIterator.hpp
// Author: Fangtong Wang
// Date: 2024-11-16

#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

#include "ListNode.hpp"

// Template for List Iterator to traverse a linked list.
template<typename T>
class ListIterator {

private:
    Node<T>* current_node; // Pointer to the current node.

public:
    explicit ListIterator(Node<T>* start_node); // Initialize with start node.
    virtual ~ListIterator(); // Destructor.

    T operator*() const; // Access current node's value.

    bool operator == (const ListIterator& iterator); // Compare equality.
    bool operator != (const ListIterator& iterator); // Compare inequality.

    ListIterator<T>& operator=(const ListIterator& other); // Assign another iterator.
    ListIterator<T>& operator++(); // Prefix increment to next node.
    ListIterator<T> operator++(int); // Postfix increment to next node.

    bool HasNext() const; // Check if more nodes exist.
    T& Next(); // Move to next node and return its value.
};

// Include implementation if needed.
#ifndef LIST_ITERATOR_CPP
#include "ListIterator.cpp"
#endif

#endif
