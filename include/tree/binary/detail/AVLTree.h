#ifndef AVLTREE_H
#define AVLTREE_H
#include "AVLTreeNode.h"
#include "BinarySearchTree.h"

namespace detail {
    template<typename T>
    class AVLTree : public BinarySearchTree<T, AVLTreeNode<T>> {
    public:
        AVLTree();
        AVLTree(const AVLTree& other);
        AVLTree(const std::vector<T>& values);
        AVLTree(const std::initializer_list<T>& init_list);
        ~AVLTree();

        size_t height() const;
        bool insert(const T& value) override;
        bool remove(const T& value) override;

        AVLTree<T> build_from_sorted(const std::vector<T>& sorted, int start = 0, int end = -1);
        AVLTree<T>& operator=(const std::vector<T>& values);
        AVLTree<T>& operator=(const AVLTree<T>& other);
        AVLTree<T>& operator=(const std::initializer_list<T>& init_list);

    private:

        size_t height(const AVLTreeNode<T>* node)const;

        bool insertNode(AVLTreeNode<T>*& node, const T& value);
        bool deleteNode(AVLTreeNode<T>*& node, const T& value);
        AVLTreeNode<T>* build_from_sorted_nodes(const std::vector<T>& sorted, int start, int end);

        void balance(AVLTreeNode<T>*& node);
        void rotateRight(AVLTreeNode<T>*& x);
        void rotateLeft(AVLTreeNode<T>*& x);
    };
} //namespace detail

#include "AVLTree.tpp"

#endif // AVLTREE_H
