#ifndef GENERAL_HASHER_HPP
#define GENERAL_HASHER_HPP

#include "Hasher.hpp"

// Concrete implementation of Hasher for general-purpose hashing.
template <typename T>
class GeneralHasher : public Hasher<T> {

public:
    // Overrides the hash method to compute a hash value using std::hash.
    size_t hash(const T& key) const override {
        return std::hash<T>()(key);
    }
};

#endif
