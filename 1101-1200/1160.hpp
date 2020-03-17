#pragma once
#include "leetcode.h"

class Solution
{
public:
    int countCharacters(vector<string>& words, string chars)
    {
        array<int, 26> src;
        src.fill(0);
        for (auto i : chars)
        {
            ++src[i - 'a'];
        }

        array<int, 26> des;
        int ans = 0;
        for (auto& word : words)
        {
            des.fill(0);
            bool success = true;
            for (auto i : word)
            {
                ++des[i - 'a'];
                if (des[i - 'a'] > src[i - 'a'])
                {
                    success = false;
                    break;
                }
            }

            if (success)
            {
                ans += word.size();
            }
        }

        return ans;
    }
};