#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool validPalindrome(string s) 
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            if (s[left] == s[right])
            {
                ++left;
                --right;
            }
            else
            {
                return isValid(s, left + 1, right) || isValid(s, left, right - 1);
            }
        }

        return true;
    }

private:
    bool isValid(const string& s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            else
            {
                ++left;
                --right;
            }
        }

        return true;
    }
};