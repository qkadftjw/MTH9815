#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include "Hasher.hpp"
#include "EqualityPredicate.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <list>

template<typename K, typename V>
class Hashtable {

private:
    struct Entry {
        K key;
        V value;
    };

    std::vector<std::list<Entry>> buckets;
    std::shared_ptr<Hasher<K>> hasher;
    std::shared_ptr<EqualityPredicate<K>> equality;
    size_t bucket_count;

    size_t get_bucket_index(const K& key) const{
        return hasher->hash(key) % bucket_count;
    }

public:
    Hashtable(size_t bucket_count, std::shared_ptr<Hasher<K>> hasher, std::shared_ptr<EqualityPredicate<K>> equality_pred);
    virtual ~Hashtable();

    void insert(const K& key, const V& val);
    bool erase(const K& key);
    bool find(const K& key, V& val) const;
};

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
    buckets.resize(bucket_count);
}

template<typename K, typename V>
Hashtable<K, V>::~Hashtable()
{
}

template<typename K, typename V>
void Hashtable<K, V>::insert(const K& key, const V& val){
    size_t index = get_bucket_index(key);
    for (auto& entry : buckets[index]) {
        if (equality->equals(entry.key, key)) {
            entry.value = val;
            return;
        }
    }

    buckets[index].push_back({key, val});
}

template<typename K, typename V>
bool Hashtable<K, V>::erase(const K& key) {
    size_t index = get_bucket_index(key);
    auto& bucket = buckets[index];
    for (auto it = bucket.begin(); it != bucket.end(); ++it){
        if (equality->equals(it->key, key)){
            bucket.erase(it);
            return true;
        }
    }
    return false;
}

template<typename K, typename V>
bool Hashtable<K, V>::find(const K& key, V& val) const{
    size_t index = get_bucket_index(key);
    const auto& bucket = buckets[index];
    for (const auto& entry : bucket) {
        if (equality->equals(entry.key, key)) {
            val = entry.value;
            return true;
        }
    }
    return false;
}

#endif
