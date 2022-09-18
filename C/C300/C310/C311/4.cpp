/*
 * @Author: sanjusss
 * @Date: 2022-09-18 10:28:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-18 11:05:49
 * @FilePath: \C\C300\C310\C311\4.cpp
 */
#include "leetcode.h"

struct Node {
    Node* children[26]{};
    int cnt = 0;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        for (auto& s : words) {
            insert(s);
        }

        vector<int> ans;
        for (auto& s : words) {
            ans.push_back(query(s));
        }

        return ans;
    }

private:
    void insert(const string& s) {
        Node* node = m_root;
        for (char c : s) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                node->children[i] = new Node();
            }

            node = node->children[i];
            ++node->cnt;
        }
    }

    int query(const string& s) {
        Node* node = m_root;
        int ans = 0;
        for (char c : s) {
            int i = c - 'a';
            node = node->children[i];
            ans += node->cnt;
        }

        return ans;
    }

private:
    Node* m_root = new Node();
};

TEST(&Solution::sumPrefixScores)