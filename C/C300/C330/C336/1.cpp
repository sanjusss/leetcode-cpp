#include "leetcode.h"

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        unordered_set<char> vowels = { 'a', 'i', 'u', 'e', 'o' };
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            if (vowels.count(words[i].front()) && vowels.count(words[i].back())) {
                ++ans;
            }
        }

        return ans;
    }
};