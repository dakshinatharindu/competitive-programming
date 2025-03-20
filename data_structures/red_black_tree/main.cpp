#include <iostream>
#include "red_black_tree.h"

int main() {
    RedBlackTree rbt;

    rbt.addLicense("0010");
    rbt.printTree();
    rbt.addLicense("0007");
    rbt.printTree();
    rbt.addLicense("0040");
    rbt.printTree();
    rbt.addLicense("0003");
    rbt.printTree();
    rbt.dropLicense("0040");
    rbt.printTree();
}