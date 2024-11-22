#ifndef EQUALITY_PREDICATE_HPP
#define EQUALITY_PREDICATE_HPP

#include <iostream>
using namespace std;

template<typename T>
class EqualityPredicate{
public:
    virtual bool equals(const T& key1, const T& key2) const = 0;
    virtual ~EqualityPredicate() = default;
};

#endif