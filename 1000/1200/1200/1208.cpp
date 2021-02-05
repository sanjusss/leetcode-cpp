#include "leetcode.h"

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int cost = 0;
        int ans = 0;
        while (right < n) {
            cost += abs(s[right] - t[right]);
            if (cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                ++left;
            }
            else {
                ++ans;
            }

            ++right;
        }

        return ans;
    }
};

TEST(&Solution::equalSubstring)