#ifndef EQUALITY_PREDICATE_HPP
#define EQUALITY_PREDICATE_HPP

#include <iostream>
using namespace std;

// Abstract template class for defining equality predicates.
template<typename T>
class EqualityPredicate {
public:
    // Pure virtual method to compare two keys for equality.
    virtual bool equals(const T& key1, const T& key2) const = 0;

    // Virtual destructor to allow proper cleanup in derived classes.
    virtual ~EqualityPredicate() = default;
};

#endif