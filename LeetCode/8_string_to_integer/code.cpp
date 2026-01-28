#include <cstdint>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class Solution {
public:
  int myAtoi(string s) {
    bool sign = true;
    bool start = false;
    vector<int> nums;

    for (char &c : s) {
      if (c == ' ' && !start) {
        continue;
      } else if (c == '-' && !start) {
        sign = false;
        start = true;
        continue;
      } else if (c == '+' && !start) {
        start = true;
        continue;
      } else if (((int)c >= 48) && ((int)c <= 57)) {
        if (!start)
          start = true;
        nums.push_back((int)c);
      } else {
        break;
      }
    }
    int out = 0;
    for (int a : nums) {
      a = a - 48;
      a = sign ? a : -a;
      if (sign && INT32_MAX / 10 < out) {
        return INT32_MAX;
      }
      if (!sign && INT32_MIN / 10 > out) {
        return INT32_MIN;
      }
      out = out * 10;
      if (sign && INT32_MAX - a < out) {
        return INT32_MAX;
      }
      if (!sign && INT32_MIN - a > out) {
        return INT32_MIN;
      }
      out = out + a;
    }
    return out;
  }
};

int main() {
  Solution s;
  cout << s.myAtoi("42") << endl;
}
