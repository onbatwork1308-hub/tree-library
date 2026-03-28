#ifndef BINARY_SEARCH_TREES_H
#define BINARY_SEARCH_TREES_H

#include "detail/BinarySearchTree.h"

template<typename T>
class binary_search_tree {
private:
    detail::BinarySearchTree<T, detail::TreeNode<T>> impl;

public:
    binary_search_tree() = default;

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