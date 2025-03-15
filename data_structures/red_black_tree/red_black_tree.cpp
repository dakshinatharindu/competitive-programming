#include "red_black_tree.h"

#include <iostream>

RedBlackTree::RedBlackTree() : root(nullptr) {}

RedBlackTree::~RedBlackTree() {
    delete root;  // Destructor to clean up the tree
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

void RedBlackTree::fixInsertion(Node*& newPlate) {
    Node* parent = nullptr;
    Node* grandparent = nullptr;
    while ((newPlate != root) && (newPlate->color == RED) &&
           (newPlate->parent->color == RED)) {
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
                    RRRotation(parent);  // Case 2a: newPlate is right child
                    newPlate = parent;   // Update newPlate to parent
                    parent = newPlate->parent;  // Update parent
                }
                // Case 2b: newPlate is left child
                LLRotation(grandparent);
                std::swap(parent->color, grandparent->color);  // Swap colors
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
                    LLRotation(parent);  // Case 2a: newPlate is left child
                    newPlate = parent;   // Update newPlate to parent
                    parent = newPlate->parent;  // Update parent
                }
                // Case 2b: newPlate is right child
                RRRotation(grandparent);
                std::swap(parent->color, grandparent->color);  // Swap colors
                newPlate = parent;
            }
        }
    }
    root->color = BLACK;  // Ensure the root is always black
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