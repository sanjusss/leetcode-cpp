#include "leetcode.h"

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int i : nums) {
            if (i % 2 == 0) {
                ++cnt[i];
            }
        }

        int freq = 0;
        int ans = -1;
        for (auto [i, c] : cnt) {
            if (c > freq) {
                freq = c;
                ans = i;
            }
            else if (c == freq) {
                ans = min(ans, i);
            }
        }

        return ans;
    }
};