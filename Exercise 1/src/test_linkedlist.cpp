// test_linkedlist.cpp
// Date: 2024-11-16

#include <iostream>
#include "LinkedList.hpp"

int main() {
    // Create an instance of LinkedList
    LinkedList<int> list;

    std::cout << "******************** Test Linked List ********************\n" << std::endl;
    // Test the Add function
    std::cout << "Testing Add:" << std::endl;
    list.Add(10); // Add 10 to the list
    list.Add(20); // Add 20 to the list
    list.Add(30); // Add 30 to the list
    std::cout << "List after adding 10, 20, 30: ";
    list.Print();
    std::cout << "\n";

    // Test the Insert function
    std::cout << "Testing Insert:" << std::endl;
    list.Insert(15, 1); // Insert 15 at index 1
    std::cout << "List after inserting 15 at index 1: ";
    for (int i = 0; i < list.Size(); ++i) {
        // Print all elements in the list
        std::cout << list.Get(i) << " ";
    }
    std::cout << "\n";

    // Test the Get function
    std::cout << "Testing Get:" << std::endl;
    try {
        // Get the element at index 2
        std::cout << "Element at index 2: " << list.Get(2) << "\n";
    } catch (const std::out_of_range& e) {
        // Handle exception for out-of-range access
        std::cerr << "Error: " << e.what() << "\n";
    }

    // Test the IndexOf function
    std::cout << "Testing IndexOf:" << std::endl;
    // Find the index of the value 20
    std::cout << "Index of 20: " << list.IndexOf(20) << "\n";
    // Try to find the index of a value not in the list (40)
    std::cout << "Index of 40 (not in list): " << list.IndexOf(40) << "\n";

    // Test the Remove function
    std::cout << "Testing Remove:" << std::endl;
    try {
        // Remove the element at index 1
        int removedValue = list.Remove(1);
        std::cout << "Removed value at index 1: " << removedValue << "\n";
        std::cout << "List after removal: ";
        list.Print();
        std::cout << "\n";
    } catch (const std::out_of_range& e) {
        // Handle exception for out-of-range removal
        std::cerr << "Error: " << e.what() << "\n";
    }

    // Test the Size function
    std::cout << "Testing Size:" << std::endl;
    // Print the current size of the list
    std::cout << "Current size of the list: " << list.Size() << "\n";

    // Test exception handling for out-of-range access
    std::cout << "Testing exceptions:" << std::endl;
    try {
        // Try to get an element at an invalid index
        list.Get(100); // Should throw an exception
    } catch (const std::out_of_range& e) {
        // Handle the expected exception
        std::cerr << "Caught exception as expected: " << e.what() << "\n";
    }

    std::cout << "\n******************** Test Linked List Iterator ********************\n" << std::endl;

    // Test the iterator object.
    ListIterator<int> iterator = list.Iterator();
    // Test operator* (dereference operator)
    std::cout << "Testing operator*:" << std::endl;
    std::cout << "Current value: " << *iterator << std::endl;

    // Test HasNext() and Next()
    std::cout << "\nTesting HasNext() and Next():" << std::endl;
    while (iterator.HasNext()) {
        std::cout << "Next value: " << iterator.Next() << std::endl;
    }

    // Test post-increment operator (operator++(int))
    std::cout << "\nTesting post-increment operator:" << std::endl;
    ListIterator<int> postIncrementIterator(list.head);
    std::cout << "Before increment: " << *postIncrementIterator << std::endl;
    ListIterator<int> temp = postIncrementIterator++;
    std::cout << "After increment (original iterator): " << *postIncrementIterator << std::endl;
    std::cout << "Returned iterator value: " << *temp << std::endl;

    // Test pre-increment operator (operator++())
    std::cout << "\nTesting pre-increment operator:" << std::endl;
    ListIterator<int> preIncrementIterator(list.head);
    std::cout << "Before increment: " << *preIncrementIterator << std::endl;
    ++preIncrementIterator;
    std::cout << "After increment: " << *preIncrementIterator << std::endl;

    // Test equality operator (operator==) and inequality operator (operator!=)
    std::cout << "\nTesting equality and inequality operators:" << std::endl;
    ListIterator<int> anotherIterator(list.head);
    std::cout << "Iterators are " << (iterator == anotherIterator ? "equal" : "not equal") << std::endl;

    // Advance both iterators
    ++iterator;
    ++anotherIterator;
    std::cout << "After advancing, iterators are " << (iterator == anotherIterator ? "equal" : "not equal") << std::endl;

    // Test assignment operator (operator=)
    std::cout << "\nTesting assignment operator:" << std::endl;
    ListIterator<int> assignedIterator = anotherIterator;
    std::cout << "Assigned iterator value: " << *assignedIterator << std::endl;

    return 0;

}
