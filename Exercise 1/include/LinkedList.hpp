// LinkedList.hpp
// Author: Fangtong Wang
// Date: 2024-11-16

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "ListNode.hpp"
#include "ListIterator.hpp"

template <typename T>
class LinkedList
{
public:
    Node<T>* head;
    Node<T>* tail;
    int length = 0;

    LinkedList();
    virtual ~LinkedList();

    // Add the specified element at the end of the list
    void Add(const T& value);
    
    // Add the specified element at the specified index
    void Insert(const T& value, int index);

    // Get the element at the specified index
    T& Get(int index) const;

    // Retrieve the index of the specified element (-1 if it does not exist in the list
    int IndexOf(const T& value) const;

    // Remove the element at the specified index and return it
    T Remove(int index);

    // Return an iterator on this list
    ListIterator<T> Iterator() const;

    // Return the size of the list
    int Size() const;

    // Return whether there is another element to return in this iterator
    bool HasNext() const;

    // Return the next element in this iterator
    T& Next() const;

    // Function to print all the elements in the linked list.
    void Print() const;
};

#ifndef LINKED_LIST_CPP
#include "LinkedList.cpp"
#endif

#endif