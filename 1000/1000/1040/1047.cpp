#include "leetcode.h"

class Solution {
public:
    string removeDuplicates(string S) {
        string ans;
        for (char i : S) {
            if (!ans.empty() && ans.back() == i) {
                ans.pop_back();
            }
            else {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

TEST(&Solution::removeDuplicates)