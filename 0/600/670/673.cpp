/*
 * @Author: sanjusss
 * @Date: 2021-08-20 18:11:51
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-25 17:34:40
 * @FilePath: \0\600\670\673.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int findNumberOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> len(n, 1);
//         vector<int> cnt(n, 1);
//         for (int i = 1; i < n; ++i) {
//             for (int j = 0; j < i; ++j) {
//                 if (nums[i] <= nums[j]) {
//                     continue;
//                 }

//                 if (len[j] + 1 > len[i]) {
//                     len[i] = len[j] + 1;
//                     cnt[i] = cnt[j];
//                 }
//                 else if (len[j] + 1 == len[i]) {
//                     cnt[i] += cnt[j];
//                 }
//             }
//         }

//         int maxLen = *max_element(len.begin(), len.end());
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             if (len[i] == maxLen) {
//                 ans += cnt[i];
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int findNumberOfLIS(vector<int>& nums) {
//         vector<vector<int>> arr;
//         vector<vector<int>> cnts;
//         for (int n : nums) {
//             int i = lower_bound(arr.begin(), arr.end(), n, [](const vector<int>& a, int b) { return a.back() < b; })
//             -
//                     arr.begin();
//             int cnt = 1;
//             if (i != 0) {
//                 int j = lower_bound(arr[i - 1].rbegin(), arr[i - 1].rend(), n) - arr[i - 1].rbegin();
//                 cnt = cnts[i - 1].back() - (j < cnts[i - 1].size() ? *(cnts[i - 1].rbegin() + j) : 0);
//             }

//             if (i == arr.size()) {
//                 arr.push_back({ n });
//                 cnts.push_back({ cnt });
//             }
//             else {
//                 arr[i].push_back(n);
//                 cnts[i].push_back(cnt + cnts[i].back());
//             }
//         }

//         return cnts.empty() ? 0 : cnts.back().back();
//     }
// };

// class Solution {
// public:
//     int findNumberOfLIS(vector<int>& nums) {
//         vector<vector<int>> arr;
//         vector<vector<int>> cnts;
//         for (int n : nums) {
//             int i = lower_bound(arr.begin(), arr.end(), n, [](const vector<int>& a, int b) { return a.back() < b; })
//             -
//                     arr.begin();
//             int cnt = 1;
//             if (i != 0) {
//                 int j = lower_bound(arr[i - 1].rbegin(), arr[i - 1].rend(), n) - arr[i - 1].rbegin();
//                 cnt = cnts[i - 1].back() - (j < cnts[i - 1].size() ? *(cnts[i - 1].rbegin() + j) : 0);
//             }

//             if (i == arr.size()) {
//                 arr.push_back({ n });
//                 cnts.push_back({ cnt });
//             }
//             else {
//                 arr[i].push_back(n);
//                 cnts[i].push_back(cnt + cnts[i].back());
//             }
//         }

//         return cnts.empty() ? 0 : cnts.back().back();
//     }
// };

class Solution {
    struct Node {
        int cnt = 0;
        int maxLength = 1;

        constexpr void update(const Node& node) {
            if (node.maxLength == maxLength) {
                cnt += node.cnt;
            }
            else if (node.maxLength > maxLength) {
                maxLength = node.maxLength;
                cnt = node.cnt;
            }
        }

        constexpr void reset() {
            cnt = 0;
            maxLength = 1;
        }
    };

    struct NodeArray {
        NodeArray(int n) : n(n), nodes(n + 1) {
        }

        static constexpr int lowbit(int i) {
            return i & -i;
        }

        void update(const Node& from, int to) {
            while (to <= n) {
                nodes[to].update(from);
                to += lowbit(to);
            }
        }

        void init(Node& node, int i) {
            node.reset();
            while (i > 0) {
                node.update(nodes[i]);
                i -= lowbit(i);
            }

            ++node.maxLength;
            node.cnt = max(node.cnt, 1);
        }

        const int n;
        vector<Node> nodes;
    };

public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        Node ans;
        Node cur;
        NodeArray na(nums.size());
        for (int i : nums) {
            int p = lower_bound(sorted.begin(), sorted.end(), i) - sorted.begin();
            na.init(cur, p);
            ans.update(cur);
            na.update(cur, p + 1);
        }

        return ans.cnt;
    }
};

TEST(&Solution::findNumberOfLIS)