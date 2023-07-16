#include "leetcode.h"

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> conns(n);
        for (auto& e : edges) {
            conns[e[0]].push_back(e[1]);
            conns[e[1]].push_back(e[0]);
        }

        int root = 0;
        for (int i = 1; i < n; ++i) {
            if (conns[i].size() > conns[root].size()) {
                root = i;
            }
        }

        vector<pair<int, int>> sums(n);
        function<void(int, int64_t)> addChildren = [&] (int i, int parent) {
            auto& [dis, cnt] = sums[i];
            ++cnt;
            for (int j : conns[i]) {
                if (j == parent) {
                    continue;
                }

                addChildren(j, i);
                dis += sums[j].first + sums[j].second;
                cnt += sums[j].second;
            }
        };
        addChildren(root, -1);
        function<void(int, int64_t)> addParent = [&] (int i, int parent) {
            auto& [dis, cnt] = sums[i];
            if (parent >= 0) {
                auto [otherD, otherC] = sums[parent];
                otherD -= dis + cnt;
                otherC -= cnt;
                dis += otherD + otherC;
                cnt += otherC;
            }

            for (int j : conns[i]) {
                if (j == parent) {
                    continue;
                }
                
                addParent(j, i);
            }
        };
        addParent(root, -1);

        vector<int> ans;
        for (auto [dis, _] : sums) {
            ans.push_back(dis);
        }

        return ans;
    }
};