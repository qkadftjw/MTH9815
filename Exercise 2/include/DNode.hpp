// DNode.hpp
// Date: 2024-11-16

#ifndef DNODE_HPP
#define DNODE_HPP

#include <memory> 

template <typename T>
class DNode 
{
public:
    T val;
    DNode* prev;
    DNode* next;

    DNode(const T& val);
    DNode();  

};

// Implement
template <typename T>
DNode<T>::DNode(const T& val) : val(val), prev(nullptr), next(nullptr)
{
}

template <typename T>
DNode<T>::DNode() : val(T()), next(nullptr) 
{
}

#endif