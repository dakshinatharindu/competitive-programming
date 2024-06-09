#include <cstdint>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;

    int digits[11];
    int d = 0;

    while (x != 0 && d < 11) {
      digits[d] = (x % 10);
      x /= 10;
      d++;
    }
    for (int i = 0; i < (d / 2); i++) {
      if (digits[i] != digits[d - i - 1])
        return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isPalindrome(323);
}
