#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int minInsertions(string s) 
    {
        int size = s.size();
        //��s�������������
        //dp[i][j]��ʾ�ַ���s[i,j]��������Ӵ����ȡ�
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for (int i = size - 1; i >= 0; --i)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < size; ++j)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return size - dp[0][size - 1];
    }
};