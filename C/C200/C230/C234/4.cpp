/*
 * @Author: sanjusss
 * @Date: 2021-03-21 11:28:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-21 13:30:08
 * @FilePath: \C\C200\C230\C234\4.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int countPairs(vector<int>& nums, int low, int high) {
//         int ans = 0;
//         int n = nums.size();
//         int t;
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 t = nums[i] ^ nums[j];
//                 if (t >= low && t <= high) {
//                     ++ans;
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
    struct Node {
        array<Node*, 2> children{ nullptr, nullptr };
        int count = 0;
    };

public:
    int countPairs(vector<int>& nums, int low, int high) {
        int ans = 0;
        Node* root = new Node();
        auto count = [&](int target, int n) -> int {            
            Node* node = root;
            int res = 0;
            for (int i = 15; i >= 0 && node != nullptr; --i) {
                int value = 1 << i;
                int bit = (n & value) ? 1 : 0;
                if (target < value) {
                    node = node->children[bit];
                }
                else {
                    target -= value;
                    res += node->children[bit] ? node->children[bit]->count : 0;
                    node = node->children[1 - bit];
                }
            }

            return res;
        };
        for (int n : nums) {
            ans += count(high + 1, n) - count(low, n);
            Node* node = root;
            for (int i = 15; i >= 0; --i) {
                ++node->count;
                int bit = (n & (1 << i)) ? 1 : 0;
                if (node->children[bit] == nullptr) {
                    node->children[bit] = new Node();
                }

                node = node->children[bit];
            }

            ++node->count;
        }

        return ans;
    }
};

TEST(&Solution::countPairs)