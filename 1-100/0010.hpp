#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    bool isMatch(string s, string p) 
//    {
//        //dp[i][j] 表示 s 的前 i 个是否能被 p 的前 j 个匹配
//        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1));
//        dp[0][0] = true;
//        //s 的前 0 个是否能被 p 的前 j 个匹配
//        for (size_t j = 1; j < p.size(); ++j)
//        {
//            if (p[j] == '*')
//            {
//                dp[0][j + 1] = dp[0][j - 1];
//            }
//        }
//
//        for (size_t i = 0; i < s.size(); ++i)
//        {
//            for (size_t j = 0; j < p.size(); ++j)
//            {
//                if (s[i] == p[j] || p[j] == '.')//匹配单个字符
//                {
//                    dp[i + 1][j + 1] = dp[i][j];
//                }
//                else if (p[j] == '*' && j > 0)
//                {
//                    if (s[i] != p[j - 1] && p[j - 1] != '.')//前一对字符匹配
//                    {
//                        dp[i + 1][j + 1] = dp[i + 1][j - 1];
//                    }
//                    else
//                    {
//                        dp[i + 1][j + 1] = dp[i][j + 1] || //*表示匹配超过一个字符(s[i]、s[i-1]和p[j-1])
//                            //dp[i + 1][j] || //*表示只匹配一个字符（s[i]和p[j-1]）
//                            dp[i + 1][j - 1];//*表示0个匹配
//                    }
//                }
//            }
//        }
//
//        return dp[s.size()][p.size()];
//    }
//};

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int sl = s.size();
        int pl = p.size();
        vector<vector<bool>> dp(sl + 1, vector<bool>(pl + 1));
        dp[0][0] = true;
        for (int j = 1; j <= pl; ++j)
        {
            if (p[j - 1] == '*')
            {
                dp[0][j] = j >= 2 && dp[0][j - 2];
            }
        }

        for (int i = 1; i <= sl; ++i)
        {
            for (int j = 1; j <= pl; ++j)
            {
                if (p[j - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    if (j == 1)
                    {
                        continue;
                    }

                    dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || ((dp[i - 1][j - 1] || dp[i - 1][j]) && (p[j - 2] == '.' || s[i - 1] == p[j - 2]));
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
                }
            }
        }

        return dp[sl][pl];
    }
};