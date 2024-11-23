// ListIterator.cpp
// Date: 2024-11-16

#ifndef LIST_ITERATOR_CPP
#define LIST_ITERATOR_CPP

#include "ListIterator.hpp"
#include <stdexcept>

// Constructor: Initializes the iterator with the starting node.
template <typename T>
ListIterator<T>::ListIterator(Node<T>* start_node) : current_node(start_node)
{
}

// Destructor: No dynamic resources to release.
template <typename T>
ListIterator<T>::~ListIterator() 
{
}

// Dereference operator: Returns the value of the current node.
template <typename T>
T ListIterator<T>::operator*() const
{
    return current_node->val;
}

// Equality operator: Checks if two iterators point to the same node.
template <typename T>
bool ListIterator<T>::operator == (const ListIterator& iterator) 
{
    return current_node == iterator.current_node;
}

// Inequality operator: Checks if two iterators point to different nodes.
template <typename T>
bool ListIterator<T>::operator != (const ListIterator& iterator) 
{
    return current_node != iterator.current_node;
}

// Assignment operator: Updates the iterator to point to the same node as the other iterator.
template <typename T>
ListIterator<T>& ListIterator<T>::operator=(const ListIterator& other)
{
    if (this != &other) {
        current_node = other.current_node;
    }
    return *this;
}

// Prefix increment: Moves to the next node and returns the updated iterator.
template <typename T>
ListIterator<T>& ListIterator<T>::operator++()
{
    if (current_node) {
        current_node = current_node->next;
    }
    return *this;
}

// Postfix increment: Moves to the next node but returns the iterator before the increment.
template <typename T>
ListIterator<T> ListIterator<T>::operator++(int)
{
    ListIterator iterator = *this;
    ++*this;
    return iterator;
}

// Checks if the current node has a next node.
template <typename T>
bool ListIterator<T>::HasNext() const
{
    return current_node != nullptr && current_node->next != nullptr;
}

// Advances to the next node and returns the value of the current node.
template <typename T>
T& ListIterator<T>::Next() 
{
    if (!current_node) {
        throw std::out_of_range("No more elements to iterate over");
    }

    T& value = current_node->val;  // Store the current node's value.
    current_node = current_node->next;  // Move to the next node.
    return value;
}

#endif
