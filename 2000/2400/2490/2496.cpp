#include "leetcode.h"

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for (auto& s : strs) {
            int cur = 0;
            for (char i : s) {
                if (i >= '0' && i <= '9') {
                    cur = cur * 10 + i - '0';
                }
                else {
                    cur = s.size();
                    break;
                }
            }

            ans = max(ans, cur);
        }

        return ans;
    }
};