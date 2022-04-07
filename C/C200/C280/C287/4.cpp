/*
 * @Author: sanjusss
 * @Date: 2022-04-03 10:19:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-03 11:29:42
 * @FilePath: \C\C200\C280\C287\4.cpp
 */
#include "leetcode.h"

class Encrypter {
    struct Trie {
        unordered_set<string> srcs;
        Trie* children[26] {};
    };

public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int kvn = keys.size();
        for (int i = 0; i < kvn; ++i) {
            m_k2v[keys[i]] = values[i];
        }

        for (auto& s : dictionary) {
            string e = encrypt(s);
            Trie* node = &m_root;
            for (char i : e) {
                if (node->children[i - 'a'] == nullptr) {
                    node->children[i - 'a'] = new Trie();
                }

                node = node->children[i - 'a'];
            }

            node->srcs.insert(s);
        }
    }
    
    string encrypt(string word1) {
        string ans;
        for (char i : word1) {
            ans += m_k2v[i];
        }

        return ans;
    }
    
    int decrypt(string word2) {
        string cur;
        unordered_set<string> ans;
        dfs(word2, cur, ans);
        return ans.size();
    }

private:
    void dfs(string_view s, string& cur, unordered_set<string>& ans) {
        if (s.empty()) {
            ans.insert(cur);
            return;
        }

        int oldSize = cur.size();
        int n = s.size();
        Trie* node = &m_root;
        for (int i = 0; i < n; ++i) {
            if (node->children[s[i] - 'a'] == nullptr) {
                break;
            }

            node = node->children[s[i] - 'a'];
            if (node->srcs.empty()) {
                continue;
            }

            for (auto& j : node->srcs) {
                cur += j;
                dfs(s.substr(i + 1), cur, ans);
                cur.resize(oldSize);
            }
        }
    }

private:
    unordered_map<char, string> m_k2v;
    Trie m_root;
};
