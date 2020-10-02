#pragma once
#include "leetcode.h"

class Solution {
    struct CharNode {
        CharNode* children[26] = { 0 };
        int index = -1;

        ~CharNode() {
            for (auto i : children) {
                delete i;
            }
        }
    };

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        CharNode front;
        CharNode back;
        for (int i = 0; i < words.size(); ++i) {
            insertFront(&front, words[i], 0, i);
            insertBack(&back, words[i], words[i].size() - 1, i);
        }

        unordered_map<int, unordered_set<int>> pairs;
        for (int i = 0; i < words.size(); ++i) {
            string& s = words[i];
            int j = s.size() - 1;
            CharNode* cur = &front;
            if (cur->index >= 0 && i != cur->index && isPalindrome(s, 0, j)) {
                pairs[cur->index].insert(i);
            }

            while (j >= 0) {
                cur = cur->children[s[j] - 'a'];
                if (cur == nullptr) {
                    break;
                }

                --j;
                if (cur->index >= 0 && i != cur->index && isPalindrome(s, 0, j)) {
                    pairs[cur->index].insert(i);
                }
            }

            j = 0;
            cur = &back;
            if (cur->index >= 0 && i != cur->index && isPalindrome(s, j, s.size() - 1)) {
                pairs[i].insert(cur->index);
            }

            while (j < s.size()) {
                cur = cur->children[s[j] - 'a'];
                if (cur == nullptr) {
                    break;
                }

                ++j;
                if (cur->index >= 0 && i != cur->index && isPalindrome(s, j, s.size() - 1)) {
                    pairs[i].insert(cur->index);
                }
            }
        }

        vector<vector<int>> ans;
        for (auto& p : pairs) {
            for (auto j : p.second) {
                ans.push_back({ p.first, j });
            }
        }

        return ans;
    }

private:
    void insertFront(CharNode* node, string& s, int cur, int index) {
        if (cur == s.size()) {
            node->index = index;
        }
        else {
            CharNode*& next = node->children[s[cur] - 'a'];
            if (next == nullptr) {
                next = new CharNode();
            }

            insertFront(next, s, cur + 1, index);
        }
    }

    void insertBack(CharNode* node, string& s, int cur, int index) {
        if (cur < 0) {
            node->index = index;
        }
        else {
            CharNode*& next = node->children[s[cur] - 'a'];
            if (next == nullptr) {
                next = new CharNode();
            }

            insertBack(next, s, cur - 1, index);
        }
    }

    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] == s[end]) {
                ++start;
                --end;
            }
            else {
                return false;
            }
        }

        return true;
    }
};