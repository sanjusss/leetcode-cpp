#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         auto fpos = lower_bound(intervals.begin(), intervals.end(), vector<int>({ 0, newInterval[0] }),
//                                 [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
//         if (fpos == intervals.end()) {
//             intervals.emplace_back(move(newInterval));
//             return intervals;
//         }

//         auto bpos = upper_bound(intervals.begin(), intervals.end(), vector<int>({ newInterval[1], 0 }),
//                                 [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

//         vector<vector<int>> ans;
//         for (auto i = intervals.begin(); i != fpos; ++i) {
//             ans.emplace_back(move(*i));
//         }

//         if (fpos == bpos) {
//             ans.emplace_back(move(newInterval));
//         }
//         else {
//             auto epos = prev(bpos);
//             ans.emplace_back(vector<int>({ min((*fpos)[0], newInterval[0]), max((*epos)[1], newInterval[1]) }));
//         }

//         for (auto i = bpos; i != intervals.end(); ++i) {
//             ans.emplace_back(move(*i));
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool done = false;
        bool half = false;
        int halfFront = 0;
        for (auto& old : intervals) {
            if (done) {
                ans.push_back(old);
            }
            else if (half) {
                if (newInterval[1] < old[0]) {
                    ans.push_back({ halfFront, newInterval[1] });
                    ans.push_back(old);
                    done = true;
                }
                else if (newInterval[1] <= old[1]) {
                    ans.push_back({ halfFront, old[1] });
                    done = true;
                }
            }
            else {
                if (newInterval[1] < old[0]) {
                    ans.push_back(newInterval);
                    ans.push_back(old);
                    done = true;
                }
                else if (newInterval[0] <= old[1]) {
                    if (newInterval[1] <= old[1]) {
                        ans.push_back({ min(old[0], newInterval[0]), old[1] });
                        done = true;
                    }
                    else {
                        halfFront = min(old[0], newInterval[0]);
                        half = true;
                    }
                }
                else {
                    ans.push_back(old);
                }
            }
        }

        if (done == false) {
            if (half) {
                ans.push_back({ halfFront, newInterval[1] });
            }
            else {
                ans.push_back(newInterval);
            }
        }

        return ans;
    }
};