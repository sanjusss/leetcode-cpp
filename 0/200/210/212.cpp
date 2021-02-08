#include "leetcode.h"

// class Solution {
//     struct Trie {
//         ~Trie() {
//             for (auto& i : children) {
//                 delete i;
//                 i = nullptr;
//             }
//         }

//         array<Trie*, 26> children = { 0 };
//         bool end = false;
//     };

// public:
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         Trie root;
//         initTrie(&root, words);
//         int m = board.size();
//         int n = board[0].size();
//         vector<vector<bool>> used(m, vector<bool>(n));
//         Trie ansTrie;
//         string s;
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 dfs(board, m, n, used, s, &ansTrie, &root, i, j);
//             }
//         }

//         vector<string> ans;
//         convertToVector(&ansTrie, ans);
//         return ans;
//     }

// private:
//     void initTrie(Trie* root, const vector<string>& words) {
//         for (auto& s : words) {
//             insertString(root, s);
//         }
//     }

//     void dfs(const vector<vector<char>>& board, const int m, const int n, vector<vector<bool>>& used, string& s,
//     Trie* ans, Trie* search, int i, int j) {
//         if (i < 0 || i >= m || j < 0 || j >= n || used[i][j]) {
//             return;
//         }

//         search = search->children[board[i][j] - 'a'];
//         if (search == nullptr) {
//             return;
//         }

//         used[i][j] = true;
//         s.push_back(board[i][j]);
//         if (search->end) {
//             insertString(ans, s);
//         }

//         static const vector<pair<int, int>> dirs = {
//             { 1, 0 },
//             { -1, 0 },
//             { 0, 1 },
//             { 0, -1 }
//         };

//         for (auto& [dx, dy] : dirs) {
//             dfs(board, m, n, used, s, ans, search, i + dx, j + dy);
//         }

//         s.pop_back();
//         used[i][j] = false;
//     }

//     void insertString(Trie* root, const string& s) {
//         auto cur = root;
//         for (char i : s) {
//             if (cur->children[i - 'a'] == nullptr) {
//                 cur->children[i - 'a'] = new Trie();
//             }

//             cur = cur->children[i - 'a'];
//         }

//         cur->end = true;
//     }

//     void convertToVector(Trie* root, vector<string>& arr) {
//         string s;
//         convertToVector(root, arr, s);
//     }

//     void convertToVector(Trie* cur, vector<string>& arr, string& s) {
//         if (cur->end) {
//             arr.push_back(s);
//         }

//         for (int i = 0; i < 26; ++i) {
//             if (cur->children[i] == nullptr) {
//                 continue;
//             }

//             s.push_back(i + 'a');
//             convertToVector(cur->children[i], arr, s);
//             s.pop_back();
//         }
//     }
// };

class Solution {
    struct Trie {
        ~Trie() {
            for (auto& i : children) {
                delete i;
                i = nullptr;
            }
        }

        void insert(const string& s) {
            auto cur = this;
            for (char i : s) {
                if (cur->children[i - 'a'] == nullptr) {
                    cur->children[i - 'a'] = new Trie();
                    ++(cur->childrenCount);
                }

                cur = cur->children[i - 'a'];
            }

            cur->end = true;
        }

        void removeEmptyChild(char i) {
            auto& child = children[i - 'a'];
            if (child == nullptr || child->childrenCount > 0) {
                return;
            }

            delete child;
            child = nullptr;
            --childrenCount;
        }

        array<Trie*, 26> children = { 0 };
        int childrenCount = 0;
        bool end = false;
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie root;
        for (auto& s : words) {
            root.insert(s);
        }

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n));
        vector<string> ans;
        string s;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, m, n, used, s, ans, &root, i, j);
            }
        }

        return ans;
    }

private:
    bool dfs(const vector<vector<char>>& board, const int m, const int n, vector<vector<bool>>& used, string& s,
             vector<string>& ans, Trie* search, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || used[i][j]) {
            return false;
        }

        auto trie = search->children[board[i][j] - 'a'];
        if (trie == nullptr) {
            return true;
        }

        bool hasResult = false;
        used[i][j] = true;
        s.push_back(board[i][j]);
        if (trie->end) {
            ans.push_back(s);
            trie->end = false;
            hasResult = true;
        }

        static const vector<pair<int, int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

        for (auto& [dx, dy] : dirs) {
            hasResult |= dfs(board, m, n, used, s, ans, trie, i + dx, j + dy);
        }

        s.pop_back();
        used[i][j] = false;
        if (hasResult) {
            search->removeEmptyChild(board[i][j]);
        }

        return hasResult;
    }
};

TEST_EQUIVALENT(&Solution::findWords)