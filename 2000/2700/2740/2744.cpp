#include "leetcode.h"

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> cnt;
        for (auto& s : words) {
            ans += cnt[s];
            reverse(s.begin(), s.end());
            ++cnt[s];
        }

        return ans;
    }
};