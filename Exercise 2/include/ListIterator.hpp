// ListIterator.hpp
// Date: 2024-11-16

#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

#include "DNode.hpp"
#include <stdexcept>

template<typename T>
class ListIterator{

private:
    DNode<T>* current_node;

public:
    ListIterator();
    explicit ListIterator(DNode<T>* start_node);
    virtual ~ListIterator();

    T operator*() const;

    bool operator == (const ListIterator& iterator);
    bool operator != (const ListIterator& iterator);

    ListIterator<T>& operator=(const ListIterator& other);
    ListIterator<T>& operator++();
    ListIterator<T> operator++(int);
    ListIterator<T>& operator--();
    ListIterator<T> operator--(int);

    bool HasNext() const;
    T& Next();

    bool HasPrev() const;
    T& Prev();
};

template <typename T>
ListIterator<T>::ListIterator()
{
}

template <typename T>
ListIterator<T>::ListIterator(DNode<T>* start_node) : current_node(start_node)
{
}

template <typename T>
ListIterator<T>::~ListIterator() 
{
}

template <typename T>
T ListIterator<T>::operator*() const
{
    if (!current_node) {
        throw std::out_of_range("Cannot dereference a null iterator.");
    }
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
    if (current_node && current_node->next) {
        current_node = current_node->next;
    } else {
        throw std::out_of_range("Cannot increment iterator past the end.");
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
ListIterator<T>& ListIterator<T>::operator -- ()
{
    if (current_node && current_node->prev) {
        current_node = current_node->prev;
    } else {
        throw std::out_of_range("Cannot decrement iterator past the beginning.");
    }
    return *this;
}

template <typename T>
ListIterator<T> ListIterator<T>::operator -- (int)
{
    ListIterator iterator = *this;
    --*this;
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

template <typename T>
bool ListIterator<T>::HasPrev() const{
    return current_node != nullptr && current_node->prev != nullptr;
}

template <typename T>
T& ListIterator<T>::Prev() {
    if (!current_node) {
        throw std::out_of_range("No more elements to iterate over");
    }

    T& value = current_node->val;  
    current_node = current_node->prev;  
    return value;
}

#endif