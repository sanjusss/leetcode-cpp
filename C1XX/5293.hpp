#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) 
    {
        unordered_map<string, int> subs;
        set<string> invailds;
        int res = 0;
        int length = s.length();
        for (int i = 0; i < length; ++i)
        {
            set<char> letters;
            string sub;
            for (int j = 0; j <= maxSize && i + j < length; ++j)
            {
                letters.insert(s[i + j]);
                sub += s[i + j];
                if (letters.size() > maxLetters)
                {
                    invailds.insert(sub);
                    break;
                }

                if (j + 1 < minSize)
                {
                    continue;
                }

                ++subs[sub];
                res = max(subs[sub], res);
            }
        }

        return res;
    }
};