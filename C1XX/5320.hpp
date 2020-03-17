#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) 
    {
        map<int, set<int>> ratings;
        for (auto& r : restaurants)
        {
            if (veganFriendly > r[2] || maxPrice < r[3] || maxDistance < r[4])
            {
                continue;
            }

            ratings[r[1]].insert(r[0]);
        }

        vector<int> ans;
        for (auto i = ratings.rbegin(); i != ratings.rend(); ++i)
        {
            for (auto j = i->second.rbegin(); j != i->second.rend(); ++j)
            {
                ans.push_back(*j);
            }
        }

        return ans;
    }
};