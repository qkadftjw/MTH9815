#ifndef GENERAL_HASHER_HPP
#define GENERAL_HASHER_HPP

#include "Hasher.hpp"

template <typename T>
class GeneralHasher : public Hasher<T> {

public:
    size_t hash(const T& key) const override {
        return std::hash<T>() (key);
    }
};

#endif
