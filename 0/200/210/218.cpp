/*
 * @Author: sanjusss
 * @Date: 2021-07-13 13:39:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-13 17:11:57
 * @FilePath: \0\200\210\218.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        map<int, int> rights;  //右侧点的集合，value应该是升序
        int n = buildings.size();
        for (auto& b : buildings) {
            int l = b[0];
            int r = b[1];
            int h = b[2];

            //处理与当前没有交集的点
            while (!rights.empty() && rights.begin()->first < l) {
                int x = rights.begin()->first;
                rights.erase(rights.begin());
                int y = 0;
                if (!rights.empty()) {
                    y = rights.begin()->second;
                }

                if (ans.empty() || ans.back()[1] != y) {  //只追加和上一个点不一样高的点。
                    ans.emplace_back(vector<int>({ x, y }));
                }
            }

            if (rights.empty()) {  // 没有多余的右侧点，说明点(l, h)是第一个点。
                if (ans.empty() || ans.back()[1] != h) {  //只追加和上一个点不一样高的点。
                    ans.emplace_back(vector<int>({ l, h }));
                }

                rights[r] = h;
                continue;
            }

            if (!ans.empty() && ans.back()[0] == l) {
                if (ans.back()[1] < h) {  //对于x相同的左侧点，取y大的点。
                    ans.back()[1] = h;
                    if (ans.size() >= 2 && ans[ans.size() - 2][1] == h) {  //只追加和上一个点不一样高的点。
                        ans.pop_back();
                    }
                }
            }
            else if (rights.begin()->second < h) { //追加点需要高过最高线。
                if (ans.empty() || ans.back()[1] != h) {  //只追加和上一个点不一样高的点。
                    ans.emplace_back(vector<int>({ l, h }));
                }
            }

            auto p = rights.lower_bound(r);
            if (p != rights.end() && p->second >= h) {
                continue;
            }

            p = rights.insert_or_assign(r, h).first;
            if (p != rights.begin()) {
                --p;
                while (p != rights.begin() && p->second <= h) {
                    rights.erase(p--);
                }

                if (p->second <= h) {
                    rights.erase(p);
                }
            }
        }

        while (!rights.empty()) {
            int x = rights.begin()->first;
            rights.erase(rights.begin());
            int y = 0;
            if (!rights.empty()) {
                y = rights.begin()->second;
            }

            if (ans.empty() || ans.back()[1] != y) {  //只追加和上一个点不一样高的点。
                ans.emplace_back(vector<int>({ x, y }));
            }
        }

        return ans;
    }
};

TEST(&Solution::getSkyline)