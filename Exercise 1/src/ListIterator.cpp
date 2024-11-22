// ListIterator.cpp
// Author: Fangtong Wang
// Date: 2024-11-16

#ifndef LIST_ITERATOR_CPP
#define LIST_ITERATOR_CPP

#include "ListIterator.hpp"
#include <stdexcept>

template <typename T>
ListIterator<T>::ListIterator(Node<T>* start_node) : current_node(start_node)
{
}

template <typename T>
ListIterator<T>::~ListIterator() 
{
}

template <typename T>
T ListIterator<T>::operator*() const
{
    return current_node->val;
}

template <typename T>
bool ListIterator<T>::operator == (const ListIterator& iterator) 
{
    return current_node == iterator.current_node;
}

template <typename T>
bool ListIterator<T>::operator != (const ListIterator& iterator) 
{
    return current_node != iterator.current_node;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator=(const ListIterator& other)
{
    if (this != &other){
        current_node = other.current_node;
    }
    return *this;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator ++ ()
{
    if (current_node) {
        current_node = current_node->next;
    }
    return *this;
}

template <typename T>
ListIterator<T> ListIterator<T>::operator ++ (int)
{
    ListIterator iterator = *this;
    ++*this;
    return iterator;

}

template <typename T>
bool ListIterator<T>::HasNext() const{
    return current_node != nullptr && current_node->next != nullptr;
}

template <typename T>
T& ListIterator<T>::Next() {
    if (!current_node) {
        throw std::out_of_range("No more elements to iterate over");
    }

    T& value = current_node->val;  
    current_node = current_node->next;  
    return value;
}

#endif