// ListIterator.hpp
// Date: 2024-11-16

#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

#include "DNode.hpp"
#include <stdexcept>

// Template for a bidirectional list iterator for doubly linked list nodes.
template<typename T>
class ListIterator {

private:
    DNode<T>* current_node; // Pointer to the current node.

public:
    ListIterator(); // Default constructor.
    explicit ListIterator(DNode<T>* start_node); // Constructor with starting node.
    virtual ~ListIterator(); // Destructor.

    T operator*() const; // Access current node's value.

    bool operator == (const ListIterator& iterator); // Compare equality.
    bool operator != (const ListIterator& iterator); // Compare inequality.

    ListIterator<T>& operator=(const ListIterator& other); // Assign another iterator.
    ListIterator<T>& operator++(); // Prefix increment: move to the next node.
    ListIterator<T> operator++(int); // Postfix increment: move to next, return old iterator.
    ListIterator<T>& operator--(); // Prefix decrement: move to the previous node.
    ListIterator<T> operator--(int); // Postfix decrement: move to previous, return old iterator.

    bool HasNext() const; // Check if a next node exists.
    T& Next(); // Move to the next node and return its value.

    bool HasPrev() const; // Check if a previous node exists.
    T& Prev(); // Move to the previous node and return its value.
};

// Default constructor: Initializes with no current node.
template <typename T>
ListIterator<T>::ListIterator()
{
}

// Constructor: Initializes with the given starting node.
template <typename T>
ListIterator<T>::ListIterator(DNode<T>* start_node) : current_node(start_node)
{
}

// Destructor: No resources to free.
template <typename T>
ListIterator<T>::~ListIterator() 
{
}

// Dereference operator: Returns the value of the current node.
template <typename T>
T ListIterator<T>::operator*() const
{
    if (!current_node) {
        throw std::out_of_range("Cannot dereference a null iterator.");
    }
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

// Assignment operator: Copies the state of another iterator.
template <typename T>
ListIterator<T>& ListIterator<T>::operator=(const ListIterator& other)
{
    if (this != &other) {
        current_node = other.current_node;
    }
    return *this;
}

// Prefix increment: Move to the next node.
template <typename T>
ListIterator<T>& ListIterator<T>::operator++()
{
    if (current_node && current_node->next) {
        current_node = current_node->next;
    } else {
        throw std::out_of_range("Cannot increment iterator past the end.");
    }
    return *this;
}

// Postfix increment: Move to the next node and return the iterator's previous state.
template <typename T>
ListIterator<T> ListIterator<T>::operator++(int)
{
    ListIterator iterator = *this;
    ++*this;
    return iterator;
}

// Prefix decrement: Move to the previous node.
template <typename T>
ListIterator<T>& ListIterator<T>::operator--()
{
    if (current_node && current_node->prev) {
        current_node = current_node->prev;
    } else {
        throw std::out_of_range("Cannot decrement iterator past the beginning.");
    }
    return *this;
}

// Postfix decrement: Move to the previous node and return the iterator's previous state.
template <typename T>
ListIterator<T> ListIterator<T>::operator--(int)
{
    ListIterator iterator = *this;
    --*this;
    return iterator;
}

// Check if a next node exists.
template <typename T>
bool ListIterator<T>::HasNext() const
{
    return current_node != nullptr && current_node->next != nullptr;
}

// Move to the next node and return the value of the current node.
template <typename T>
T& ListIterator<T>::Next() 
{
    if (!current_node) {
        throw std::out_of_range("No more elements to iterate over");
    }

    T& value = current_node->val;
    current_node = current_node->next;
    return value;
}

// Check if a previous node exists.
template <typename T>
bool ListIterator<T>::HasPrev() const
{
    return current_node != nullptr && current_node->prev != nullptr;
}

// Move to the previous node and return the value of the current node.
template <typename T>
T& ListIterator<T>::Prev() 
{
    if (!current_node) {
        throw std::out_of_range("No more elements to iterate over");
    }

    T& value = current_node->val;
    current_node = current_node->prev;
    return value;
}

#endif
