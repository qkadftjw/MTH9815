// ListIterator.hpp
// Author: Fangtong Wang
// Date: 2024-11-16

#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

#include "ListNode.hpp"

template<typename T>
class ListIterator{

private:
    Node<T>* current_node;

public:
    explicit ListIterator(Node<T>* start_node);
    virtual ~ListIterator();

    T operator*() const;

    bool operator == (const ListIterator& iterator);
    bool operator != (const ListIterator& iterator);
    
    ListIterator<T>& operator=(const ListIterator& other);
    ListIterator<T>& operator++();
    ListIterator<T> operator++(int);

    bool HasNext() const;
    T& Next();
};

#ifndef LIST_ITERATOR_CPP
#include "ListIterator.cpp"
#endif

#endif