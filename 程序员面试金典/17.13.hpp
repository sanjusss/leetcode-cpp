#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    int respace(vector<string>& dictionary, string sentence) {
//        return respace(unordered_set<string_view>(dictionary.begin(), dictionary.end()), string_view(sentence), 0);
//    }
//
//private:
//    int respace(unordered_set<string_view>& dictionary, string_view& sentence, int cur) {
//        if (cur >= sentence.size()) {
//            return 0;
//        }
//
//        int ans = INT_MAX;
//        for (int i = cur; i < sentence.size(); ++i) {
//            string_view test = sentence.substr(cur, i - cur + 1);
//            if (dictionary.find(test) == dictionary.end()) {
//                ans = min(ans, i - cur + 1 + respace(dictionary, sentence, i + 1));
//            }
//            else {
//                ans = min(ans, respace(dictionary, sentence, i + 1));
//            }
//        }
//
//        return ans;
//    }
//};

class Solution {
    struct Trie {
        Trie* children[26] = { 0 };
        bool isEnd = false;

        ~Trie() {
            for (auto i : children) {
                delete i;
            }
        }

        static void insert(Trie* root, string& s) {
            Trie* cur = root;
            int j;
            for (int i = s.size() - 1; i >= 0; --i) {
                j = s[i] - 'a';
                if (cur->children[j] == nullptr) {
                    cur->children[j] = new Trie();
                }

                cur = cur->children[j];
            }

            cur->isEnd = true;
        }
    };

public:
    int respace(vector<string>& dictionary, string sentence) {
        Trie tree;
        for (auto& i : dictionary) {
            Trie::insert(&tree, i);
        }

        int n = sentence.size();
        vector<int> dp(n + 1);
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = dp[i] + 1;
            Trie* cur = &tree;
            for (int j = i; j >= 0 && cur->children[sentence[j] - 'a'] != nullptr; --j) {
                cur = cur->children[sentence[j] - 'a'];
                if (cur->isEnd) {
                    dp[i + 1] = min(dp[i + 1], dp[j]);
                }
            }
        }

        return dp[n];
    }
};