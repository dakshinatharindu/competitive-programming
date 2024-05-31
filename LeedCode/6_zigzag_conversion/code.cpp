#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        int j, k;
        string out = "";
        if (numRows == 1) return s;
        for (int i = 0; i < numRows; i++)
        {
            if ((i == 0) || (i == numRows - 1)){
                j = i;
                while (j < n)
                {
                    out += s[j];
                    j = j + 2 * (numRows - 1);
                }
                
            } else {
                j = i;
                k = 2 * (numRows - 1) - i;

                while (k < n)
                {
                    out += s[j];
                    out += s[k];
                    j = j + 2 * (numRows - 1);
                    k = k + 2 * (numRows - 1);
                }

                if (j < n) {
                    out += s[j];
                }
                
            }
        }
        
        return out;
    }
};

int main(){
    Solution s;
    cout << s.convert("A", 1) << endl;
}