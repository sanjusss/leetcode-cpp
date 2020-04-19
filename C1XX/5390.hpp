#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int minNumberOfFrogs(string croakOfFrogs) 
//    {
//        int size = croakOfFrogs.size();
//        if (size % 5 != 0)
//        {
//            return -1;
//        }
//
//        unordered_map<char, int> indeies =
//        {
//            { 'c', 0 },
//            { 'r', 1 },
//            { 'o', 2 },
//            { 'a', 3 },
//            { 'k', 4 }
//        };
//        vector<int> cs(5);
//        vector<vector<int>> poses(5);
//        for (int i = 0; i < size; ++i)
//        {
//            int index = indeies[croakOfFrogs[i]];
//            if (index > 0 && cs[index - 1] <= cs[index])
//            {
//                return -1;
//            }
//
//            ++cs[index];
//            int r = index - 1;
//            if (index == 0)
//            {
//                r = 4;
//            }
//
//            if (poses[r].size() > poses[index].size())
//            {
//                poses[index].push_back(i);
//                continue;
//            }
//
//            int j;
//            for (j = 0; j < poses[r].size(); ++j)
//            {
//                if (poses[r][j] < i && poses[r][j] > poses[index][j])
//                {
//                    break;
//                }
//            }
//
//            if (j == poses[r].size())
//            {
//                poses[index].push_back(i);
//            }
//            else
//            {
//                poses[index][j] = i;
//            }
//        }
//
//        return poses[0].size();
//    }
//};

class Solution
{
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {
        int size = croakOfFrogs.size();
        if (size % 5 != 0)
        {
            return -1;
        }

        unordered_map<char, int> indeies =
        {
            { 'c', 0 },
            { 'r', 1 },
            { 'o', 2 },
            { 'a', 3 },
            { 'k', 4 }
        };
        vector<int> cs(5);
        int remains = 0;
        int reuse = 0;
        for (int i = 0; i < size; ++i)
        {
            int index = indeies[croakOfFrogs[i]];
            if (index > 0 && cs[index - 1] <= cs[index])
            {
                return -1;
            }

            ++cs[index];
            if (index == 0 && remains > 0)
            {
                ++reuse;
                --remains;
            }

            if (index == 4)
            {
                ++remains;
            }
        }

        return cs[0] - reuse;
    }
};