#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "TreeNode.h"
#include "BinaryTrees.h"

namespace detail {
    template<typename T, typename NodeType = TreeNode<T>>
    class BinarySearchTree : public Tree<T, NodeType> {
    public:
        BinarySearchTree();
        ~BinarySearchTree();

        virtual bool insert(const T& value);
        virtual bool remove(const T& value);
        bool contains(const T& value) const;

    private:
        // Helper functions for insertion, searching, and removal
        bool searchNode(NodeType* node, const T& value) const;
        bool insertNode(NodeType*& node, const T& value);
        bool deleteNode(NodeType*& node, const T& value);
    };
} //namespace detail

#include "BinarySearchTree.tpp"

#endif // BINARY_SEARCH_TREE_H