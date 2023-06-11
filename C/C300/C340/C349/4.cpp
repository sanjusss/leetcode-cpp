/*
 * @Author: sanjusss
 * @Date: 2023-06-04 10:29:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-11 16:33:13
 * @FilePath: \C\C300\C340\C349\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int nlen = nums1.size();
        int qlen = queries.size();
        map<int, int> y2id;
        vector<pair<bool, int>> xs;
        for (int i = 0; i < nlen; ++i) {
            y2id[nums2[i]];
            xs.emplace_back(false, i);
        }

        for (int i = 0; i < qlen; ++i) {
            y2id[queries[i][1]];
            xs.emplace_back(true, i);
        }

        int curreId = y2id.size();
        for (auto& [_, id] : y2id) {
            id = curreId--;
        }

        vector<int> tree(y2id.size() + 1, -1);
        auto modify = [&tree](int id, int sum) {
            while (id < tree.size()) {
                tree[id] = max(tree[id], sum);
                id += id & -id;
            }
        };
        auto query = [&tree](int id) -> int {
            int res = -1;
            while (id > 0) {
                res = max(tree[id], res);
                id -= id & -id;
            }

            return res;
        };

        sort(xs.begin(), xs.end(), [&nums1, &queries](const pair<bool, int>& a, const pair<bool, int>& b) {
            int va = (a.first ? queries[a.second][0] : nums1[a.second]);
            int vb = (b.first ? queries[b.second][0] : nums1[b.second]);
            if (va == vb) {
                va += a.first ? 0 : 1;
                vb += b.first ? 0 : 1;
                return va > vb;
            }
            else {
                return va > vb;
            }
        });

        vector<int> ans(qlen);
        for (auto [isQuery, i] : xs) {
            if (isQuery) {
                int id = y2id[queries[i][1]];
                ans[i] = query(id);
            }
            else {
                int id = y2id[nums2[i]];
                modify(id, nums1[i] + nums2[i]);
            }
        }

        return ans;
    }
};

TEST(&Solution::maximumSumQueries)