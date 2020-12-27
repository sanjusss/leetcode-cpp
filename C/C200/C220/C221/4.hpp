/*
 * @Author: sanjusss
 * @Date: 2020-12-27 11:02:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-27 12:44:22
 * @FilePath: \C\C200\C220\C221\4.hpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
//         sort(nums.begin(), nums.end());
//         vector<int> ans;
//         for (auto& q : queries) {
//             auto end = upper_bound(nums.begin(), nums.end(), q[1]);
//             if (nums.begin() == end) {
//                 ans.push_back(-1);
//                 continue;
//             }

//             ans.push_back(0);
//             for (auto i = nums.begin(); i != end; ++i) {
//                 ans.back() = max(ans.back(), (*i) ^ q[0]);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
private:
    class Node {
    public:
        Node* zero = nullptr;
        Node* one = nullptr;
        int min = INT_MAX;
    };

public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        static const int h = 30;
        Node* root = new Node();
        for (int i : nums) {
            Node* node = root;
            node->min = min(node->min, i);
            for (int j = h - 1; j >= 0; --j) {
                if ((1 << j) & i) {
                    if (node->one == nullptr) {
                        node->one = new Node();
                    }

                    node = node->one;
                }
                else {
                    if (node->zero == nullptr) {
                        node->zero = new Node();
                    }

                    node = node->zero;
                }
                
                node->min = min(node->min, i);
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            int x = q[0];
            int m = q[1];
            int v = 0;
            Node* node = root;
            for (int j = h - 1; j >= 0; --j) {
                int bit = 1 << j;
                v <<= 1;
                if (x & bit) {
                    if (node->zero != nullptr) {
                        ++v;
                        node = node->zero;
                    }
                    else {
                        node = node->one;
                        if (node->min > m) {
                            v = -1;
                            break;
                        }
                    }
                }
                else {
                    if (node->one != nullptr && node->one->min <= m) {
                        ++v;
                        node = node->one;
                    }
                    else if (node->zero != nullptr) {
                        node = node->zero;
                    }
                    else {
                        v = -1;
                        break;
                    }   
                }
            }

            ans.push_back(v);
        }

        return ans;
    }
};