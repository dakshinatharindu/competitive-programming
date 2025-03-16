#pragma once

#include <string>

enum Color { RED, BLACK };

struct Node {
    std::string plateNum;
    unsigned int revenue;
    Color color;
    Node *left, *right, *parent;

    Node(std::string plateNum) : plateNum(plateNum) {
        parent = left = right = nullptr;
        color = RED;
    }
};

class RedBlackTree {
   private:
    Node *root;

    // Helper functions for red-black tree properties
    std::string randomPlate();
    void LLRotation(Node *&node);
    void RRRotation(Node *&node);
    void fixInsertion(Node *&newPlate);

   public:
    RedBlackTree();
    ~RedBlackTree();
    bool addLicense(std::string plateNum);
    void addLicense();
    void dropLicense(std::string plateNum);
    void lookupLicense(std::string plateNum);
    void lookupPrev(std::string plateNum);
    void lookupNext(std::string plateNum);
    void lookupRange(std::string lo, std::string hi);
    void revenue();
    void quit();
};
