#include "red_black_tree.h"

#include <functional>
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////
// Public member functions
//////////////////////////////////////////////////////////////////////////////////
RedBlackTree::RedBlackTree() : root(nullptr), totalRevenue(0) {}

RedBlackTree::~RedBlackTree() {
    delete root;  // Destructor to clean up the tree
}

std::string RedBlackTree::addLicense() {
    std::string plateNum;

    do {
        plateNum = randomPlate();
    } while (!insertLicense(plateNum, false));
    return plateNum;
}

bool RedBlackTree::addLicense(std::string plateNum) { return insertLicense(plateNum, true); }

bool RedBlackTree::insertLicense(std::string plateNum, bool customized) {
    Node* newPlate = new Node(plateNum);
    newPlate->customized = customized;
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
    if (customized) {
        totalRevenue += 7;
    } else {
        totalRevenue += 4;
    }
    return true;
}

bool RedBlackTree::dropLicense(std::string plateNum) {
    Node* z = nullptr;
    Node *x, *y;
    Node* node = root;

    // Find the node with the key
    while (node != nullptr) {
        if (node->plateNum == plateNum) {
            z = node;
            break;
        }

        if (node->plateNum < plateNum)
            node = node->right;
        else
            node = node->left;
    }

    if (z == nullptr) return false;  // Key not found

    y = z;
    Color y_original_color = y->color;
    Node* x_parent;

    if (z->left == nullptr) {
        x = z->right;
        x_parent = z->parent;
        transplant(z, z->right);
    } else if (z->right == nullptr) {
        x = z->left;
        x_parent = z->parent;
        transplant(z, z->left);
    } else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;

        if (y->parent == z) {
            x_parent = y;
            if (x != nullptr) x->parent = y;
        } else {
            x_parent = y->parent;
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if (y_original_color == BLACK && x_parent != nullptr) {
        fixDeletion(x, x_parent);
    }

    if (z->customized) {
        totalRevenue -= 7;  // Adjust revenue for customized plates
    } else {
        totalRevenue -= 4;  // Adjust revenue for standard plates
    }
    delete z;

    return true;  // License plate removed successfully
}

bool RedBlackTree::lookupLicense(std::string plateNum) {
    Node* node = root;

    while (node != nullptr) {
        if (node->plateNum == plateNum) {
            return true;  // License plate found
        }
        if (node->plateNum < plateNum) {
            node = node->right;
        } else {
            node = node->left;
        }
    }
    return false;  // License plate not found
}

std::string RedBlackTree::lookupPrev(std::string plateNum) {
    Node* node = root;
    Node* prev = nullptr;

    while (node != nullptr) {
        if (node->plateNum < plateNum) {
            prev = node;  // Update prev to current node
            node = node->right;
        } else {
            node = node->left;
        }
    }

    return (prev != nullptr) ? prev->plateNum : "";  // Return previous plate number or empty string
}

std::string RedBlackTree::lookupNext(std::string plateNum) {
    Node* node = root;
    Node* next = nullptr;

    while (node != nullptr) {
        if (node->plateNum > plateNum) {
            next = node;  // Update next to current node
            node = node->left;
        } else {
            node = node->right;
        }
    }

    return (next != nullptr) ? next->plateNum : "";  // Return next plate number or empty string
}

std::vector<std::string> RedBlackTree::lookupRange(std::string lo, std::string hi) {
    std::vector<std::string> result;
    Node* node = root;

    // In-order traversal to find all plates in the range [lo, hi]
    std::function<void(Node*)> inOrder = [&](Node* node) {
        if (node != nullptr) {
            if (node->plateNum >= lo && node->plateNum <= hi) {
                result.push_back(node->plateNum);
            }
            inOrder(node->left);
            inOrder(node->right);
        }
    };
    inOrder(node);

    return result;  // Return the vector of plate numbers in the range
}

int RedBlackTree::revenue() {
    return totalRevenue;
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

void RedBlackTree::fixDeletion(Node*& x, Node*& x_parent) {
    Node* s;

    while (x != root && (x == nullptr || x->color == BLACK)) {
        if (x == x_parent->left) {
            s = x_parent->right;

            if (s->color == RED) {
                // Case 1: s is red
                s->color = BLACK;
                x_parent->color = RED;
                RRRotation(x_parent);
                s = x_parent->right;
            }

            if ((s->left == nullptr || s->left->color == BLACK) &&
                (s->right == nullptr || s->right->color == BLACK)) {
                // Case 2: s is black, and both of s's children are black
                s->color = RED;
                x = x_parent;
                x_parent = x->parent;
            } else {
                if (s->right == nullptr || s->right->color == BLACK) {
                    // Case 3: s is black, s's left child is red, s's right child is black
                    if (s->left != nullptr) s->left->color = BLACK;
                    s->color = RED;
                    LLRotation(s);
                    s = x_parent->right;
                }

                // Case 4: s is black, s's right child is red
                s->color = x_parent->color;
                x_parent->color = BLACK;
                if (s->right != nullptr) s->right->color = BLACK;
                RRRotation(x_parent);
                x = root;
            }
        } else {
            s = x_parent->left;

            if (s->color == RED) {
                // Case 1: s is red
                s->color = BLACK;
                x_parent->color = RED;
                LLRotation(x_parent);
                s = x_parent->left;
            }

            if ((s->right == nullptr || s->right->color == BLACK) &&
                (s->left == nullptr || s->left->color == BLACK)) {
                // Case 2: s is black, and both of s's children are black
                s->color = RED;
                x = x_parent;
                x_parent = x->parent;
            } else {
                if (s->left == nullptr || s->left->color == BLACK) {
                    // Case 3: s is black, s's right child is red, s's left child is black
                    if (s->right != nullptr) s->right->color = BLACK;
                    s->color = RED;
                    RRRotation(s);
                    s = x_parent->left;
                }

                // Case 4: s is black, s's left child is red
                s->color = x_parent->color;
                x_parent->color = BLACK;
                if (s->left != nullptr) s->left->color = BLACK;
                LLRotation(x_parent);
                x = root;
            }
        }
    }

    if (x != nullptr) x->color = BLACK;
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

void RedBlackTree::printTree() {
    // In-order traversal to print the tree for debugging
    std::function<void(Node*)> inOrder = [&](Node* node) {
        if (node != nullptr) {
            inOrder(node->left);
            std::cout << node->plateNum << " (" << (node->color == RED ? "R" : "B") << ") ";
            inOrder(node->right);
        }
    };
    inOrder(root);
    std::cout << std::endl;
}

void RedBlackTree::transplant(Node*& u, Node*& v) {
    if (u->parent == nullptr)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v != nullptr) v->parent = u->parent;
}

Node* RedBlackTree::minimum(Node* node) {
    while (node->left != nullptr) node = node->left;
    return node;
}