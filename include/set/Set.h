#ifndef SET_H
#define SET_H

#include <tree/binary/avl_trees.h>
#include <iostream>

template <typename T>
class Set {
private:
    avl_tree<T> tree;
public:
    Set();
    Set(const std::vector<T>& values);
    Set(std::initializer_list<T> values);
    Set(const Set<T>& other) = default;
    Set(Set<T>&& other) = default;
    ~Set() = default;

    size_t size() const;
    bool empty() const;
    void clear();
    std::vector<T> to_vector() const;

    void insert(const T& value);
    void erase(const T& value);
    bool contains(const T& value) const;
    
    Set<T> set_union(const Set<T>& other) const;
    Set<T> set_intersection(const Set<T>& other) const;
    Set<T> set_difference(const Set<T>& other) const;
    Set<T> symmetric_difference(const Set<T>& other) const;

    Set<T>& operator=(const std::vector<T>& values);
    Set<T>& operator=(const Set<T>& other)= default;
    Set<T>& operator=(const std::initializer_list<T>& values);
    bool operator==(const Set<T>& other) const;
    bool operator!=(const Set<T>& other) const;

};

#include "Set.tpp"

#endif // SET_H