// ListNode.hpp
// Author: Fangtong Wang
// Date: 2024-11-16

#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node 
{
public:
    T val;
    Node* next;

    Node(const T& val);
    Node();  

};

#ifndef LIST_NODE_CPP
#include "ListNode.cpp"
#endif

#endif