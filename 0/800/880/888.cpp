#include "leetcode.h"

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int diff = (sumA - sumB) / 2;
        unordered_set<int> bset(B.begin(), B.end());
        for (int i : A) {
            if (bset.find(i - diff) != bset.end()) {
                return { i, i - diff };
            }
        }

        return {};
    }
};

TEST(Solution::fairCandySwap)