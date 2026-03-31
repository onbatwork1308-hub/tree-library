#include <tree/binary/binary_search_trees.h>
#include <tree/binary/avl_trees.h>
#include <iostream>
#include <vector>
#include <limits>

template<typename T>
void takeInputTree(T& tree) {
    std::cout << "Enter values to insert into the tree (enter ok to stop)" << std::endl;
    int value;
    while (std::cin >> value) {
        tree.insert(value);
    }
    std::cin.clear(); // Clear the error flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
}

void printTraversal(const std::vector<int>& values) {
    for (int value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

void printTraversal(const std::vector<std::vector<int>>& levels) {
    for (const auto& level : levels) {
        printTraversal(level);
    }
}
int main() {
    binary_search_tree<int> bst;
    avl_tree<int> avl;

    std::cout << "Dealing with Binary Search Tree" << std::endl;
    takeInputTree(bst);

    std::cout << "Height of BST: " << bst.height() << std::endl;
    std::cout << "Size of BST: " << bst.size() << std::endl;
    std::cout << "Number of Leaves in BST: " << bst.leaf_count() << std::endl;
    std::cout << "Number of Nodes with One Child in BST: " << bst.single_child_count() << std::endl;
    std::cout << "Number of Nodes with Two Children in BST: " << bst.double_child_count() << std::endl;

    std::cout << "Inorder Traversal of BST: ";
    printTraversal(bst.inorder());
    std::cout << std::endl;

    std::cout << "Preorder Traversal of BST: ";
    printTraversal(bst.preorder());
    std::cout << std::endl;

    std::cout << "Postorder Traversal of BST: ";
    printTraversal(bst.postorder());
    std::cout << std::endl;

    std::cout << "Level Order Traversal of BST: ";
    printTraversal(bst.levelorder());
    std::cout << std::endl;

    std::cout << "Vertical Order Traversal of BST: ";
    printTraversal(bst.vertical_order());
    std::cout << std::endl;

    std::cout <<"Enter value to be Searched and deleted form the tree: ";
    int value;
    std::cin >> value;
    if(bst.contains(value)) {
        std::cout << "Value found in the tree. Deleting..." << std::endl;
        bst.erase(value);
    } else {
        std::cout << "Value not found in the tree." << std::endl;
    }

    std::cout << "Dealing with AVL Tree" << std::endl;
    takeInputTree(avl);

    std::cout << "Height of AVL: " << avl.height() << std::endl;
    std::cout << "Size of AVL: " << avl.size() << std::endl;
    std::cout << "Number of Leaves in AVL: " << avl.leaf_count() << std::endl;
    std::cout << "Number of Nodes with One Child in AVL: " << avl.single_child_count() << std::endl;
    std::cout << "Number of Nodes with Two Children in AVL: " << avl.double_child_count() << std::endl;

    std::cout << "Inorder Traversal of AVL: ";
    printTraversal(avl.inorder());
    std::cout << std::endl;

    std::cout << "Preorder Traversal of AVL: ";
    printTraversal(avl.preorder());
    std::cout << std::endl;

    std::cout << "Postorder Traversal of AVL: ";
    printTraversal(avl.postorder());
    std::cout << std::endl;

    std::cout << "Level Order Traversal of AVL: ";
    printTraversal(avl.levelorder());
    std::cout << std::endl;

    std::cout << "Vertical Order Traversal of AVL: ";
    printTraversal(avl.vertical_order());
    std::cout << std::endl;

    std::cout <<"Enter value to be Searched and deleted form the tree: ";
    std::cin >> value;
    if(avl.contains(value)) {
        std::cout << "Value found in the tree. Deleting..." << std::endl;
        avl.erase(value);
    } else {
        std::cout << "Value not found in the tree." << std::endl;
    }

     return 0;
}
