// GeneralEquality.hpp
// Date: 2024-11-16

#ifndef GENERAL_EQUALITY_HPP
#define GENERAL_EQUALITY_HPP

#include "EqualityPredicate.hpp"

// Concrete implementation of EqualityPredicate for general equality.
template <typename T>
class GeneralEquality : public EqualityPredicate<T> {
public:
    // Overrides the equals method to compare two keys using the == operator.
    bool equals(const T& key1, const T& key2) const override {
        return key1 == key2;
    }
};

#endif
