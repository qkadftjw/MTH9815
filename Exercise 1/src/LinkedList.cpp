// LinkedList.cpp
// Author: Fangtong Wang
// Date: 2024-11-16

#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include "LinkedList.hpp"
#include <stdexcept>
#include <iostream>

// Constructor
template<typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), length(0)
{
}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* current = head;
    while (current)
    {
        Node<T>* next_node = current->next;
        delete current;
        current = next_node;
    }
}

// Add the specified element at the end of the list
template<typename T>
void LinkedList<T>::Add(const T& value)
{
    Node<T>* new_node = new Node<T>(value);
    if (!tail){
        head = tail = new_node;
    }
    else{
        tail->next = new_node;
        tail = new_node;
    }
    ++length;
}


// Add the specified element at the specified index
template <typename T>
void LinkedList<T>::Insert(const T& value, int index)
{
    if (index < 0 || index > length){
        throw std::out_of_range("Index out of range");
    }

    Node<T>* new_node = new Node<T>(value);

    if (index == 0){
        new_node->next = head;
        head = new_node;
        if (!tail) {
            tail = new_node;
        }
    }

    else{
        Node<T>* current = head;
        for (int i = 0; i < index-1; ++i){
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        if (new_node->next == nullptr){
            tail = new_node;
        }
    }

    ++length;
}


// Get the element at the specified index
template <typename T>
T& LinkedList<T>::Get(int index) const{
    if (index < 0 || index >= length)
    {
        throw std::out_of_range("Index out of range");
    }
        
    Node<T>* current = head;

    for (int i = 0; i < index; ++i){
        current = current->next;
    }

    return current->val;
}

// Retrieve the index of the specified element (-1 if it does not exist in the list
template <typename T>
int LinkedList<T>::IndexOf(const T& value) const
{
    Node<T>* current = head;
    int index = 0;
    while (current){
        if (current->val == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

// Remove the element at the specified index and return it
template <typename T>
T LinkedList<T>::Remove(int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }

    Node<T>* removed_node;

    if (index == 0) {
        removed_node = head;
        T removed_val = removed_node->val;  
        head = head->next;
        if (!head) {
            tail = nullptr;  
        }
        delete removed_node;  
        --length;
        return removed_val;
    } else {
        Node<T>* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }

        removed_node = current->next;
        T removed_val = removed_node->val;  
        current->next = removed_node->next;

        if (!current->next) {
            tail = current;  
        }

        delete removed_node;  
        --length;
        return removed_val;
    }
}

// Return an iterator on this list
template <typename T>
ListIterator<T> LinkedList<T>::Iterator() const {
    return ListIterator<T>(head);
}

// Return the size of the list
template <typename T>
int LinkedList<T>::Size() const{
    return length;
}

template  <typename T>
void LinkedList<T>::Print() const{
    auto current = head;
    while (current){
        std::cout << current->val << ", ";
        current = current->next;
    }
}

#endif