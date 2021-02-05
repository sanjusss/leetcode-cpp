#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> groupIds;
        for (int i = 0; i < groupSizes.size(); ++i) {
            groupIds[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> ans;
        for (auto& [size, arr] : groupIds) {
            for (int i = 0; i < arr.size(); ++i) {
                if (i % size == 0) {
                    ans.push_back({ arr[i] });
                }
                else {
                    ans.back().push_back(arr[i]);
                }
            }
        }

        return ans;
    }
};