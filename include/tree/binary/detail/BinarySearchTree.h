#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BinaryTrees.h"

namespace detail {
    template<typename T, typename NodeType = TreeNode<T>>
    class BinarySearchTree : public Tree<T, NodeType> {
    public:
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree& other);
        BinarySearchTree(const std::vector<T>& values);
        BinarySearchTree(const std::initializer_list<T>& init_list);
        ~BinarySearchTree();

        virtual bool insert(const T& value);
        virtual bool remove(const T& value);
        bool contains(const T& value) const;

        BinarySearchTree<T, NodeType> build_from_sorted(const std::vector<T>& sorted, int start = 0, int end = -1);
        BinarySearchTree<T, NodeType>& operator=(const std::vector<T>& values);
        BinarySearchTree<T, NodeType>& operator=(const BinarySearchTree& other);
        BinarySearchTree<T, NodeType>& operator=(const std::initializer_list<T>& init_list);

    private:
        // Helper functions for insertion, searching, and removal
        bool searchNode(NodeType* node, const T& value) const;
        bool insertNode(NodeType*& node, const T& value);
        bool deleteNode(NodeType*& node, const T& value);
        NodeType* build_from_sorted_nodes(const std::vector<T>& sorted, int start, int end);
    };
} //namespace detail

#include "BinarySearchTree.tpp"

#endif // BINARY_SEARCH_TREE_H