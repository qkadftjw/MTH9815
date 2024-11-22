// LinkedList.hpp
// Date: 2024-11-16

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "DNode.hpp"
#include "ListIterator.hpp"
#include <stdexcept>
#include <iostream>

template <typename T>
class DoublyLinkedList 
{
private:
    DNode<T>* head;
    DNode<T>* tail;
    int length = 0;

public:

    DoublyLinkedList ();
    virtual ~DoublyLinkedList ();

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

// Constructor
template<typename T>
DoublyLinkedList <T>::DoublyLinkedList() : head(nullptr), tail(nullptr), length(0)
{
}

// Destructor
template <typename T>
DoublyLinkedList <T>::~DoublyLinkedList()
{
    DNode<T>* current = head;
    while (current)
    {
        DNode<T>* next_node = current->next;
        delete current;
        current = next_node;
    }
}

// Add the specified element at the end of the list
template<typename T>
void DoublyLinkedList <T>::Add(const T& value)
{
    DNode<T>* new_node = new DNode<T>(value);
    if (!tail){
        head = tail = new_node;
    }
    else{
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    ++length;
}


// Add the specified element at the specified index
template <typename T>
void DoublyLinkedList <T>::Insert(const T& value, int index)
{
    if (index < 0 || index > length){
        throw std::out_of_range("Index out of range");
    }

    DNode<T>* new_node = new DNode<T>(value);

    if (index == 0){
        new_node->next = head;
        if (head) {
            head->prev = new_node;
        }
        head = new_node;
        if (!tail) {
            tail = new_node;
        }
    }
    else if (index == length) {
        new_node->next = nullptr;
        new_node->prev = tail;
        if (tail){
            tail->next = new_node;
        }
        tail = new_node;
        if (!head) {
            head = new_node;
        }
    }
    else{
        if (index <= length / 2) {
            DNode<T>* current = head;
            for (int i = 0; i < index-1; ++i) {
                current = current->next;
            }
            new_node->next = current->next;
            new_node->prev = current;
            current->next = new_node; 
            if (new_node->next == nullptr){
                tail = new_node;
            }
        }
        else {
            DNode<T>* current = tail;
            for (int i = length-1; i > index+1; --i) {
                current = current->prev;
            }
            new_node->prev = current->prev;
            new_node->next = current;
            current->prev = new_node;
            if (new_node->prev == nullptr){
                head = new_node;
            }
        }
    }
    ++length;
}


// Get the element at the specified index
template <typename T>
T& DoublyLinkedList <T>::Get(int index) const{
    if (index < 0 || index >= length)
    {
        throw std::out_of_range("Index out of range");
    }
    
    if (index <= length / 2) {
        DNode<T>* current = head;
        for (int i = 0; i < index; ++i){
            current = current->next;
        }

        return current->val;
    }
    else {
        DNode<T>* current = tail;
        for (int i = length - 1; i > index; --i){
            current = current->prev;
        }
        return current->val;
    }
}

// Retrieve the index of the specified element (-1 if it does not exist in the list
template <typename T>
int DoublyLinkedList <T>::IndexOf(const T& value) const
{
    DNode<T>* current = head;
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
T DoublyLinkedList <T>::Remove(int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }

    DNode<T>* removed_node;
    T removed_val;

    if (index == 0) {
        removed_node = head;
        removed_val = removed_node->val;  
        head = head->next;
        if (head){
            head->prev = nullptr;
        }
        else{
            tail = nullptr;
        }
    } 
    else if (index == length-1){
        removed_node = tail;
        removed_val = removed_node->val;
        tail = tail->prev;
        if (tail){
            tail->next = nullptr;
        }
        else{
            head = nullptr;
        }
    }
    else if (index <= length / 2) {
        DNode<T>* current = head;
        for (int i = 0; i < index-1; ++i){
            current = current->next;
        }

        removed_node = current->next;
        removed_val = removed_node->val;  

        current->next = removed_node->next;
        if (removed_node->next){
            removed_node->next->prev = current;
        }
        else {
            tail = current;
        }
    }
    else{
        DNode<T>* current = tail;
        for (int i = length-1; i > index + 1; --i){
            current = current->prev;
        }

        removed_node = current->prev;
        removed_val = removed_node->val;
        current->prev = removed_node->prev;

        if (removed_node->prev){
            removed_node->prev->next = current;
        }  
        else{
            head = current;
        }
    }

    delete removed_node;  
    --length;
    return removed_val;
}

// Return an iterator on this list
template <typename T>
ListIterator<T> DoublyLinkedList <T>::Iterator() const {
    return ListIterator<T>(head);
}

// Return the size of the list
template <typename T>
int DoublyLinkedList <T>::Size() const{
    return length;
}

template  <typename T>
void DoublyLinkedList <T>::Print() const{
    auto current = head;
    while (current){
        std::cout << current->val << ", ";
        current = current->next;
    }
}

#endif