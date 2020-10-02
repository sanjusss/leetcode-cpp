#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    vector<int> smallestRange(vector<vector<int>>& nums) {
//        auto cmp = [&nums](const pair<int, int>& a, const pair<int, int>& b) {
//            return nums[a.first][a.second] > nums[b.first][b.second];
//        };
//
//        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
//        for (int i = 0; i < nums.size(); ++i) {
//            q.push({ i, 0 });
//        }
//
//        int left = -1e5;
//        int right = 1e5;
//        multiset<int> vs;
//        while (!q.empty()) {
//            auto p = q.top();
//            q.pop();
//
//            if (p.second > 0) {
//                vs.erase(vs.find(nums[p.first][p.second - 1]));
//            }
//
//            vs.insert(nums[p.first][p.second]);
//            if (vs.size() == nums.size()) {
//                int tl = *vs.begin();
//                int tr = *vs.rbegin();
//                if (tr - tl < right - left) {
//                    right = tr;
//                    left = tl;
//                }
//            }
//
//            ++p.second;
//            if (p.second < nums[p.first].size()) {
//                q.push(p);
//            }
//        }
//
//        return { left, right };
//    }
//};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> nexts(n);
        auto cmp = [&nums, &nexts](int a, int b) {
            return nums[a][nexts[a]] > nums[b][nexts[b]];
        };

        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        int left = -1e5;
        int right = 1e5;
        int curLeft = 0;
        int curRight = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            q.push(i);
            curRight = max(curRight, nums[i][0]);
        }

        while (true) {
            int i = q.top();
            q.pop();

            curLeft = nums[i][nexts[i]];
            if (curRight - curLeft < right - left) {
                left = curLeft;
                right = curRight;
            }

            ++nexts[i];
            if (nexts[i] == nums[i].size()) {
                break;
            }

            curRight = max(curRight, nums[i][nexts[i]]);
            q.push(i);
        }

        return { left, right };
    }
};