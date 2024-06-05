#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int reverse(int x) {
        int reverse_x = 0;
        int digits = 0;
        int temp;
        bool pos = (x > 0) ? true : false;

        while (x != 0) {
            if (pos) {
                if ((INT32_MAX / 10) < reverse_x) return 0;
            } else {
                if ((INT32_MIN / 10) > reverse_x) return 0;
            }

            reverse_x *= 10;
            temp = (x % 10);
            if (pos) {
                if ((INT32_MAX - reverse_x) < temp) return 0;
            } else {
                if ((INT32_MIN - reverse_x) > temp) return 0;
            }

            reverse_x = reverse_x + temp;
            digits++;
            x = x / 10;
        }

        return reverse_x;
    }
};

int main() {
    Solution s;
    cout << s.reverse(-123) << endl;
}