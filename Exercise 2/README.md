# Exercise1 - Doubly Linked List Implementation

This project implements a generic **Double Linked List** in C++ with additional features such as iterators. The project is set up using **CMake** and is compiled using **GCC 13**.

## Features

### **DoublyLinkedList**
The `DoublyLinkedList` class provides functionality for creating and managing a doubly linked list. Key features include:

- **Add elements to the list**:  
  Append new elements to the end of the linked list using the `Add` method.

- **Insert elements at a specific index**:  
  Insert a new element into the list at a specified index using the `Insert` method.

- **Remove elements by index**:  
  Remove and return the element at a specific index using the `Remove` method.

- **Retrieve elements by index**:  
  Access elements at a specified index using the `Get` method.

- **Retrieve the index of a value**:  
  Find the index of a specific value in the list using the `IndexOf` method (returns `-1` if the value is not found).

- **Print the entire list**:  
  Display all the elements of the list sequentially using the `Print` method.

- **Iterate over the linked list**:  
  Use the `Iterator` method to get an iterator for traversing the list.

- **Check the size of the list**:  
  Use the `Size` method to get the number of elements currently in the list.

---

### **ListIterator**
The `ListIterator` class is designed to work with the `DoublyLinkedList`, providing tools for traversing the list. Key features include:

- **Standard iterator operations**:  
  Use operators such as `*` to dereference the current element, `++` to move to the next node, and `--` to move to the previous node.

- **Forward and backward traversal**:  
  Traverse the list in both directions using `HasNext` and `Next` for forward traversal, and `HasPrev` and `Prev` for backward traversal.

- **Equality and inequality operators**:  
  Compare two iterators using `==` and `!=` to check if they point to the same node.

- **Flexible construction**:  
  Create an iterator with no initial node (default constructor) or start from a specific node (explicit constructor).

- **Robust error handling**:  
  Ensure safe access to list elements by throwing exceptions for invalid operations, such as dereferencing a null iterator or traversing past the list bounds.

## Prerequisites

- **C++ Compiler**: GCC 13 or higher.
- **CMake**: Version 3.10 or higher.

---

## Project Structure

```
├── Exercise 2
│   ├── include
│   │   ├── DNode.hpp             # Node class for DoublyLinkedList
│   │   ├── DoubleLinkedList.hpp  # DoublyLinkedList class declaration
│   │   ├── ListIterator.hpp      # Iterator class for DoublyLinkedList
│   ├── src
│   │   ├── DoubleLinkedList.cpp  # Implementation of DoublyLinkedList
│   │   ├── ListIterator.cpp      # Implementation of ListIterator
│   │   ├── test_dlinkedlist.cpp  # Main test file
│   ├── CMakeLists.txt            # CMake build configuration
│   └── README.md                 # Documentation for Exercise 2
├── .vscode
│   └── settings.json             # VSCode project settings
└── README.md                     # Top-level project documentation
```

---

## Build and Run Instructions

1. **Create a build directory**:

   ```bash
   mkdir build
   cd build
   ```

2. **Configure and build using CMake**:

   ```bash
   cmake ..
   make
   ```

3. **Run the executable**:

   ```bash
   ./test_linkedlist
   ```

---

## Example Output

Sample output from `test_double_linkedlist.cpp`:

```
******************** Testing Doubly Linked List ********************

Testing Add function:
List after adding 10, 20, 30: 10, 20, 30, 
Testing Insert function:
List after inserting 5 at index 0: 5, 10, 20, 30, 
List after inserting 15 at index 2: 5, 10, 15, 20, 30, 
List after inserting 35 at the end: 5, 10, 15, 20, 30, 35, 
Testing Get function:
Element at index 0: 5
Element at index 3: 20
Element at index 4: 30
Testing IndexOf function:
Index of 20: 3
Index of 40 (not in list): -1

Testing Remove function:
Removed value at index 0: 5
List after removing index 0: 10, 15, 20, 30, 35, 
Removed value at index 1: 15
List after removing index 1: 10, 20, 30, 35, 
Removed value at the last index: 35
List after removing the last element: 10, 20, 30, 
List after removing all elements: 30, 
Removed value at index 0: 30

List after re-adding 100, 200, 300: 100, 200, 300, 
Testing Size function:
Current size of the list: 3

Testing exception handling for out-of-range access:
Caught exception as expected: Index out of range

******************** Testing Doubly Linked List Iterator ********************

Initial list: 10, 20, 30, 40, 50, 

Testing Pre-increment operator (++it):
Current element: 10
After pre-increment, current element: 20

Testing Post-increment operator (it++):
Current element: 10
After post-increment, original iterator current element: 20
Returned iterator value from post-increment: 10

Testing Pre-decrement operator (--it):
Current element before pre-decrement: 20
After pre-decrement, current element: 10

Testing Post-decrement operator (it--):
Current element before post-decrement: 20
After post-decrement, original iterator current element: 10
Returned iterator value from post-decrement: 20

Testing HasNext() and Next():
Current element: 10, Next element: 10
Current element: 20, Next element: 20
Current element: 30, Next element: 30
Current element: 40, Next element: 40

Testing HasPrev() and Prev():
Current element: 50, Previous element: 50
Current element: 40, Previous element: 40
Current element: 30, Previous element: 30
Current element: 20, Previous element: 20

Testing Equality and Inequality operators:
itEqual1 and itEqual2 are equal
After incrementing itEqual1, itEqual1 and itEqual2 are not equal

Testing Assignment operator:
itAssigned current element: 20
itAssign current element: 20
itAssigned and itAssign are equal

Testing Boundary Conditions:
Current element: 10
Attempting to pre-decrement at the beginning:
Error: Cannot decrement iterator past the beginning.
Iterator is now at the end. Current element: 50
Attempting to post-increment at the end:
Error: Cannot increment iterator past the end.
```

---

## Customization

- You can modify the **CMakeLists.txt** file to adjust compiler settings or include additional files.
- Edit `test_double_linkedlist.cpp` to add more test cases or customize the output.