// ListNode.hpp
// Date: 2024-11-16

#ifndef NODE_HPP
#define NODE_HPP

// Template for a Node in a singly linked list.
template <typename T>
class Node 
{
public:
    T val;        // Node value.
    Node* next;   // Pointer to the next node.

    Node(const T& val); // Constructor with value.
    Node();             // Default constructor.
};

// Include implementation if needed.
#ifndef LIST_NODE_CPP
#include "ListNode.cpp"
#endif

#endif
