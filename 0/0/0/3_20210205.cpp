#include "leetcode.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> indeies(CHAR_MAX + 1, -1);
        int n = s.size();
        int ans = 0;
        int left = -1;
        for (int i = 0; i < n; ++i) {
            if (indeies[s[i]] > left) {
                left = indeies[s[i]];
            }

            ans = max(i - left, ans);
            indeies[s[i]] = i;
        }

        return ans;
    }
};

TEST(&Solution::lengthOfLongestSubstring)