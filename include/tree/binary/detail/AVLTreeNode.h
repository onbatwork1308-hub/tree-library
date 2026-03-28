#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H

#include "BinaryNode.h"

namespace detail {
    template<typename T>
    class AVLTree;

    template<typename T>
    class AVLTreeNode : public BinaryNode<T, AVLTreeNode<T>> {
    public:

        AVLTreeNode();
        AVLTreeNode(const T& value);
        AVLTreeNode(const T& value, AVLTreeNode* left, AVLTreeNode* right);

        ~AVLTreeNode() = default;

        AVLTreeNode(const AVLTreeNode& other) = delete;
        AVLTreeNode& operator=(const AVLTreeNode& other) = delete;

        size_t getHeight() const;
        int getBalance() const;

        private:

        friend class AVLTree<T>;
        
        size_t height;
        void setHeight(size_t h);
    };
}//namespace detail
#include "AVLTreeNode.tpp"
#endif // AVL_TREE_NODE_H