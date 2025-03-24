#pragma once

#include <string>
#include <vector>

enum Color { RED, BLACK };

struct Node {
    std::string plateNum;
    Color color;
    Node *left, *right, *parent;
    bool customized = false;

    Node(std::string plateNum) : plateNum(plateNum) {
        parent = left = right = nullptr;
        color = RED;
    }
};

class RedBlackTree {
   private:
    Node *root;
    int totalRevenue;

    // Helper functions for red-black tree properties
    std::string randomPlate();
    void LLRotation(Node *&node);
    void RRRotation(Node *&node);
    void transplant(Node *&u, Node *&v);
    void fixInsertion(Node *&newPlate);
    void fixDeletion(Node *&x, Node *&x_parent);
    Node *maximum(Node *node);
    bool insertLicense(std::string plateNum, bool customized);

   public:
    RedBlackTree();
    ~RedBlackTree();
    bool addLicense(std::string plateNum);
    std::string addLicense();
    bool dropLicense(std::string plateNum);
    bool lookupLicense(std::string plateNum);
    std::string lookupPrev(std::string plateNum);
    std::string lookupNext(std::string plateNum);
    std::vector<std::string> lookupRange(std::string lo, std::string hi);
    int revenue();

    void printTree();  // For debugging purposes
};
