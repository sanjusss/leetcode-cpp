/*
 * @Author: sanjusss
 * @Date: 2024-01-09 09:29:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-01-09 09:41:41
 * @FilePath: \2000\2700\2700\2707.cpp
 */
#include "leetcode.h"

struct Node {
    Node* children[26] = {};
    bool end = false;
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Node root;
        for (auto& w : dictionary) {
            Node* head = &root;
            for (char c : w) {
                int i = c - 'a';
                if (head->children[i] == nullptr) {
                    head->children[i] = new Node();
                }

                head = head->children[i];
            }

            head->end = true;
        }

        int n = s.size();
        vector<int> dp(n + 1, INT_MAX / 2);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            Node* head = &root;
            for (int j = i; j < n && head != nullptr; ++j) {
                head = head->children[s[j] - 'a'];
                if (head && head->end) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
                else {
                    dp[i] = min(dp[i], j - i + 1 + dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};