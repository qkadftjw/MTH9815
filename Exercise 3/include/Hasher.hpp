#ifndef HASHER_HPP
#define HASHER_HPP

#include <iostream>
using namespace std;

template<typename T>
class Hasher{
public:
    virtual size_t hash(const T& key) const = 0;
    virtual ~Hasher() = default;
};

#endif