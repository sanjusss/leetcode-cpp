/*
 * @Author: sanjusss
 * @Date: 2023-02-12 10:47:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-12 11:03:49
 * @FilePath: \C\C300\C330\C332\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> dict;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int small = max(i - 30, 0);
            int k = 0;
            for (int j = i; j >= small; --j) {
                k |= (s[j] - '0') << (i - j);
                if (dict.count(k) && dict[k][1] - dict[k][0] <= i - j) {
                    continue;
                }

                dict[k].resize(2);
                dict[k][0] = j;
                dict[k][1] = i;
            }
        }
        
        vector<vector<int>> ans;
        vector<int> notfound = {{ -1, -1 }};
        for (auto& q : queries) {
            int k = q[0] ^ q[1];
            if (dict.count(k)) {
                ans.push_back(dict[k]);
            }
            else {
                ans.push_back(notfound);
            }
        }

        return ans;
    }
};

TEST(&Solution::substringXorQueries)