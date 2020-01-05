#pragma once
#include "leetcode.h"

class Solution 
{
    inline std::string replaceAllString(std::string str, const std::string& from, const std::string& to)
    {
        size_t start_pos = 0;
        while ((start_pos = str.find(from, start_pos)) != std::string::npos)
        {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
        }

        return str;
    }

public:
    string freqAlphabets(string s)
    {
        for (int i = 26; i >= 10; --i)
        {
            s = replaceAllString(s, to_string(i) + "#", string() + (char)('a' + i - 1));
        }

        for (int i = 9; i >= 1; --i)
        {
            s = replaceAllString(s, to_string(i), string() + (char)('a' + i - 1));
        }

        return s;
    }
};