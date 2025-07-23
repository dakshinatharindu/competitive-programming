#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string runLengthEnc(string &in) {
        string out;
        stringstream ss;

        char curr = in[0];
        int count = 1;

        for (int i = 1; i < in.length(); i++) {
            if (curr == in[i]) {
                count++;
            } else {
                ss << count << curr;
                curr = in[i];
                count = 1;
            }
        }

        ss << count << curr;

        return ss.str();
    }

    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        } else {
            string in = "1";
            for (int i = 0; i < n - 1; i++) {
                in = runLengthEnc(in);
            }

            return in;
        }
    }
};

int main() {
    Solution solution;
    int n = 5; // Example input
    string result = solution.countAndSay(n);
    cout << "The " << n << "th term in the count-and-say sequence is: " << result << endl;
    return 0;
}
