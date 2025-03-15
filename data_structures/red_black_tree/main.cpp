#include <iostream>
#include "red_black_tree.h"

int main() {
    RedBlackTree rbt;

    std::string s1 = "9A";
    std::string s2 = "A9";

    bool comp = s1 < s2;
    std::cout << "Is " << s1 << " < " << s2 << "? " << (comp ? "true" : "false") << std::endl;
}