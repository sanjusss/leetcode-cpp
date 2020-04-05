#pragma once
#include "leetcode.h"

class Solution 
{
public:
    string longestDiverseString(int a, int b, int c) 
    {
        multimap<int, char> cc =
        {
            { a, 'a' },
            { b, 'b' },
            { c, 'c' }
        };

        pair<int, char> i = *cc.rbegin();
        pair<int, char> j = *next(cc.rbegin());
        pair<int, char> k = *cc.begin();
        string ans(i.first, i.second);

        int ipair = i.first / 2;
        int jp = j.first;
        for (int x = 0; x < ipair && jp > 0; ++x)
        {
            --jp;
            ans.insert((x + 1) * 3 - 1, 1, j.second);
        }

        if (jp > 0)
        {
            for (int x = 0; x < ipair && jp > 0; ++x)
            {
                --jp;
                ans.insert((x + 1) * 4 - 1, 1, j.second);
            }

            for (int x = 0; x < ipair && k.first > 0; ++x)
            {
                --k.first;
                ans.insert((x + 1) * 4 - 1, 1, k.second);
            }

            for (int x = 0; x < ipair && k.first > 0; ++x)
            {
                --k.first;
                ans.insert((x + 1) * 4 - 1, 1, k.second);
            }
        }
        else
        {
            for (int x = j.first; x < ipair && k.first > 0; ++x)
            {
                --k.first;
                ans.insert((x + 1) * 3 - 1, 1, k.second);
            }

            for (int x = 0; x < ipair && k.first > 0; ++x)
            {
                --k.first;
                ans.insert((x + 1) * 4 - 1, 1, k.second);
            }
        }

        int length = ans.size();
        while (length > 2 &&
            ans[length - 1] == ans[length - 2] &&
            ans[length - 2] == ans[length - 3])
        {
            --length;
        }

        return ans.substr(0, length);
    }
};