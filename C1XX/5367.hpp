#pragma once
#include "leetcode.h"

class Solution 
{
public:
    string longestPrefix(string s) 
    {
        int size = s.size(); 
        string_view prefix = s;
        string_view suffix = s;
        for (int i = size - 1; i > 0; --i)
        {
            prefix.remove_prefix(1);
            suffix.remove_suffix(1);
            if (prefix == suffix)
            {
                return string(prefix);
            }
        }

        return string();
    }
};