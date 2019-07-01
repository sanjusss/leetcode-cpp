#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> f;
        for (int i : nums)
        {
            ++f[i];
        }

        multimap<int, int> m;
        for (auto i : f)
        {
            m.insert(make_pair(i.second, i.first));
        }

        vector<int> results;
        for (auto i = m.rbegin(); k > 0 && i != m.rend(); ++i, --k)
        {
            results.push_back(i->second);
        }

        return results;
    }
};