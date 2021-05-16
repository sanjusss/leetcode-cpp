/*
 * @Author: sanjusss
 * @Date: 2021-05-16 10:02:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-16 10:13:38
 * @FilePath: \0\400\420\421_20210516.cpp
 */
#include "leetcode.h"

class Solution {
    struct Node {
        ~Node () {
            delete children[0];
            delete children[1];
        }

        array<Node*, 2> children = { 0 };
    };

public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        Node root;
        for (int i : nums) {
            int temp = 0;
            Node* test = &root;
            Node* insert = &root;
            for (int j = 31; j >= 0; --j) {
                int bit = (i & (1 << j)) > 0 ? 1 : 0;
                if (test != nullptr) {
                    if (test->children[1 - bit] != nullptr) {
                        temp |= 1 << j;
                        test = test->children[1 - bit];
                    }
                    else {
                        test = test->children[bit];
                    }
                }

                if (insert->children[bit] == nullptr) {
                    insert->children[bit] = new Node();
                }

                insert = insert->children[bit];
            }

            ans = max(temp, ans);
        }

        return ans;
    }
};

TEST(&Solution::findMaximumXOR)