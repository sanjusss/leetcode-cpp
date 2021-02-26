#include "leetcode.h"

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> all(26); 
        for (auto& s : words) {
            int key = 0;
            for (char i : s) {
                key |= 1 << (i - 'a');
            }

            ++all[key];
        }

        vector<int> ans;
        ans.reserve(puzzles.size());
        for (auto& s : puzzles) {
            int first = 1 << (s[0] - 'a');
            int key = 0;
            for (int i = 1; i < 7; ++i) {
                key |= 1 << (s[i] - 'a');
            }

            int count = 0;
            int sub = key;
            do {
                auto pos = all.find(sub | first);
                if (pos != all.end()) {
                    count += pos->second;
                }

                sub = (sub - 1) & key;
            } while (sub != key);

            ans.push_back(count);
        }

        return ans;
    }
};

TEST(&Solution::findNumOfValidWords)