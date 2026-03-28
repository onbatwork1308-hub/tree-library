#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "TreeNode.h"

namespace detail {
    template<typename T, typename NodeType = TreeNode<T>>
    class Tree {
    protected:
        NodeType* root;
    private:
        size_t getHeight(NodeType* node) const;

        size_t countNodes(NodeType* node) const;
        size_t countLeaves(NodeType* node) const;
        size_t countOneChild(NodeType* node) const;
        size_t countTwoChild(NodeType* node) const;


        void verticalTraversal(NodeType* node, int colNo, int rowNo, std::map<int, std::multiset<std::pair<int, T>>> &mp) const;

        void deleteTree(NodeType* node);

    public:
        Tree();
        Tree(NodeType* root);
        Tree(const Tree& other) = delete;
        Tree& operator=(const Tree& other) = delete;
        ~Tree();

        std::vector<T> inorder() const;
        std::vector<T> preorder() const;
        std::vector<T> postorder() const;
        std::vector<std::vector<T>> levelorder() const;
        std::vector<std::vector<T>> verticalOrder() const;

        size_t getHeight() const;
        size_t numNodes() const;
        size_t numLeaves() const;
        size_t numNodesWithOneChild() const;
        size_t numNodesWithTwoChildren() const;
        void deleteTree();

    };

} // namespace detail

#include "BinaryTrees.tpp"
#endif // BINARY_TREES_H