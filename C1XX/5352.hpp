#pragma once
#include "leetcode.h"

class Solution 
{
public:
    string generateTheString(int n) 
    {
        string ans(n, 'a');
        if (n % 2 == 0)
        {
            ans.back() = 'b';
        }

        return ans;
    }
};