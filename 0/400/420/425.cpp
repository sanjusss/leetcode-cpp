#include "leetcode.h"

class Solution {
    struct Trie {
        array<Trie*, 26> children = { 0 };
    };

    class TrieRoot : public Trie {
    public:
        TrieRoot(int size, int n) : m_nodes(size * n), m_n(n) {

        }

        void insert(const string& s) {
            Trie* cur = this;
            for (char i : s) {
                if (cur->children[i - 'a'] == nullptr) {
                    cur->children[i - 'a'] = &(m_nodes[m_next++]);
                }

                cur = cur->children[i - 'a'];
            }
        }

        void dfs() {
            vector<string> arr(m_n, string(m_n, ' '));
            vector<Trie*> nodes(m_n, this);
            select(arr, nodes, 0, 0);
        }

    private:
        void select(vector<string>& arr, vector<Trie*>& nodes, int row, int col) {
            if (col < m_n) {
                for (int i = 0; i < 26; ++i) {
                    if (nodes[row]->children[i] == nullptr) {
                        continue;
                    }

                    if (col > row && nodes[col]->children[i] == nullptr) {
                        continue;
                    }

                    arr[row][col] = i + 'a';
                    Trie* oldNode = nodes[row];
                    nodes[row] = nodes[row]->children[i];

                    Trie* oldMirrorNode = nodes[col];
                    if (col > row) {
                        arr[col][row] = i + 'a';
                        nodes[col] = nodes[col]->children[i];
                    }

                    select(arr, nodes, row, col + 1);

                    nodes[row] = oldNode;
                    if (col > row) {
                        nodes[col] = oldMirrorNode;
                    }
                }
            }
            else {
                if (row < m_n) {
                    select(arr, nodes, row + 1, row + 1);
                }
                else {
                    ans.push_back(arr);
                }
            }
        }

    public:
        vector<vector<string>> ans;

    private:
        vector<Trie> m_nodes;
        int m_next = 0;
        const int m_n;
    };

public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words[0].size();
        TrieRoot trie(words.size(), n);
        for (auto& i : words) {
            trie.insert(i);
        }

        trie.dfs();
        return move(trie.ans);
    }
};

TEST_EQUIVALENT(&Solution::wordSquares)