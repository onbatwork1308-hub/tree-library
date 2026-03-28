#ifdef __INTELLISENSE__
#include "BinaryNode.h"
#endif
namespace detail {

    template<typename T, typename NodeType>
    BinaryNode<T, NodeType>::BinaryNode() : data(), left(nullptr), right(nullptr) {}

    template<typename T, typename NodeType>
    BinaryNode<T, NodeType>::BinaryNode(const T& value) : data(value), left(nullptr), right(nullptr) {}

    template<typename T, typename NodeType>
    BinaryNode<T, NodeType>::BinaryNode(const T& value, Node* left, Node* right) : data(value), left(left), right(right) {}

    template<typename T, typename NodeType>
    bool BinaryNode<T, NodeType>::isLeaf() const {
        return (this->left == nullptr && this->right == nullptr);
    }

    template<typename T, typename NodeType>
    NodeType* BinaryNode<T, NodeType>::clone() const {
        NodeType* newNode = new NodeType(this->data);
        if (this->left) {
            newNode->left = this->left->clone();
        }
        if (this->right) {
            newNode->right = this->right->clone();
        }
        return newNode;
    }

} // namespace detail
