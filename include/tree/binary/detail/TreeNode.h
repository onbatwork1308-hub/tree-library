#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "BinaryNode.h"
namespace detail {
template<typename T>
    class TreeNode : public BinaryNode<T, TreeNode<T>> {
    public:
        using BinaryNode<T, TreeNode<T>>::BinaryNode;

        ~TreeNode() = default;
        
        TreeNode(const TreeNode& other) = delete;
        TreeNode& operator=(const TreeNode& other) = delete;

    };
} // namespace detail
#endif // TREE_NODE_H