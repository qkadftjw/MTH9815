// test_linkedlist.cpp
// Author: Fangtong Wang
// Date: 2024-11-16

#include <iostream>
#include <stdexcept>
#include "DoubleLinkedList.hpp"

int main() {
{
    // Create an instance of DoublyLinkedList
    DoublyLinkedList<int> list;

    std::cout << "******************** Testing Doubly Linked List ********************\n" << std::endl;

    // Test the Add function
    std::cout << "Testing Add function:" << std::endl;
    list.Add(10); // Add 10 to the list
    list.Add(20); // Add 20 to the list
    list.Add(30); // Add 30 to the list
    std::cout << "List after adding 10, 20, 30: ";
    list.Print();
    std::cout << "\n";

    // Test the Insert function
    std::cout << "Testing Insert function:" << std::endl;
    // Insert at the beginning
    list.Insert(5, 0); // Insert 5 at index 0
    std::cout << "List after inserting 5 at index 0: ";
    list.Print();
    std::cout << "\n";

    // Insert in the middle
    list.Insert(15, 2); // Insert 15 at index 2
    std::cout << "List after inserting 15 at index 2: ";
    list.Print();
    std::cout << "\n";

    // Insert at the end
    list.Insert(35, list.Size()); // Insert 35 at the end
    std::cout << "List after inserting 35 at the end: ";
    list.Print();
    std::cout << "\n";

    // Test the Get function
    std::cout << "Testing Get function:" << std::endl;
    try {
        // Get elements at various indices
        std::cout << "Element at index 0: " << list.Get(0) << "\n";
        std::cout << "Element at index 3: " << list.Get(3) << "\n";
        std::cout << "Element at index 4: " << list.Get(4) << "\n";
    } catch (const std::out_of_range& e) {
        // Handle out-of-range access
        std::cerr << "Error: " << e.what() << "\n";
    }

    // Test the IndexOf function
    std::cout << "Testing IndexOf function:" << std::endl;
    std::cout << "Index of 20: " << list.IndexOf(20) << "\n";
    std::cout << "Index of 40 (not in list): " << list.IndexOf(40) << "\n";
    std::cout << "\n";

    // Test the Remove function
    std::cout << "Testing Remove function:" << std::endl;
    try {
        // Remove from the beginning
        int removedValue = list.Remove(0);
        std::cout << "Removed value at index 0: " << removedValue << "\n";
        std::cout << "List after removing index 0: ";
        list.Print();
        std::cout << "\n";

        // Remove from the middle
        removedValue = list.Remove(1);
        std::cout << "Removed value at index 1: " << removedValue << "\n";
        std::cout << "List after removing index 1: ";
        list.Print();
        std::cout << "\n";

        // Remove from the end
        removedValue = list.Remove(list.Size() - 1);
        std::cout << "Removed value at the last index: " << removedValue << "\n";
        std::cout << "List after removing the last element: ";
        list.Print();
        std::cout << "\n";

        // Attempt to remove from an empty list
        // First, remove remaining elements
        list.Remove(0); // Remove first element
        list.Remove(0); // Remove last remaining element
        std::cout << "List after removing all elements: ";
        list.Print();
        std::cout << "\n";

        // Now, try removing from the empty list
        removedValue = list.Remove(0); // Should throw an exception
        std::cout << "Removed value at index 0: " << removedValue << "\n";
    } catch (const std::out_of_range& e) {
        // Handle out-of-range removal
        std::cerr << "Error: " << e.what() << "\n";
    }

    // Re-populate the list for further tests
    list.Add(100);
    list.Add(200);
    list.Add(300);
    std::cout << "\nList after re-adding 100, 200, 300: ";
    list.Print();
    std::cout << "\n";

    // Test the Size function
    std::cout << "Testing Size function:" << std::endl;
    std::cout << "Current size of the list: " << list.Size() << "\n";
    std::cout << "\n";

    // Test exception handling for out-of-range access
    std::cout << "Testing exception handling for out-of-range access:" << std::endl;
    try {
        list.Get(10); // Should throw an exception
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception as expected: " << e.what() << "\n";
    }
}

{
    std::cout << "\n******************** Testing Doubly Linked List Iterator ********************\n" << std::endl;
    // 1. Initialize the Doubly Linked List with initial elements
    DoublyLinkedList<int> list;
    list.Add(10);
    list.Add(20);
    list.Add(30);
    list.Add(40);
    list.Add(50);
    std::cout << "Initial list: ";
    list.Print();
    std::cout << "\n\n";

    // 2. Test Pre-increment operator (operator++())
    std::cout << "Testing Pre-increment operator (++it):" << std::endl;
    ListIterator<int> itPreInc = list.Iterator();
    std::cout << "Current element: " << *itPreInc << std::endl; // Should be 10
    ++itPreInc;
    std::cout << "After pre-increment, current element: " << *itPreInc << std::endl; // Should be 20
    std::cout << "\n";

    // 3. Test Post-increment operator (operator++(int))
    std::cout << "Testing Post-increment operator (it++):" << std::endl;
    ListIterator<int> itPostInc = list.Iterator();
    std::cout << "Current element: " << *itPostInc << std::endl; // Should be 10
    ListIterator<int> tempPostInc = itPostInc++;
    std::cout << "After post-increment, original iterator current element: " << *itPostInc << std::endl; // Should be 20
    std::cout << "Returned iterator value from post-increment: " << *tempPostInc << std::endl; // Should be 10
    std::cout << "\n";

    // 4. Test Pre-decrement operator (operator--())
    std::cout << "Testing Pre-decrement operator (--it):" << std::endl;
    ListIterator<int> itPreDec = list.Iterator();
    ++itPreDec; // Move to 20
    std::cout << "Current element before pre-decrement: " << *itPreDec << std::endl; // Should be 20
    --itPreDec;
    std::cout << "After pre-decrement, current element: " << *itPreDec << std::endl; // Should be 10
    std::cout << "\n";

    // 5. Test Post-decrement operator (operator--(int))
    std::cout << "Testing Post-decrement operator (it--):" << std::endl;
    ListIterator<int> itPostDec = list.Iterator();
    ++itPostDec; // Move to 20
    std::cout << "Current element before post-decrement: " << *itPostDec << std::endl; // Should be 20
    ListIterator<int> tempPostDec = itPostDec--;
    std::cout << "After post-decrement, original iterator current element: " << *itPostDec << std::endl; // Should be 10
    std::cout << "Returned iterator value from post-decrement: " << *tempPostDec << std::endl; // Should be 20
    std::cout << "\n";

    // 6. Test HasNext() and Next()
    std::cout << "Testing HasNext() and Next():" << std::endl;
    ListIterator<int> itHasNext = list.Iterator();
    while (itHasNext.HasNext()) {
        std::cout << "Current element: " << *itHasNext << ", Next element: " << itHasNext.Next() << std::endl;
    }
    std::cout << "\n";

    // 7. Test HasPrev() and Prev()
    std::cout << "Testing HasPrev() and Prev():" << std::endl;
    ListIterator<int> itHasPrev = list.Iterator();
    // Move iterator to the end
    while (itHasPrev.HasNext()) {
        itHasPrev.Next();
    }
    // Now iterate backwards
    while (itHasPrev.HasPrev()) {
        std::cout << "Current element: " << *itHasPrev << ", Previous element: " << itHasPrev.Prev() << std::endl;
    }
    std::cout << "\n";

    // 8. Test Equality and Inequality Operators
    std::cout << "Testing Equality and Inequality operators:" << std::endl;
    ListIterator<int> itEqual1 = list.Iterator();
    ListIterator<int> itEqual2 = list.Iterator();
    std::cout << "itEqual1 and itEqual2 are " << ((itEqual1 == itEqual2) ? "equal" : "not equal") << std::endl;
    ++itEqual1;
    std::cout << "After incrementing itEqual1, itEqual1 and itEqual2 are " << ((itEqual1 == itEqual2) ? "equal" : "not equal") << std::endl;
    std::cout << "\n";

    // 9. Test Assignment Operator
    std::cout << "Testing Assignment operator:" << std::endl;
    ListIterator<int> itAssign = list.Iterator();
    ++itAssign; // Move to 20
    ListIterator<int> itAssigned;
    itAssigned = itAssign; // Assign
    std::cout << "itAssigned current element: " << *itAssigned << std::endl; // Should be 20
    std::cout << "itAssign current element: " << *itAssign << std::endl; // Should be 20
    std::cout << "itAssigned and itAssign are " << ((itAssigned == itAssign) ? "equal" : "not equal") << std::endl;
    std::cout << "\n";

    // 10. Test Boundary Conditions
    std::cout << "Testing Boundary Conditions:" << std::endl;
    // Attempt to decrement iterator at the beginning
    ListIterator<int> itBoundary = list.Iterator();
    std::cout << "Current element: " << *itBoundary << std::endl; // Should be 10
    std::cout << "Attempting to pre-decrement at the beginning:" << std::endl;
    try {
        --itBoundary; // Should handle gracefully, possibly remain at head or throw
        std::cout << "After pre-decrement, current element: " << *itBoundary << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Attempt to increment iterator at the end
    itBoundary = list.Iterator();
    while (itBoundary.HasNext()) {
        itBoundary.Next();
    }
    std::cout << "Iterator is now at the end. Current element: " << *itBoundary << std::endl; // Should be 50
    std::cout << "Attempting to post-increment at the end:" << std::endl;
    try {
        itBoundary++; // Should handle gracefully, possibly move to nullptr or throw
        if (itBoundary == ListIterator<int>(nullptr)) {
            std::cout << "Iterator has moved past the end." << std::endl;
        } else {
            std::cout << "After post-increment, current element: " << *itBoundary << std::endl;
        }
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
}