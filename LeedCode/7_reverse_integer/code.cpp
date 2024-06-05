#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int reverse(int x) {
        int reverse_x = 0;
        int digits = 0;

        while (x != 0) {
            reverse_x = reverse_x * 10 + (x % 10);
            digits++;
            x = x / 10;
        }

        return reverse_x;
    }
};

int main() {
    Solution s;
    cout << s.reverse(2147483641) << endl;
}