#ifndef HASHER_HPP
#define HASHER_HPP

#include <iostream>
using namespace std;

// Abstract template class for defining hash functions.
template<typename T>
class Hasher {
public:
    // Pure virtual method to compute the hash value of a key.
    virtual size_t hash(const T& key) const = 0;

    // Virtual destructor to allow proper cleanup in derived classes.
    virtual ~Hasher() = default;
};

#endif
