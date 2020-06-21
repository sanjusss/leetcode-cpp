#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    vector<int> avoidFlood(vector<int>& rains) 
//    {
//        unordered_map<int, int> full;
//        vector<int> sunny;
//        vector<int> acts(rains.size(), -1);
//        for (int i = 0; i < rains.size(); ++i)
//        {
//            if (rains[i] > 0)
//            {
//                if (full.find(rains[i]) == full.end())
//                {
//                    full[rains[i]] = i;
//                }
//                else if (sunny.empty())
//                {
//                    return vector<int>();
//                }
//                else
//                {
//                    auto j = upper_bound(sunny.begin(), sunny.end(), full[rains[i]]);
//                    if (j == sunny.end())
//                    {
//                        return vector<int>();
//                    }
//
//                    acts[*j] = rains[i];
//                    sunny.erase(j);
//                    full[rains[i]] = i;
//                }
//            }
//            else
//            {
//                sunny.push_back(i);
//            }
//        }
//
//        for (int i : sunny)
//        {
//            acts[i] = 1;
//        }
//
//        return acts;
//    }
//};

class Solution
{
public:
    vector<int> avoidFlood(vector<int>& rains)
    {
        unordered_map<int, int> full;
        vector<int> sunny;
        vector<int> acts(rains.size(), -1);
        for (int i = 0; i < rains.size(); ++i)
        {
            if (rains[i] > 0)
            {
                if (full.find(rains[i]) == full.end())
                {
                    full[rains[i]] = i;
                }
                else if (sunny.empty())
                {
                    return vector<int>();
                }
                else
                {
                    auto j = upper_bound(sunny.begin(), sunny.end(), full[rains[i]]);
                    if (j == sunny.end())
                    {
                        return vector<int>();
                    }

                    acts[*j] = rains[i];
                    sunny.erase(j);
                    full[rains[i]] = i;
                }
            }
            else
            {
                sunny.push_back(i);
            }
        }

        for (int i : sunny)
        {
            acts[i] = 1;
        }

        return acts;
    }
};