#ifndef BINARY_NODE_H
#define BINARY_NODE_H

#include <iostream>

namespace detail {
    template<typename T, typename NodeType>
    class BinaryNode {
    public:
        using Node = NodeType;
        T data;
        Node* left;
        Node* right;

        BinaryNode();
        BinaryNode(const T& value);
        BinaryNode(const T& value, Node* left, Node* right);

        virtual ~BinaryNode() = default;

        BinaryNode(const BinaryNode& other) = delete;
        BinaryNode& operator=(const BinaryNode& other) = delete;

        virtual Node* clone() const ;
        bool isLeaf() const;

    };
} // namespace detail

#include "BinaryNode.tpp"
#endif // BINARY_NODE_H