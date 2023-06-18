#include "leetcode.h"

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<vector<int>> prefixSums(n + 1);
        prefixSums[0] = vector<int>(26);
        for (int i = 0; i < n; ++i) {
            auto& cnt = prefixSums[i + 1];
            cnt = prefixSums[i];
            ++cnt[s[i] - 'a'];
        }

        vector<bool> ans;
        for (auto& q : queries) {
            auto& left = prefixSums[q[0]];
            auto& right = prefixSums[q[1] + 1];
            int k = q[2];
            int single = 0;
            for (int i = 0; i < 26; ++i) {
                single += (right[i] - left[i]) % 2;
            }

            ans.push_back(single <= k * 2 + 1);
        }

        return ans;
    }
};