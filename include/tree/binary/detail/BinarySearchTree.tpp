#ifdef __INTELLISENSE__
#include "BinarySearchTree.h"
#endif
namespace detail {

    template<typename T, typename NodeType>
    BinarySearchTree<T, NodeType>::BinarySearchTree() : Tree<T, NodeType>() {}

    template<typename T, typename NodeType>
    BinarySearchTree<T, NodeType>::~BinarySearchTree(){}

    template<typename T, typename NodeType>
    bool BinarySearchTree<T, NodeType>::insert(const T& value) {
        return insertNode(this->root, value);
    }

    template<typename T, typename NodeType>
    bool BinarySearchTree<T, NodeType>::insertNode(NodeType*& node, const T& value) {
        bool status = true;
        if (node == nullptr) {
            node = new NodeType(value);
            status = true;
        }
        else if (value < node->data) {
            status = insertNode(node->left, value);
        } else if(node->data < value) {
            status = insertNode(node->right, value);
        } else status = false;
        return status;
    }

    template<typename T, typename NodeType>
    bool BinarySearchTree<T, NodeType>::searchNode(NodeType* node, const T& value) const {
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        }
        if (value < node->data) {
            return searchNode(node->left, value);
        } else {
            return searchNode(node->right, value);
        }
    }

    template<typename T, typename NodeType>
    bool BinarySearchTree<T, NodeType>::contains(const T& value) const {
        return searchNode(this->root, value);
    }

    template<typename T, typename NodeType>
    bool BinarySearchTree<T, NodeType>::deleteNode(NodeType*& node, const T& value) {
        bool status = false;
        if(node != nullptr) {
            if(node->data == value) {
                if(node->isLeaf()) {
                    delete node;
                    node = nullptr;
                }
                else if(node->left == nullptr) {
                    NodeType* temp = node;
                    node = node->right;
                    temp->right = nullptr;
                    delete temp;
                }
                else if(node->right == nullptr) {
                    NodeType* temp = node;
                    node = node->left;
                    temp->left = nullptr;
                    delete temp;
                }
                else {
                    NodeType* parentSucc = node;
                    NodeType* succ = node->right;
                    while(succ->left != nullptr) {
                        parentSucc = succ;
                        succ = succ->left;
                    }
                    if(parentSucc != node) {
                        parentSucc->left = succ->right;
                        succ->right = node->right;
                        succ->left = node->left;
                    } else {
                        succ->left = node->left;
                    }
                    node->left = nullptr;
                    node->right = nullptr;
                    delete node;
                    node = succ;
                }
                status = true;
            }
            else if(value < node->data) {
                status = deleteNode(node->left, value);
            }
            else {
                status = deleteNode(node->right, value);
            }
        }
        return status;
    }

    template<typename T, typename NodeType>
    bool BinarySearchTree<T, NodeType>::remove(const T& value) {
        return deleteNode(this->root, value);
    }

}
