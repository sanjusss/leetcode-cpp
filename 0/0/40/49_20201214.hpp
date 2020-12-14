#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> vs;
        for (string& i : strs) {
            string key = i;
            sort(key.begin(), key.end());
            vs[key].push_back(move(i));
        }

        vector<vector<string>> ans;
        for (auto& p : vs) {
            ans.push_back(move(p.second));
        }

        return ans;
    }
};