# Exercise3 - Hashtable Implementation

This project implements a generic **Hashtable** in C++ with customizable hashing and equality predicates. The project is set up using **CMake** and is compiled using **GCC 13**.

## Features

### **Hashtable**
The `Hashtable` class provides a generic implementation of a hashtable. Key features include:

- **Insert key-value pairs**:  
  Add new key-value pairs to the hashtable using the `insert` method.

- **Remove elements by key**:  
  Remove a key-value pair from the hashtable using the `erase` method.

- **Find elements by key**:  
  Retrieve the value associated with a given key using the `find` method.

- **Customizable hashing**:  
  Supports user-defined hash functions through the `Hasher` interface.

- **Customizable equality comparison**:  
  Allows the use of custom equality predicates via the `EqualityPredicate` interface.

---

### **Hasher**
The `Hasher` class is an abstract template class that defines the interface for hash functions. Key features include:

- **General hashing**:  
  Use the `GeneralHasher` class, which relies on the standard `std::hash` for general-purpose hashing.

---

### **EqualityPredicate**
The `EqualityPredicate` class is an abstract template class that defines the interface for key equality comparison. Key features include:

- **General equality**:  
  Use the `GeneralEquality` class, which uses the `==` operator for equality comparison.

---

## Prerequisites

- **C++ Compiler**: GCC 13 or higher.
- **CMake**: Version 3.10 or higher.

---

## Project Structure

```
.
├── include
│   ├── EqualityPredicate.hpp    # Abstract class for equality comparison
│   ├── GeneralEquality.hpp      # Default equality comparison implementation
│   ├── GeneralHasher.hpp        # Default hash function implementation
│   ├── Hasher.hpp               # Abstract class for hashing
│   ├── Hashtable.hpp            # Hashtable class declaration
├── src
│   ├── test_hashtable.cpp       # Main test file for hashtable
├── CMakeLists.txt               # CMake build configuration
└── README.md                    # Project documentation
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

Sample output from `test_hashtable.cpp`:

```
Found key 'Bob' with value: 25
Key 'Alice' deleted successfully
Key 'Alice' not found
```

---

## Customization

- You can modify the **CMakeLists.txt** file to adjust compiler settings or include additional files.
- Edit `test_hashtable.cpp` to add more test cases or customize the output.
