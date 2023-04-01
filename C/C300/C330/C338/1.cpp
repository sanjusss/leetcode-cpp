#include "leetcode.h"

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;
        int one = min(numOnes, k);
        ans += one;
        k -= one;

        int zero = min(numZeros, k);
        k -= zero;

        int neg = min(k, numNegOnes);
        ans -= neg;
        return ans;
    }
};