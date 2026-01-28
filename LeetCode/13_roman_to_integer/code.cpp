#include <iostream>
#include <map>
#include <string>
#include <stdint.h>

using namespace std;

class Solution {
    public:
        int romanToInt(string s) {
            int n = s.size();
            int i = 0;
    
            std::map<char, uint16_t> my_map = {
                { 'I', 1 },
                { 'V', 5 },
                { 'X', 10 },
                { 'L', 50 },
                { 'C', 100 },
                { 'D', 500 },
                { 'M', 1000 }
            };
    
            int ret = 0;
    
            while(1) {
                if (i >= n - 1) {
                    ret += my_map[s[i]];
                    break;
                }
    
                if ((s[i] == 'I') && ((s[i+1] == 'V') || (s[i+1] == 'X'))) {
                    ret += my_map[s[i+1]] - 1;
                    i++;
                } else if ((s[i] == 'X') && ((s[i+1] == 'L') || (s[i+1] == 'C'))) {
                    ret += my_map[s[i+1]] - 10;
                    i++;
                } else if ((s[i] == 'C') && ((s[i+1] == 'D') || (s[i+1] == 'M'))) {
                    ret += my_map[s[i+1]] - 100;
                    i++;
                } else {
                    ret += my_map[s[i]];
                }
    
                i++;
            }
    
            return ret;
        }
    };

int main() {
    Solution s;
    cout << s.romanToInt("MCMXCIV") << endl;
}