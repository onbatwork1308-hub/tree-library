#ifndef SET_TPP
#define SET_TPP

#ifdef __INTELLISENSE__
#include <Set.h>
#endif

#include <vector>

template<typename T>
Set<T>::Set() : tree() {}

template<typename T>
Set<T>::Set(std::initializer_list<T> values) : tree() {
    this->tree = std::vector<T>(values);
}

template<typename T>
Set<T>::Set(const std::vector<T>& values) : tree() {
    this->tree = values;
}

template<typename T>
Set<T>& Set<T>::operator=(const std::vector<T>& values) {
    this->tree = values;
    return *this;
}


template<typename T>
Set<T>& Set<T>::operator=(const std::initializer_list<T>& values) {
    this->tree = std::vector<T>(values);
    return *this;
}

template<typename T>
bool Set<T>::operator==(const Set<T>& other) const {
    return this->tree == other.tree;
}

template<typename T>
bool Set<T>::operator!=(const Set<T>& other) const {
    return !(*this == other);
}

template<typename T>
size_t Set<T>::size() const {
    return this->tree.size();
}

template<typename T>
bool Set<T>::empty() const {
    return this->tree.empty();
}

template<typename T>
void Set<T>::clear() {
    this->tree.clear();
}

template<typename T>
std::vector<T> Set<T>::to_vector() const {
    return this->tree.inorder();
}

template<typename T>
void Set<T>::insert(const T& value) {
    this->tree.insert(value);
}

template<typename T>
void Set<T>::erase(const T& value) {
    this->tree.erase(value);
}

template<typename T>
bool Set<T>::contains(const T& value) const {
    return this->tree.contains(value);
}

template<typename T>
Set<T> Set<T>::set_union(const Set<T>& other) const {

    Set<T> result = *this; // Start with a copy of the current set
    std::vector<T> other_elements = other.to_vector();

    for (const T& elem : other_elements) {
        result.insert(elem);
    }

    return result;
}

template<typename T>
Set<T> Set<T>::set_intersection(const Set<T>& other) const {
    Set<T> result;
    std::vector<T> other_elements = other.to_vector();
    for (const T& elem : other_elements) {
        if (this->contains(elem)) {
            result.insert(elem);
        }
    }
    return result;
}

template<typename T>
Set<T> Set<T>::set_difference(const Set<T>& other) const {
    Set<T> result = *this; // Start with a copy of the current set
    auto other_elements = other.to_vector();
    for (const T& elem : other_elements) {
        result.erase(elem);
    }
    return result;
}

template<typename T>
Set<T> Set<T>::symmetric_difference(const Set<T>& other) const {
    return this->set_union(other).set_difference(this->set_intersection(other));
}




#endif // SET_TPP

