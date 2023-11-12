/*
 * @Author: sanjusss
 * @Date: 2023-11-12 10:31:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-11-12 11:12:34
 * @FilePath: \C\C300\C370\C371\4.cpp
 */
#include "leetcode.h"

struct Node {
    Node* children[2] = { nullptr, nullptr };
    int cnt = 0;
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        static constexpr int maxBits = 20;
        int ans = 0;
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        int n = nums.size();
        Node root;
        for (int i = 0; i < n; ++i) {
            while (right <= i && nums[i] - nums[right] <= nums[right]) {
                Node* node = &root;
                for (int j = maxBits - 1; j >= 0; --j) {
                    int b = (nums[right] & (1 << j)) ? 1 : 0;
                    if (node->children[b] == nullptr) {
                        node->children[b] = new Node();
                    }

                    node = node->children[b];
                    ++(node->cnt);
                }

                ++right;
            }

            while (left <= i && nums[i] - nums[left] > nums[left]) {
                Node* node = &root;
                for (int j = maxBits - 1; j >= 0; --j) {
                    int b = (nums[left] & (1 << j)) ? 1 : 0;
                    if (--(node->children[b]->cnt) == 0) {
                        node->children[b] = nullptr;
                        break;
                    }

                    node = node->children[b];
                }
                ++left;
            }

            Node* node = &root;
            int cur = 0;
            for (int j = maxBits - 1; j >= 0; --j) {
                int b = (nums[i] & (1 << j)) ? 1 : 0;
                if (node->children[1 - b] == nullptr) {
                    node = node->children[b];
                }
                else {
                    node = node->children[1 - b];
                    cur |= 1 << j;
                }
            }

            ans = max(ans, cur);
        }

        return ans;
    }
};