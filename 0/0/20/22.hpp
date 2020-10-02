#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    vector<string> generateParenthesis(int n) 
//    {
//        vector<string> ans;
//        backTrace(ans, "", 0, 0, n);
//        return ans;
//    }
//
//private:
//    void backTrace(vector<string>& ans, string cur, int open, int close, int n)
//    {
//        if (open < n)
//        {
//            backTrace(ans, cur + "(", open + 1, close, n);
//        }
//
//        if (close < open)
//        {
//            backTrace(ans, cur + ")", open, close + 1, n);
//        }
//
//        if (open == n && close == n)
//        {
//            ans.push_back(cur);
//        }
//    }
//};

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> dp(n + 1);
        dp[0] = { "" };
        if (n >= 1)
        {
            dp[1] = { "()" };
        }

        for (int i = 2; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                for (auto& k : dp[j])
                {
                    for (auto& l : dp[i - j - 1])
                    {
                        dp[i].push_back("(" + k + ")" + l);
                    }
                }
            }
        }

        return dp[n];
    }
};