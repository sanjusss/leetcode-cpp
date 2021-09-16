/*
 * @Author: sanjusss
 * @Date: 2021-09-16 08:37:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-16 10:59:57
 * @FilePath: \0\200\210\212_20210916.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         int m = board.size();
//         int n = board[0].size();
//         function<bool(int,int,const string&, int)> dfs = [&](int i, int j, const string& w, int wi) {
//             if (board[i][j] != w[wi]) {
//                 return false;
//             }

//             if (++wi == w.size()) {
//                 return true;
//             }

//             char c = board[i][j];
//             board[i][j] = 0;
//             static const vector<pair<int, int>> dirs = {
//                 { 1, 0 },
//                 { -1, 0 },
//                 { 0, 1 },
//                 { 0, -1 }
//             };
//             bool success = false;
//             for (auto [dx, dy] : dirs) {
//                 int x = i + dx;
//                 int y = j + dy;
//                 if (x < 0 || x >= m || y < 0 || y >= n) {
//                     continue;
//                 }

//                 if (dfs(x, y, w, wi)) {
//                     success = true;
//                     break;
//                 }
//             }

//             board[i][j] = c;
//             return success;
//         };

//         vector<string> ans;
//         for (string& w : words) {
//             bool success = false;
//             for (int i = 0; i < m && !success; ++i) {
//                 for (int j = 0; j < n && !success; ++j) {
//                     if (dfs(i, j, w, 0)) {
//                         success = true;
//                     }
//                 }
//             }

//             if (success) {
//                 ans.push_back(move(w));
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
//     struct Node {
//         array<Node*, 26> children = { 0 };
//     };

// public:
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         int m = board.size();
//         int n = board[0].size();
//         function<void(int, int, Node*)> dfs = [&](int i, int j, Node* node) {
//             char c = board[i][j];
//             board[i][j] = 0;
//             if (node->children[c - 'a'] == nullptr) {
//                 node->children[c - 'a'] = new Node();
//             }

//             node = node->children[c - 'a'];
//             static const vector<pair<int, int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
//             for (auto [dx, dy] : dirs) {
//                 int x = i + dx;
//                 int y = j + dy;
//                 if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == 0) {
//                     continue;
//                 }
                
//                 dfs(x, y, node);
//             }

//             board[i][j] = c;
//         };

//         Node* tree = new Node();
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 dfs(i, j, tree);
//             }
//         }

//         vector<string> ans;
//         for (string& w : words) {
//             bool success = true;
//             Node* node = tree;
//             for (char i : w) {
//                 if (node == nullptr) {
//                     success = false;
//                     break;
//                 }
                
//                 node = node->children[i - 'a'];
//             }

//             if (success) {
//                 ans.push_back(move(w));
//             }
//         }

//         return ans;
//     }
// };

class Solution {
    struct Node {
        bool end = false;
        int cnt = 0;
        array<Node*, 26> children = { 0 };
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        vector<string> ans;
        function<int(int, int, string&, Node*)> dfs = [&](int i, int j, string& temp, Node* node) -> int{
            char c = board[i][j];
            if (c == 0) {
                return 0;
            }
            
            node = node->children[c - 'a'];
            if (node == nullptr || node->cnt == 0) {
                return 0;
            }

            temp.push_back(c);
            board[i][j] = 0;
            int res = 0;
            if (node->end) {
                node->end = false;
                ++res;
                ans.push_back(temp);
            }

            static const vector<pair<int, int>> dirs = {
                { 1, 0 },
                { -1, 0 },
                { 0, 1 },
                { 0, -1 }
            };
            for (auto [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }
                
                res += dfs(x, y, temp, node);
            }

            board[i][j] = c;
            temp.pop_back();
            node->cnt -= res;
            return res;
        };

        Node* tree = new Node();
        for (auto& s : words) {
            auto node = tree;
            for (char i : s) {
                if (node->children[i - 'a'] == nullptr) {
                    node->children[i - 'a'] = new Node();
                }

                node = node->children[i - 'a'];
                ++node->cnt;
            }

            node->end = true;
        }

        string temp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(i, j, temp, tree);
            }
        }

        return ans;
    }
};

TEST_EQUIVALENT(&Solution::findWords)