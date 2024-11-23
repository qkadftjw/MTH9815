// DNode.hpp
// Date: 2024-11-16

#ifndef DNODE_HPP
#define DNODE_HPP

#include <memory> 

// Template class for a doubly linked list node.
template <typename T>
class DNode 
{
public:
    T val;         // Value stored in the node.
    DNode* prev;   // Pointer to the previous node.
    DNode* next;   // Pointer to the next node.

    DNode(const T& val); // Constructor: Initializes the node with a value.
    DNode();             // Default constructor: Initializes with default value.
};

// Constructor: Initializes the node with a given value and sets pointers to nullptr.
template <typename T>
DNode<T>::DNode(const T& val) : val(val), prev(nullptr), next(nullptr)
{
}

// Default constructor: Initializes with a default value and sets pointers to nullptr.
template <typename T>
DNode<T>::DNode() : val(T()), prev(nullptr), next(nullptr)
{
}

#endif
