#pragma once
#include "leetcode.h"

class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int> results(num_people, 0);
        int maxi = (-1.0 + sqrt(1ll + 8ll * candies)) / 2.0;
        int times = maxi / num_people;
        for (int i = 0; i < num_people; ++i)
        {
            results[i] = (times - 1) * times / 2 * num_people + times * (i + 1);
        }

        int lastc = maxi % num_people;
        for (int i = 0; i < lastc; ++i)
        {
            results[i] += times * num_people + i + 1;
        }

        results[lastc] += candies - (maxi + 1) * maxi / 2;
        return results;
    }
};