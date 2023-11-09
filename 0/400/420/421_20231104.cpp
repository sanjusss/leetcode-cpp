#include "leetcode.h"

struct Node {
    Node* children[2] { nullptr, nullptr };
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Node root;
        int ans = 0;
        bool first = true;
        for (int i : nums) {
            if (first) {
                first = false;
            }
            else {
                int cur = 0;
                Node* node = &root;
                for (int j = 31; j >= 0; --j) {
                    int b = 1 << j;
                    if (i & b) {
                        if (node->children[0] != nullptr) {
                            cur += b;
                            node = node->children[0];
                        }
                        else {
                            node = node->children[1];
                        }
                    }
                    else {
                        if (node->children[1] != nullptr) {
                            cur += b;
                            node = node->children[1];
                        }
                        else {
                            node = node->children[0];
                        }
                    }
                }

                ans = max(ans, cur);
            }

            Node* node = &root;
            for (int j = 31; j >= 0; --j) {
                int b = (i & (1 << j)) ? 1 : 0;
                if (node->children[b] == nullptr) {
                    node->children[b] = new Node();
                }

                node = node->children[b];
            }
        }

        return ans;
    }
};

TEST(&Solution::findMaximumXOR)