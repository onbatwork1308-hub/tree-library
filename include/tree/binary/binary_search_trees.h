#ifndef BINARY_SEARCH_TREES_H
#define BINARY_SEARCH_TREES_H

#include "detail/BinarySearchTree.h"

template<typename T>
class binary_search_tree {
private:
    detail::BinarySearchTree<T, detail::TreeNode<T>> impl;

public:
    binary_search_tree() = default;
    binary_search_tree(const binary_search_tree& other) = default;
    binary_search_tree& operator=(const binary_search_tree& other) = default;
    binary_search_tree(binary_search_tree&&) noexcept = default;
    binary_search_tree& operator=(binary_search_tree&&) noexcept = default;

    binary_search_tree(const std::vector<T>& values) {
        *this = values;
    }

    binary_search_tree(const std::initializer_list<T>& init_list) {
        *this = init_list;
    }

    binary_search_tree& operator=(const std::vector<T>& values) {
        impl = values;
        return *this;
    }

    binary_search_tree& operator=(const std::initializer_list<T>& init_list) {
        return operator=(std::vector<T>(init_list));
    }

    bool operator==(const binary_search_tree& other) const {
        return impl == other.impl;
    }

    bool operator!=(const binary_search_tree& other) const {
        return !(*this == other);
    }

    // Controlled API
    bool insert(const T& value) {
        return impl.insert(value);
    }

    bool erase(const T& value) {
        return impl.remove(value);
    }

    bool contains(const T& value) const {
        return impl.contains(value);
    }
    

    static binary_search_tree build_from_sorted(const std::vector<T>& sorted, int start = 0, int end = -1) {
    binary_search_tree bst;

    if (sorted.empty()) return bst;

    start = std::max(0, start);
    end = (end == -1) ? sorted.size() - 1 : std::min((int)sorted.size() - 1, end);

    if (start > end) return bst;

    bst.impl = detail::BinarySearchTree<T, detail::TreeNode<T>>::build_from_sorted(sorted, start, end);

    return bst;

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

#endif // BINARY_SEARCH_TREES_H