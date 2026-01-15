#include <climits>
#include <cstdlib>
#include <iostream>

using namespace std;

class Solution {
   public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool negative = (dividend < 0) ^ (divisor < 0);

        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long quotient = 0;

        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            quotient += multiple;
        }

        if (negative) quotient = -quotient;

        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;

        return (int)quotient;
    }
};

int main() {
    Solution solution;
    int dividend = 10;
    int divisor = 3;
    int result = solution.divide(dividend, divisor);

    cout << "Quotient of " << dividend << " divided by " << divisor
         << " is: " << result << "\n";

    // Second example
    Solution solution2;
    int divided2 = 7;
    int divisor2 = -3;
    int result2 = solution2.divide(divided2, divisor2);

    cout << "Quotient of " << divided2 << " divided by " << divisor2
         << " is: " << result2 << "\n";

    return 0;
}
