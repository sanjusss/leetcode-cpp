#include "leetcode.h"

class Solution {
    struct Trie {
        ~Trie() {
            for(auto& i : children) {
                delete i;
                i = nullptr;
            }
        }

        void insert(int n) {
            auto cur = this;
            int t;
            for (int i = 30; i >= 0; --i) {
                t = ((1 << i) & n) >> i;
                if (cur->children[t] == nullptr) {
                    cur->children[t] = new Trie();
                }

                cur = cur->children[t];
            }
        }

        int findMaximumXOR(int n) const {
            int ans = 0;
            int t;
            auto cur = this;
            for (int i = 30; i >= 0; --i) {
                t = ((1 << i) & n) >> i;
                if (cur->children[1 - t] != nullptr) {
                    ans += 1 << i;
                    cur = cur->children[1 - t];
                }
                else if (cur->children[t] != nullptr) {
                    cur = cur->children[t];
                }
                else {
                    return 0;
                }
            }

            return ans;
        }

        array<Trie*, 2> children = { 0 };
    };

public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int ans = 0;
        for (int i : nums) {
            ans = max(trie.findMaximumXOR(i), ans);
            trie.insert(i);
        }

        return ans;
    }
};

TEST(&Solution::findMaximumXOR)