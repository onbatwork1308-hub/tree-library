#ifdef __INTELLISENSE__
#include "BinarySearchTree.h"
#endif

#include <algorithm>
#include <vector>
#include <utility>

namespace detail {

    template<typename T, typename NodeType>
    BinarySearchTree<T, NodeType>::BinarySearchTree() : Tree<T, NodeType>() {}

    template<typename T, typename NodeType>
    BinarySearchTree<T, NodeType>::BinarySearchTree(const BinarySearchTree& other) {
        if (this != &other) {
            this->root = other.root ? other.root->clone() : nullptr;
        }
    }

    template<typename T, typename NodeType>
    BinarySearchTree<T, NodeType>::BinarySearchTree(const std::vector<T>& values) {
        *this = values;
    }

    template<typename T, typename NodeType>
    BinarySearchTree<T, NodeType>::BinarySearchTree(const std::initializer_list<T>& init_list) {
        *this = init_list;
    }

    template<typename T, typename NodeType>
    BinarySearchTree<T, NodeType>::~BinarySearchTree(){}

    template<typename T, typename NodeType>
    BinarySearchTree<T, NodeType>& BinarySearchTree<T, NodeType>::operator=(const BinarySearchTree& other) {
        this->deleteTree();
        this->root = other.root ? other.root->clone() : nullptr;
        return *this;
    }

    template<typename T, typename NodeType>
    BinarySearchTree<T, NodeType>& BinarySearchTree<T, NodeType>::operator=(const std::vector<T>& values) {

        BinarySearchTree<T, NodeType> temp;

        std::vector<T> sortedValues = values;
        std::sort(sortedValues.begin(), sortedValues.end());

        sortedValues.erase(
            std::unique(sortedValues.begin(), sortedValues.end()),
            sortedValues.end()
        );

        temp.root = build_from_sorted_nodes(sortedValues, 0, sortedValues.size() - 1);

        std::swap(this->root, temp.root);
        
        return *this;
    }

    template<typename T, typename NodeType>
    BinarySearchTree<T, NodeType>& BinarySearchTree<T, NodeType>::operator=(const std::initializer_list<T>& init_list) {
        return operator=(std::vector<T>(init_list));
    }

    template<typename T, typename NodeType>
    BinarySearchTree<T, NodeType> BinarySearchTree<T, NodeType>::build_from_sorted(const std::vector<T>& sorted, int start, int end) {
        BinarySearchTree<T, NodeType> bst;
        if(sorted.empty()) return bst;

        start = std::max(0, start);
        end = std::min(static_cast<int>(sorted.size()) - 1, end);

        if (start > end) return bst;

        auto sortedValues = sorted;
        sortedValues.erase(
            std::unique(sortedValues.begin(), sortedValues.end()),
            sortedValues.end()
        );
        bst.root = build_from_sorted_nodes(sortedValues, start, end);
        return bst;
    }

    template<typename T, typename NodeType>
    NodeType* BinarySearchTree<T, NodeType>::build_from_sorted_nodes(const std::vector<T>& sorted, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        NodeType* node = new NodeType(sorted[mid]);
        node->left = build_from_sorted_nodes(sorted, start, mid - 1);
        node->right = build_from_sorted_nodes(sorted, mid + 1, end);
        return node;
    }

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
