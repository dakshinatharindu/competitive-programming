#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int nsize = needle.size();

        if (nsize > haystack.size()) return -1;
        
        for (int i = 0; i <= haystack.size() - nsize; i++) {
            if (haystack.substr(i, nsize) == needle) {
                return i;
            }
        }

        return -1;
    } 
};

int main() {
    Solution solution;
    string haystack = "hello";
    string needle = "ll";
    int result = solution.strStr(haystack, needle);
    cout << "The index of the first occurrence of '" << needle << "' in '" << haystack << "' is: " << result << endl;
    return 0;
}