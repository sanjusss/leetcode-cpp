#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int isPrefixOfWord(string sentence, string searchWord) 
    {
        int size = sentence.size() - searchWord.size();
        if (size < 0)
        {
            return -1;
        }

        bool lastIsSpace = true;
        int ans = 1;
        for (int i = 0; i < size; ++i)
        {
            if (sentence[i] == ' ')
            {
                lastIsSpace = true;
                ++ans;
            }
            else if (lastIsSpace)
            {
                lastIsSpace = false;
                bool success = true;
                for (int j = 0; j < searchWord.size(); ++j)
                {
                    if (sentence[i + j] != searchWord[j])
                    {
                        success = false;
                        break;
                    }
                }

                if (success)
                {
                    return ans;
                }
            }
        }

        bool success = true;
        for (int j = 0; j < searchWord.size(); ++j)
        {
            if (sentence[size + j] != searchWord[j])
            {
                success = false;
                break;
            }
        }

        if (success)
        {
            return ans;
        }
        else
        {
            return -1;
        }
    }
};