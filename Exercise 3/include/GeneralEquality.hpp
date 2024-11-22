#ifndef GENERAL_EQUALITY_HPP
#define GENERAL_EQUALITY_HPP

#include "EqualityPredicate.hpp"

template <typename T>
class GeneralEquality : public EqualityPredicate<T> {
public:
    bool equals(const T& key1, const T& key2) const override{
        return key1 == key2;
    }
};

#endif