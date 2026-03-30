#ifdef __INTELLISENSE__
#include "AVLTreeNode.h"
#endif

namespace detail {

    template<typename T>
    AVLTreeNode<T>::AVLTreeNode() : BinaryNode<T, AVLTreeNode<T>>(), height(1) {}

    template<typename T>
    AVLTreeNode<T>::AVLTreeNode(const T &value) : BinaryNode<T, AVLTreeNode<T> >(value), height(1) {}

    template<typename T>
    AVLTreeNode<T>::AVLTreeNode(const T &value, AVLTreeNode *left, AVLTreeNode *right)
        : BinaryNode<T, AVLTreeNode<T>>(value, left, right), height(1) {}

    template<typename T>
    size_t AVLTreeNode<T>::getHeight() const { return height; }

    template<typename T>
    void AVLTreeNode<T>::setHeight(size_t h) { height = h; }

    template<typename T>
    int AVLTreeNode<T>::getBalance() const {
        int leftHeight = this->left ? this->left->getHeight() : 0;
        int rightHeight = this->right ? this->right->getHeight() : 0;
        return leftHeight - rightHeight;
    }

    template<typename T>
    AVLTreeNode<T>* AVLTreeNode<T>::clone() const {
        AVLTreeNode<T>* newNode = new AVLTreeNode<T>(this->data);
        newNode->setHeight(this->getHeight());
        if (this->left) {
            newNode->left = this->left->clone();
        }
        if (this->right) {
            newNode->right = this->right->clone();
        }
        return newNode;
    }

}//namespace detail