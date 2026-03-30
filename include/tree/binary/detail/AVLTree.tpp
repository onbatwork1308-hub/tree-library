#ifdef __INTELLISENSE__
#include "AVLTree.h"
#endif
namespace detail {
    template<typename T>
    AVLTree<T>::AVLTree() {}

    template<typename T>
    AVLTree<T>::AVLTree(const AVLTree& other) {
        if (this != &other) {
            this->root = other.root ? other.root->clone() : nullptr;
        }
    }

    template<typename T>
    AVLTree<T>::AVLTree(const std::vector<T>& values) {
        *this = values;
    }

    template<typename T>
    AVLTree<T>::AVLTree(const std::initializer_list<T>& init_list) {
        *this = init_list;
    }

    template<typename T>
    AVLTree<T>::~AVLTree() {}

    template<typename T>
    size_t AVLTree<T>::height() const {
        return height(this->root);
    }

    template<typename T>
    size_t AVLTree<T>::height(const AVLTreeNode<T>* node) const {
        return node ? node->getHeight() : 0;
    }

    template<typename T>
    AVLTree<T> AVLTree<T>::build_from_sorted(const std::vector<T>& sorted, int start, int end) {
        AVLTree<T> avlTree;

        if (sorted.empty()) return avlTree;

        start = std::max(0, start);
        end = std::min(static_cast<int>(sorted.size()) - 1, end);

        if(start > end) return avlTree;

        auto sortedValues = sorted;
        sortedValues.erase(
            std::unique(sortedValues.begin(), sortedValues.end()),
            sortedValues.end()
        );

        avlTree.root = build_from_sorted_nodes(sortedValues, start, end);
        return avlTree;
    }

    template<typename T>
    AVLTreeNode<T>* AVLTree<T>::build_from_sorted_nodes(const std::vector<T>& sorted, int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        AVLTreeNode<T>* node = new AVLTreeNode<T>(sorted[mid]);

        node->left = build_from_sorted_nodes(sorted, start, mid - 1);
        node->right = build_from_sorted_nodes(sorted, mid + 1, end);

        node->setHeight(1 + std::max(height(node->left), height(node->right)));
        return node;
    }

    template<typename T>
    AVLTree<T>& AVLTree<T>::operator=(const std::vector<T>& values) {
        AVLTree<T> temp;

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

    template<typename T>
    AVLTree<T>& AVLTree<T>::operator=(const AVLTree<T>& other) {
        if (this != &other) {
            this->root = other.root ? other.root->clone() : nullptr;
        }
        return *this;
    }

    template<typename T>
    AVLTree<T>& AVLTree<T>::operator=(const std::initializer_list<T>& init_list) {
        return operator=(std::vector<T>(init_list));
    }

    template<typename T>
    bool AVLTree<T>::insert(const T& value) {
        return this->insertNode(this->root, value);
    }

    template<typename T>
    bool AVLTree<T>::remove(const T& value) {
        return this->deleteNode(this->root, value);
    }

    template<typename T>
    bool AVLTree<T>::insertNode(AVLTreeNode<T>*& node, const T& value) {
        bool status = true;
        if(node) {
            if(value < node->data) status = insertNode(node->left, value);
            else if(node->data < value) status = insertNode(node->right, value);
            else status = false;

            if(status == true) {
                node->setHeight(1 + std::max(height(node->left), height(node->right)));
                balance(node);
            }
        }
        else {
            node = new AVLTreeNode<T>(value);
            status = true;
        }
        return status;
    }

    template <typename T>
    bool AVLTree<T>::deleteNode(AVLTreeNode<T>*& node, const T& value) {
        bool status = false;
        if(node) {
            if(node->data == value) {
                if(node->isLeaf()) {
                    delete node;
                    node = nullptr;
                } 
                else if(node->left == nullptr) {
                    AVLTreeNode<T>* toDelete = node;
                    node = node->right;
                    toDelete->right = nullptr;
                    delete toDelete;
                }
                else if(node->right == nullptr) {
                    AVLTreeNode<T>* toDelete = node;
                    node = node->left;
                    toDelete->left = nullptr;
                    delete toDelete;
                }
                else {
                    AVLTreeNode<T>* parentSucc = node;
                    AVLTreeNode<T>* succ = node->right;
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
            else if(value < node->data) status = deleteNode(node->left, value);
            else status = deleteNode(node->right, value);

            if(node && status == true) {
                node->setHeight(1 + std::max(height(node->left), height(node->right)));
                balance(node);
            }
        }
        return status;
    }

    template <typename T>
    void AVLTree<T>::balance(AVLTreeNode<T>*& node) {
        if(node) {
            int bf = node->getBalance();
            if(bf > 1) {
                if(node->left && node->left->getBalance() < 0) rotateLeft(node->left);
                rotateRight(node);
            }
            else if(bf < -1) {
                if(node->right && node->right->getBalance() > 0) rotateRight(node->right);
                rotateLeft(node);
            }
        }
    }

    template <typename T>
    void AVLTree<T>::rotateLeft(AVLTreeNode<T>*& x) {
        if(x && x->right) {
            AVLTreeNode<T>* y = x->right;
            x->right = y->left;
            y->left = x;

            x->setHeight(1 + std::max(height(x->left),height(x->right)));
            y->setHeight(1 + std::max(height(y->left), height(y->right)));
            x = y;
        }
    }

    template<typename T>
    void AVLTree<T>::rotateRight(AVLTreeNode<T>*& x) {
        if(x && x->left) {
            AVLTreeNode<T>* y = x->left;
            x->left = y->right;
            y->right = x;

            x->setHeight(1 + std::max(height(x->left), height(x->right)));
            y->setHeight(1 + std::max(height(y->left), height(y->right)));
            x = y;        
        }
    }

} //namespace detail