// Hashtable.hpp
// Date: 2024-11-16

#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include "Hasher.hpp"
#include "EqualityPredicate.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <list>

// Generic Hashtable class supporting custom hash and equality predicates.
template<typename K, typename V>
class Hashtable {

private:
    // Struct to represent a key-value entry in the hash table.
    struct Entry {
        K key;    // Key of the entry.
        V value;  // Value of the entry.
    };

    std::vector<std::list<Entry>> buckets; // Buckets containing lists of entries.
    std::shared_ptr<Hasher<K>> hasher;    // Custom hasher for key hashing.
    std::shared_ptr<EqualityPredicate<K>> equality; // Custom equality predicate for key comparison.
    size_t bucket_count; // Total number of buckets.

    // Computes the bucket index for a given key.
    size_t get_bucket_index(const K& key) const {
        return hasher->hash(key) % bucket_count;
    }

public:
    // Constructor: Initializes the hash table with the given bucket count, hasher, and equality predicate.
    Hashtable(size_t bucket_count, std::shared_ptr<Hasher<K>> hasher, std::shared_ptr<EqualityPredicate<K>> equality_pred);

    // Destructor: Cleans up resources.
    virtual ~Hashtable();

    // Inserts a key-value pair into the hash table.
    void insert(const K& key, const V& val);

    // Removes a key-value pair by key. Returns true if successful, false otherwise.
    bool erase(const K& key);

    // Finds the value associated with a key. Returns true if the key exists, false otherwise.
    bool find(const K& key, V& val) const;
};

// Constructor: Initializes buckets and ensures the hasher and equality predicate are valid.
template<typename K, typename V>
Hashtable<K, V>::Hashtable(size_t bucket_count, std::shared_ptr<Hasher<K>> hasher, std::shared_ptr<EqualityPredicate<K>> equality_pred)
    : hasher(std::move(hasher)), equality(std::move(equality_pred)), bucket_count(bucket_count)
{
    if (!this->hasher || !this->equality) {
        throw std::invalid_argument("Hasher and EqualityPredicate cannot be null");
    }
    if (bucket_count == 0) {
        throw std::invalid_argument("Bucket count must be greater than 0");
    }
    buckets.resize(bucket_count); // Initialize buckets with the given size.
}

// Destructor: No special cleanup required since smart pointers handle memory.
template<typename K, typename V>
Hashtable<K, V>::~Hashtable()
{
}

// Inserts a key-value pair into the hash table. Updates the value if the key already exists.
template<typename K, typename V>
void Hashtable<K, V>::insert(const K& key, const V& val) {
    size_t index = get_bucket_index(key);
    for (auto& entry : buckets[index]) {
        if (equality->equals(entry.key, key)) {
            entry.value = val; // Update value if key exists.
            return;
        }
    }
    buckets[index].push_back({key, val}); // Insert new entry if key does not exist.
}

// Removes a key-value pair by key. Returns true if the key was found and removed.
template<typename K, typename V>
bool Hashtable<K, V>::erase(const K& key) {
    size_t index = get_bucket_index(key);
    auto& bucket = buckets[index];
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (equality->equals(it->key, key)) {
            bucket.erase(it); // Remove the entry.
            return true;
        }
    }
    return false; // Key not found.
}

// Finds the value associated with a key. Returns true if the key exists, false otherwise.
template<typename K, typename V>
bool Hashtable<K, V>::find(const K& key, V& val) const {
    size_t index = get_bucket_index(key);
    const auto& bucket = buckets[index];
    for (const auto& entry : bucket) {
        if (equality->equals(entry.key, key)) {
            val = entry.value; // Assign the found value to the output parameter.
            return true;
        }
    }
    return false; // Key not found.
}

#endif
