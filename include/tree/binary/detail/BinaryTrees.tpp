#ifdef __INTELLISENSE__
#include "BinaryTrees.h"
#endif

#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
namespace detail {
    template<typename T, typename NodeType>
    Tree<T, NodeType>::Tree() : root(nullptr) {}

    template<typename T, typename NodeType>
    Tree<T, NodeType>::Tree(NodeType* node){
        this->root = nullptr;
        if(node!= nullptr) {
            this->root = node->clone();
        }
    }

    template<typename T, typename NodeType>
    Tree<T, NodeType>::Tree(const Tree& other) : root(nullptr) {
        if (other.root != nullptr) {
            this->root = other.root->clone();
        }
    }

    template<typename T, typename NodeType>
    Tree<T, NodeType>::~Tree() {
        deleteTree(this->root);
        this->root = nullptr;
    }

    template<typename T, typename NodeType>
    void Tree<T, NodeType>::deleteTree(NodeType* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    template<typename T, typename NodeType>
    void Tree<T, NodeType>::deleteTree() {
        deleteTree(this->root);
        this->root = nullptr;
    }

    template<typename T, typename NodeType>
    bool Tree<T, NodeType>::operator==(const Tree& other) const {

        auto same = [&](auto&& self, NodeType* n1, NodeType* n2) -> bool {
            if (n1 == nullptr && n2 == nullptr) return true;
            if (n1 == nullptr || n2 == nullptr) return false;

            return (n1->data == n2->data) &&
                self(self, n1->left, n2->left) &&
                self(self, n1->right, n2->right);
        };

        return same(same, this->root, other.root);
    }

    template<typename T, typename NodeType>
    bool Tree<T, NodeType>::operator!=(const Tree& other) const {
        return !(*this == other);
    }

    template<typename T, typename NodeType>
    std::vector<T> Tree<T, NodeType>::inorder() const {
        std::vector<T> inorder;
        std::stack<NodeType*> st;
        NodeType* curr = this->root;
        while((curr != nullptr) || !st.empty()) {
            if(curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                curr = st.top();
                inorder.push_back(curr->data);
                st.pop();
                curr = curr->right;
            }
        }
        return inorder;
    }

    template<typename T, typename NodeType>
    std::vector<T> Tree<T, NodeType>::preorder() const {
        std::vector<T> preorder;
        std::stack<NodeType*> st;
        NodeType* curr = this->root;
        while((curr != nullptr) || !st.empty()) {
            if(curr != nullptr) {
                preorder.push_back(curr->data);
                st.push(curr);
                curr = curr->left;
            }
            else {
                curr = st.top();
                st.pop();
                curr = curr->right;
            }
        }
        return preorder;
    }

    template<typename T, typename NodeType>
    std::vector<T> Tree<T, NodeType>::postorder() const {
        std::vector<T> postorder;
        std::stack<NodeType*> st;
        NodeType* curr = this->root;
        while(curr || !st.empty()) {
            if(curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                NodeType* temp = st.top()->right;
                if(temp == nullptr) {
                    temp = st.top();
                    postorder.push_back(temp->data);
                    st.pop();
                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        postorder.push_back(temp->data);
                        st.pop();
                    }
                    
                }
                else {
                    curr = temp;
                }
            }
        }
        return postorder;
    }

    template<typename T, typename NodeType>
    std::vector<std::vector<T>> Tree<T, NodeType>::levelorder() const {
        std::vector<std::vector<T>> levelorder;
        if(this->root != nullptr) {
            std::queue<NodeType*> q;
            NodeType* curr = this->root;
            q.push(curr);
            while(!q.empty()) {
                int qSize = q.size();
                std::vector<T> level;
                for(int i = 0; i < qSize; i++) {
                    curr = q.front();
                    q.pop();
                    level.push_back(curr->data);
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
                levelorder.push_back(level);
            }
        }
        return levelorder;
    }


    template<typename T, typename NodeType>
    void Tree<T, NodeType>::verticalTraversal(NodeType* node, int colNo, int rowNo, std::map<int, std::multiset<std::pair<int, T>>> &mp) const {
        if(node == nullptr) return;
        mp[colNo].insert({rowNo, node->data});
        verticalTraversal(node->left, colNo - 1, rowNo + 1, mp);
        verticalTraversal(node->right, colNo + 1, rowNo + 1, mp);
    }

    template<typename T, typename NodeType>
    std::vector<std::vector<T>> Tree<T, NodeType>::verticalOrder() const {
        std::vector<std::vector<T>> verticalOrder;
        if(this->root != nullptr) {
            std::map<int, std::multiset<std::pair<int, T>>> mp;
            verticalTraversal(this->root, 0, 0, mp);
            for(auto& [colNo, nodes] : mp) {
                std::vector<T> colNodes;
                for(auto& [rowNo, value] : nodes) {
                    colNodes.push_back(value);
                }
                verticalOrder.push_back(colNodes);
            }
        }
        return verticalOrder;
    }

    template<typename T, typename NodeType>
    size_t Tree<T, NodeType>::getHeight(NodeType* node) const {
        if(node == nullptr) return 0;
        return 1 + std::max(getHeight(node->left), getHeight(node->right));
    }

    template<typename T, typename NodeType>
    size_t Tree<T, NodeType>::getHeight() const {
        return getHeight(this->root);
    }

    template<typename T, typename NodeType>
    size_t Tree<T, NodeType>::countNodes(NodeType* node) const {
        if(node == nullptr) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    template<typename T, typename NodeType>
    size_t Tree<T, NodeType>::numNodes() const {
        return countNodes(this->root);
    }

    template<typename T, typename NodeType>
    size_t Tree<T, NodeType>::countLeaves(NodeType* node) const {
        if(!node) return 0;
        if(!node->left && !node->right) return 1;
        return countLeaves(node->left) + countLeaves(node->right);
    }

    template<typename T, typename NodeType>
    size_t Tree<T, NodeType>::numLeaves() const {
        return countLeaves(this->root);
    }

    template<typename T, typename NodeType>
    size_t Tree<T, NodeType>::countOneChild(NodeType* node) const{
        if (!node) return 0;

        size_t count = 0;

        if ((node->left && !node->right) || (!node->left && node->right)) {
            count = 1;
        }

        return count 
            + countOneChild(node->left) 
            + countOneChild(node->right);
    }

    template<typename T, typename NodeType>
    size_t Tree<T, NodeType>::numNodesWithOneChild() const {
        return countOneChild(this->root);
    }

    template<typename T, typename NodeType>
    size_t Tree<T, NodeType>::countTwoChild(NodeType* node) const {
        if (!node) return 0;

        return (node->left && node->right ? 1 : 0)
            + countTwoChild(node->left)
            + countTwoChild(node->right);
    }

    template<typename T, typename NodeType>
    size_t Tree<T, NodeType>::numNodesWithTwoChildren() const {
        return countTwoChild(this->root);
    }
} // namespace detail