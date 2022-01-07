#include "leetcode.h"

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int left = 0;
        for (char i : s) {
            if (i == '(') {
                ans = max(++left, ans);
            }
            else if (i == ')') {
                --left;
            }
        }

        return ans;
    }
};