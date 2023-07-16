/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-16 11:20:09
 * @FilePath: \C\C300\C350\C354\4.cpp
 */
#include "leetcode.h"

struct Node {
    Node* children[26] = {};
    bool end = false;
};

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        Node* root = new Node();
        for (auto& s : forbidden) {
            insert(root, s);
        }

        string_view sv = word;
        int n = sv.size();
        int ans = 0;
        int last = 0;
        for (int i = n - 1; i >= 0; --i) {
            string_view sub = sv.substr(i);
            int match = findMin(sub, root);
            if (match == -1) {
                ++last;
            }
            else {
                last = min(last + 1, max(0, match - 1));
            }

            ans = max(ans, last);
        }

        return ans;
    }

private:
    void insert(Node* node, const string& s) {
        for (char c : s) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                node->children[i] = new Node();
            }

            node = node->children[i];
        }

        node->end = true;
    }

    int findMin(string_view s, Node* node) {
        int len = 0;
        for (char c : s) {
            if (node->end) {
                return len;
            }

            int i = c - 'a';
            if (node->children[i] == nullptr) {
                return -1;
            }

            node = node->children[i];
            ++len;
        }

        if (node->end) {
            return len;
        }
        else {
            return -1;
        }
    }
};

TEST(&Solution::longestValidSubstring)