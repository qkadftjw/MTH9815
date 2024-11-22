# Exercise1 - Linked List Implementation

This project implements a generic **Linked List** in C++ with additional features such as iterators. The project is set up using **CMake** and is compiled using **GCC 13**.

## Features

- **LinkedList**:
  - Add elements to the list.
  - Insert elements at a specific index.
  - Remove elements by index.
  - Retrieve elements by index.
  - Print the entire list.
- **ListIterator**:
  - Iterate over the linked list using an iterator.
  - Supports standard iterator operations (`++`, `*`, etc.).

---

## Prerequisites

- **C++ Compiler**: GCC 13 or higher.
- **CMake**: Version 3.10 or higher.

---

## Project Structure

```
.
├── include
│   ├── LinkedList.hpp        # LinkedList template class declaration
│   ├── ListIterator.hpp      # Iterator class for LinkedList
│   ├── ListNode.hpp          # Node class for LinkedList
├── src
│   ├── LinkedList.cpp        # Implementation of LinkedList
│   ├── ListIterator.cpp      # Implementation of ListIterator
│   ├── ListNode.cpp          # Implementation of ListNode
│   ├── test_linkedlist.cpp   # Main test file
├── CMakeLists.txt            # CMake build configuration
└── README.md                 # Project documentation
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

Sample output from `test_linkedlist.cpp`:

```
******************** Test Linked List ********************

Testing Add:
List after adding 10, 20, 30: 10, 20, 30, 
Testing Insert:
List after inserting 15 at index 1: 10 15 20 30 
Testing Get:
Element at index 2: 20
Testing IndexOf:
Index of 20: 2
Index of 40 (not in list): -1
Testing Remove:
Removed value at index 1: 15
List after removal: 10, 20, 30, 
Testing Size:
Current size of the list: 3
Testing exceptions:
Caught exception as expected: Index out of range

******************** Test Linked List Iterator ********************

Testing operator*:
Current value: 10

Testing HasNext() and Next():
Next value: 10
Next value: 20

Testing post-increment operator:
Before increment: 10
After increment (original iterator): 20
Returned iterator value: 10

Testing pre-increment operator:
Before increment: 10
After increment: 20

Testing equality and inequality operators:
Iterators are not equal
After advancing, iterators are not equal

Testing assignment operator:
Assigned iterator value: 20
```

---

## Customization

- You can modify the **CMakeLists.txt** file to adjust compiler settings or include additional files.
- Edit `test_linkedlist.cpp` to add more test cases or customize the output.
