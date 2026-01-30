#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string multiply(string num1, string num2) {
        int num1_start = 0, num2_start = 0;
        while (num1[num1_start] == '0' && num1_start < num1.length())
            num1_start++;
        while (num2[num2_start] == '0' && num2_start < num2.length())
            num2_start++;

        if (num1_start == num1.length() || num2_start == num2.length())
            return "0";

        string curr_multi, ans = "0";
        int carry = 0;

        for (int i = num2.length() - 1; i >= num2_start; i--) {
            curr_multi = "";
            for (int j = num1.length() - 1; j >= num1_start; j--) {
                curr_multi.insert(
                    0, 1,
                    (((num1[j] - '0') * (num2[i] - '0') + carry) % 10) + '0');
                carry = ((num1[j] - '0') * (num2[i] - '0') + carry) / 10;
            }
            if (carry) curr_multi.insert(0, 1, carry + '0');
            carry = 0;
            for (int j = i; j < num2.length() - 1; j++) curr_multi += '0';
            addStringCaller(ans, curr_multi);
        }

        return ans;
    }

    void addStringCaller(string &a, string &b) {
        if (a.length() >= b.length())
            addString(a, b);
        else {
            addString(b, a);
            a = b;
        }
    }

    void addString(string &a, string &b) {
        int carry = 0;
        string temp = a;
        for (int i = 0; i < b.length(); i++) {
            a[a.length() - i - 1] = ((a[a.length() - i - 1] - '0') +
                                     (b[b.length() - i - 1] - '0') + carry) %
                                        10 +
                                    '0';
            carry = ((temp[temp.length() - i - 1] - '0') +
                     (b[b.length() - i - 1] - '0') + carry) /
                    10;
        }
        for (int i = a.length() - b.length() - 1; i >= 0; i--) {
            if (carry == 0) return;
            a[i] = ((a[i] - '0') + carry) % 10 + '0';
            carry = ((temp[i] - '0') + carry) / 10;
        }
        if (carry) {
            a.insert(0, 1, carry + '0');
        }
    }
};

int main() {
    Solution sol;
    string num1 = "123", num2 = "456";
    cout << sol.multiply(num1, num2) << endl;  // Output: "56088"
    return 0;
}
