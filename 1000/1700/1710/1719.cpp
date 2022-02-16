/*
 * @Author: sanjusss
 * @Date: 2022-02-16 21:41:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-16 21:52:00
 * @FilePath: \1000\1700\1710\1719.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> refs;
        for (auto& p : pairs) {
            refs[p[0]].insert(p[1]);
            refs[p[1]].insert(p[0]);
        }

        int root = -1;
        for (auto& [i, neighbours] : refs) {
            if (neighbours.size() == refs.size() - 1) {
                root = i;
                break;
            }
        }

        if (root == -1) {
            return 0;
        }

        int ans = 1;
        for (auto& [i, neighbours] : refs) {
            if (i == root) {
                continue;
            }

            int parent = -1;
            int parentDegree = INT_MAX;
            int degree = neighbours.size();
            for (int j : neighbours) {
                auto& jref = refs[j];
                if (jref.size() < parentDegree && jref.size() >= degree) {
                    parent = j;
                    parentDegree = jref.size();
                }
            }

            if (parent == -1) {
                return 0;
            }

            auto& parentRef = refs[parent];
            for (int j : neighbours) {
                if (j == parent) {
                    continue;
                }
                else if (!parentRef.count(j)) {
                    return 0;
                }
            }
            
            if (parentDegree == degree) {
                ans = 2;
            }
        }

        return ans;
    }
};