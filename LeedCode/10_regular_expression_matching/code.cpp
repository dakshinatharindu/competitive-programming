#include <iostream>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int i = 0, j = 0;
    for (char &c : p) {
      i++;
    }

    return true;
  }
};

int main() {
  Solution s;
  cout << s.isMatch("aa", "a.");
}
