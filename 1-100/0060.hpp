#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    string getPermutation(int n, int k) 
//    {
//        string nums;
//        for (int i = 1; i <= n; ++i)
//        {
//            nums.push_back(i + '0');
//        }
//
//        while (--k > 0)
//        {
//            next_permutation(nums.begin(), nums.end());
//        }
//        return nums;
//    }
//};

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> fn(n, 1);
        for (int i = 1; i < n; ++i)
        {
            fn[i] = i * fn[i - 1];
        }

        vector<int> used(n + 1, 0);

        string ans;
        --k;//让k从0开始计算。
        int r = n;
        while (--r >= 0)
        {
            int i = k / fn[r];
            k %= fn[r];
            for (int j = 1; j <= n; ++j)
            {
                if (used[j] == 1)
                {
                    continue;
                }

                if (i == 0)
                {
                    used[j] = 1;
                    ans.push_back(j + '0');
                    break;
                }
                else
                {
                    --i;
                }
            }
        }

        return ans;
    }
};