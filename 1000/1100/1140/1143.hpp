#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int longestCommonSubsequence(string text1, string text2) 
//    {
//        if (text1.size() > text2.size())
//        {
//            text1.swap(text2);
//        }
//
//        int longest = 0;
//        int size = text1.size();
//        int maxTimes = (1 << size);
//        for (int i = 1; i <= maxTimes; ++i)
//        {
//            int lastIndex = -1;
//            int length = 0;
//            for (int j = 0; j < size; ++j)
//            {
//                if ((1 << j) & i)
//                {
//                    ++length;
//                    lastIndex = text2.find_first_of(text1[j], lastIndex + 1);
//                    if (lastIndex < 0)
//                    {
//                        break;
//                    }
//                }
//            }
//
//            if (lastIndex >= 0)
//            {
//                longest = max(length, longest);
//            }
//        }
//
//        return longest;
//    }
//};

class Solution 
{
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int size1 = text1.size();
        int size2 = text2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));//dp[i][j]表示text1[0,i-1]和text2[0,j-1]的最长公共子串。
        for (int i = 0; i < size1; ++i)
        {
            for (int j = 0; j < size2; ++j)
            {
                if (text1[i] == text2[j])
                {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }
                else
                {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[size1][size2];
    }
};