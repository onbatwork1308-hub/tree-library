#ifndef AVL_TREES_H
#define AVL_TREES_H

#include "detail/AVLTree.h"

template <typename T>
class avl_tree {
private:
    detail::AVLTree<T> impl;

public:
    avl_tree() = default;
    avl_tree(const avl_tree& other) = default;
    avl_tree(avl_tree&&) noexcept = default;
    avl_tree& operator=(avl_tree&&) noexcept = default;
    avl_tree& operator=(const avl_tree& other) = default;

    avl_tree(const std::vector<T>& values) {
        *this = values;
    }

    avl_tree(const std::initializer_list<T>& init_list) {
        *this = init_list;
    }

    avl_tree<T>& operator=(const std::vector<T>& values) {
        impl = values;
        return *this;
    }

    avl_tree<T>& operator=(const std::initializer_list<T>& init_list) {
        return operator=(std::vector<T>(init_list));
    }

    bool operator==(const avl_tree& other) const {
        return impl == other.impl;
    }

    bool operator!=(const avl_tree& other) const {
        return !(*this == other);
    }

    bool insert(const T& value) {
        return impl.insert(value);
    }

    bool erase(const T& value) {
        return impl.remove(value);
    }

    bool contains(const T& value) const {
        return impl.contains(value);
    }

    void clear() {
        impl.deleteTree();
    }

    bool empty() const {
        return this->size() == 0;
    }

    int height() const {
        return impl.getHeight();
    }

    static avl_tree<T> build_from_sorted(const std::vector<T>& sorted, int start = 0, int end = -1) {
    avl_tree<T> avl;

    if (sorted.empty()) return avl;

    start = std::max(0, start);
    end = (end == -1) ? sorted.size() - 1 : std::min((int)sorted.size() - 1, end);

    if (start > end) return avl;

    avl.impl = detail::AVLTree<T>::build_from_sorted(sorted, start, end);
    return avl;

    }

    std::vector<T> inorder() const {
        return impl.inorder();
    }

    std::vector<T> preorder() const {
        return impl.preorder();
    }

    std::vector<T> postorder() const {
        return impl.postorder();
    }
    
    std::vector<std::vector<T>> levelorder() const {
        return impl.levelorder();
    }

    std::vector<std::vector<T>> vertical_order() const {
        return impl.verticalOrder();
    }

    size_t size() const {
        return impl.numNodes();
    }

    size_t leaf_count() const {
        return impl.numLeaves();
    }

    size_t single_child_count() const {
        return impl.numNodesWithOneChild();
    }

    size_t double_child_count() const {
        return impl.numNodesWithTwoChildren();
    }
};

#endif // AVL_TREES_H