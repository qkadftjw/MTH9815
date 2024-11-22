// ListNode.cpp
// Author: Fangtong Wang
// Date: 2024-11-16

#ifndef LIST_NODE_CPP
#define LIST_NODE_CPP

#include "ListNode.hpp"

template <typename T>
Node<T>::Node(const T& val) : val(val), next(nullptr)
{
}

template <typename T>
Node<T>::Node() : val(T()), next(nullptr) {}

#endif