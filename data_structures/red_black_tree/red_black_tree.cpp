#include "red_black_tree.h"

#include <iostream>

//////////////////////////////////////////////////////////////////////////////////
// Public member functions
//////////////////////////////////////////////////////////////////////////////////
RedBlackTree::RedBlackTree() : root(nullptr) {}

RedBlackTree::~RedBlackTree() {
    delete root;  // Destructor to clean up the tree
}

void RedBlackTree::addLicense() {
    std::string plateNum;

    do {
        plateNum = randomPlate();
    } while (!addLicense(plateNum));
}

bool RedBlackTree::addLicense(std::string plateNum) {
    Node* newPlate = new Node(plateNum);
    Node* parent = nullptr;
    Node* current = root;

    while (current != nullptr) {
        parent = current;
        if (newPlate->plateNum < current->plateNum) {
            current = current->left;
        } else if (newPlate->plateNum > current->plateNum) {
            current = current->right;
        } else {
            delete newPlate;  // Duplicate plate number, do not add
            return false;
        }
    }
    newPlate->parent = parent;
    if (parent == nullptr) {
        root = newPlate;  // Tree was empty
    } else if (newPlate->plateNum < parent->plateNum) {
        parent->left = newPlate;
    } else {
        parent->right = newPlate;
    }

    fixInsertion(newPlate);  // Fix the red-black tree properties
    return true;
}

bool RedBlackTree::dropLicense(std::string plateNum) {
    Node* current = root;
    while (current != nullptr) {
        if (plateNum < current->plateNum) {
            current = current->left;
        } else if (plateNum > current->plateNum) {
            current = current->right;
        } else {
            break;
        }
    }
    if (current == nullptr) {
        return false;  // License plate not found
    }

    Node *y, *py;
    Color removeColor;
    // Case 1: Node to be deleted has no children (leaf node)
    if (current->left == nullptr && current->right == nullptr) {
        if (current == root) {
            delete current;
            root = nullptr;  // Tree is now empty
            return true;
        }
        if (current->parent->left == current) {
            current->parent->left = nullptr;
        } else {
            current->parent->right = nullptr;
        }
        removeColor = current->color;
        y = nullptr;
        py = current->parent;

        delete current;  // Delete the leaf node
    } else if (current->left == nullptr || current->right == nullptr) {
        // Case 2: Node to be deleted has one child
        y = (current->left != nullptr) ? current->left : current->right;
        if (current == root) {
            root = y;
            return true;
        }
        if (current->parent->left == current) {
            current->parent->left = y;
        } else {
            current->parent->right = y;
        }
        removeColor = current->color;
        y->parent = current->parent;
        py = current->parent;

        delete current;  // Delete the node with one child
    } else {
        // Case 3: Node to be deleted has two children
        // Find the in-order predecessor (max of left subtree)
        Node* pred = current->left;
        while (pred->right != nullptr) {
            pred = pred->right;
        }
        // Swap the values of current and pred
        current->plateNum = pred->plateNum;
        removeColor = pred->color;  // Store the color of the predecessor
        // Now we need to delete the predecessor
        y = (pred->left != nullptr) ? pred->left : nullptr;

        if (pred->parent->left == pred) {
            pred->parent->left = y;
        } else {
            pred->parent->right = y;
        }
        if (y != nullptr) {
            y->parent = pred->parent;
        }
        py = pred->parent;
        delete pred;  // Delete the predecessor
    }
    // Fix the red-black tree properties after deletion
    if (removeColor == BLACK) {
        fixDeletion(y, py);  // Fix the tree if we removed a black node
    }
    return true;
}

//////////////////////////////////////////////////////////////////////////////////
// Private member functions
//////////////////////////////////////////////////////////////////////////////////
std::string RedBlackTree::randomPlate() {
    std::string plateNum;
    // Generate a random license plate number with 4 charaters including A-Z and 0-9
    for (int i = 0; i < 4; ++i) {
        int rand = std::rand() % 36;  // 26 letters + 10 digits
        if (rand < 26) {
            plateNum += 'A' + rand;  // A-Z
        } else {
            plateNum += '0' + (rand - 26);  // 0-9
        }
    }
    return plateNum;
}

void RedBlackTree::fixInsertion(Node*& newPlate) {
    Node* parent = nullptr;
    Node* grandparent = nullptr;
    while ((newPlate != root) && (newPlate->color == RED) && (newPlate->parent->color == RED)) {
        parent = newPlate->parent;
        grandparent = parent->parent;

        if (parent == grandparent->left) {
            Node* d = grandparent->right;
            if (d != nullptr && d->color == RED) {
                // Case LYr: d is red
                grandparent->color = RED;
                parent->color = BLACK;
                d->color = BLACK;
                newPlate = grandparent;  // Move up the tree
            } else {
                // Case LYb: d is black
                if (newPlate == parent->right) {
                    RRRotation(parent);         // Case 2a: newPlate is right child
                    newPlate = parent;          // Update newPlate to parent
                    parent = newPlate->parent;  // Update parent
                }
                // Case 2b: newPlate is left child
                LLRotation(grandparent);
                std::swap(parent->color,
                          grandparent->color);  // Swap colors
                newPlate = parent;
            }
        } else {
            Node* d = grandparent->left;
            if (d != nullptr && d->color == RED) {
                // Case RYr: d is red
                grandparent->color = RED;
                parent->color = BLACK;
                d->color = BLACK;
                newPlate = grandparent;  // Move up the tree
            } else {
                // Case RYb: d is black
                if (newPlate == parent->left) {
                    LLRotation(parent);         // Case 2a: newPlate is left child
                    newPlate = parent;          // Update newPlate to parent
                    parent = newPlate->parent;  // Update parent
                }
                // Case 2b: newPlate is right child
                RRRotation(grandparent);
                std::swap(parent->color,
                          grandparent->color);  // Swap colors
                newPlate = parent;
            }
        }
    }
    root->color = BLACK;  // Ensure the root is always black
}

void RedBlackTree::fixDeletion(Node*& y, Node*& py) {
}

void RedBlackTree::LLRotation(Node*& node) {
    Node* temp = node->left;
    node->left = temp->right;
    if (temp->right != nullptr) {
        temp->right->parent = node;
    }
    temp->parent = node->parent;
    if (node->parent == nullptr) {
        root = temp;  // Update root
    } else if (node == node->parent->left) {
        node->parent->left = temp;
    } else {
        node->parent->right = temp;
    }
    temp->right = node;
    node->parent = temp;
}

void RedBlackTree::RRRotation(Node*& node) {
    Node* temp = node->right;
    node->right = temp->left;
    if (temp->left != nullptr) {
        temp->left->parent = node;
    }
    temp->parent = node->parent;
    if (node->parent == nullptr) {
        root = temp;  // Update root
    } else if (node == node->parent->left) {
        node->parent->left = temp;
    } else {
        node->parent->right = temp;
    }
    temp->left = node;
    node->parent = temp;
}