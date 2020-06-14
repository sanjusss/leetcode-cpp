#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
        if (arr.size() <= k)
        {
            return 0;
        }

        unordered_map<int, int> vc;
        for (int i : arr)
        {
            ++vc[i];
        }

        map<int, int> cc;
        for (auto& p : vc)
        {
            ++cc[p.second];
        }

        int ans = 0;
        for (auto& p : cc)
        {
            if (k > 0)
            {
                if (k >= p.first * p.second)
                {
                    k -= p.first * p.second;
                }
                else
                {
                    ans += p.second - k / p.first;
                    k = 0;
                }
            }
            else
            {
                ans += p.second;
            }
        }

        return ans;
    }
};