// ListNode.cpp
// Author: Fangtong Wang
// Date: 2024-11-16

#ifndef LIST_NODE_CPP
#define LIST_NODE_CPP

#include "ListNode.hpp"

// Constructor: Initializes the node with a given value and sets the next pointer to nullptr.
template <typename T>
Node<T>::Node(const T& val) : val(val), next(nullptr)
{
}

// Default constructor: Initializes the node with a default value of type T and sets the next pointer to nullptr.
template <typename T>
Node<T>::Node() : val(T()), next(nullptr) {}

#endif
