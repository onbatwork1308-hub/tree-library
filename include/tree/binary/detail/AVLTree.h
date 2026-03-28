#ifndef AVLTREE_H
#define AVLTREE_H
#include "AVLTreeNode.h"
#include "BinarySearchTree.h"

namespace detail {
    template<typename T>
    class AVLTree : public BinarySearchTree<T, AVLTreeNode<T>> {
    public:
        AVLTree();
        ~AVLTree();

        bool insert(const T& value) override;
        bool remove(const T& value) override;
        size_t height() const;

    private:

        size_t height(const AVLTreeNode<T>* node)const;

        bool insertNode(AVLTreeNode<T>*& node, const T& value);
        bool deleteNode(AVLTreeNode<T>*& node, const T& value);

        void balance(AVLTreeNode<T>*& node);
        void rotateRight(AVLTreeNode<T>*& x);
        void rotateLeft(AVLTreeNode<T>*& x);
    };
} //namespace detail

#include "AVLTree.tpp"

#endif // AVLTREE_H
