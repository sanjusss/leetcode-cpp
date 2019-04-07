#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int videoStitching(vector<vector<int>>& clips, int T) 
    {
        int minC = INT_MAX;
        int maxC = INT_MIN;
        map<int, int> parts;
        for (auto i : clips)
        {
            minC = min(i[0], minC);
            maxC = max(i[1], maxC);
            bool success = true;
            for (auto j = parts.begin(); j != parts.end();)
            {
                if (i[0] >= j->first && i[1] <= j->second)
                {
                    success = false;
                    break;
                }

                if (i[0] <= j->first && i[1] >= j->second)
                {
                    parts.erase(j++);
                }
                else
                {
                    ++j;
                }
            }

            if (success)
            {
                parts.insert({ i[0], i[1] });
            }
        }

        if (minC > 0 || maxC < T)
        {
            return -1;
        }

        for (auto i = parts.begin(); i != prev(parts.end());)
        {
            if (i->second >= T)
            {
                return distance(parts.begin(), i) + 1;
            }

            if (i == parts.begin())
            {
                ++i;
                continue;
            }

            if (prev(i)->second >= next(i)->first)
            {
                parts.erase(i++);
            }
            else
            {
                ++i;
            }
        }

        return parts.size();
    }
};