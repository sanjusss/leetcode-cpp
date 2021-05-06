#include "leetcode.h"

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans{ first };
        int prev = first;
        for (int i : encoded) {
            prev = i ^ prev;
            ans.push_back(prev);
        }

        return ans;
    }
};

TEST(&Solution::decode)