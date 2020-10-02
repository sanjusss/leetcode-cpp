#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        vector<string> res;
        int minSum = INT_MAX;
        unordered_map<string, int> hash_list1;
        int length = list1.size();
        for (int i = 0; i < length; ++i)
        {
            hash_list1[list1[i]] = i;
        }

        length = list2.size();
        for (int i = 0; i < length; ++i)
        {
            if (hash_list1.count(list2[i]) == 0)
            {
                continue;
            }

            if (hash_list1[list2[i]] + i > minSum)
            {
                continue;
            }

            if (hash_list1[list2[i]] + i < minSum)
            {
                res.clear();
                minSum = hash_list1[list2[i]] + i;
            }

            res.push_back(list2[i]);
        }

        return res;
    }
};