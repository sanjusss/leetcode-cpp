#include "leetcode.h"

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int, int> suf;
        for (int i : nums) {
            ++suf[i];
        }

        vector<int> ans;
        unordered_set<int> pre;
        for (int i : nums) {
            pre.insert(i);
            if (--suf[i] == 0) {
                suf.erase(i);
            }

            ans.push_back(pre.size() - suf.size());
        }

        return ans;
    }
};