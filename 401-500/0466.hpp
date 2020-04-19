#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int getMaxRepetitions(string s1, int n1, string s2, int n2) 
//    {
//        int size1 = s1.size();
//        int size2 = s2.size();
//        int max1 = size1 * n1;
//        int max2 = size2 * n2;
//        int ans = 0;
//        for (int i = 0, j = 0; i < max1; ++i)
//        {
//            if (s1[i % size1] != s2[j % size2])
//            {
//                continue;
//            }
//
//            ++j;
//            if (j == max2)
//            {
//                j = 0;
//                ++ans;
//            }
//        }
//
//        return ans;
//    }
//};

//class Solution
//{
//public:
//    int getMaxRepetitions(string s1, int n1, string s2, int n2)
//    {
//        int c2 = 0;
//        int k = 0;
//        int maxK = s2.size() - 1;
//        int k0 = 0;
//        int c20 = 0;
//        int i0 = 0;
//        for (int i = 0; i < n1; ++i)
//        {
//            for (int j = 0; j < s1.size(); ++j)
//            {
//                if (s1[j] == s2[k])
//                {
//                    if (k == maxK)
//                    {
//                        k = 0;
//                        ++c2;
//                    }
//                    else
//                    {
//                        ++k;
//                    }
//                }
//            }
//
//            if (c20 == 0)
//            {
//                if (c2 > 0)
//                {
//                    c20 = c2;
//                    k0 = k;
//                    i0 = i;
//                }
//            }
//            else if (k == k0)
//            {
//                c2 = (n1 - 1 - i0) * (c2 - c20) / (i - i0) + c20;
//                break;
//            }
//        }
//
//        return c2 / n2;
//    }
//};

class Solution
{
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {
        int c2 = 0;
        int k = 0;
        int maxK = s2.size() - 1;
        int k0 = 0;
        vector<int> c2s;
        for (int i = 0; i < n1; ++i)
        {
            for (int j = 0; j < s1.size(); ++j)
            {
                if (s1[j] == s2[k])
                {
                    if (k == maxK)
                    {
                        k = 0;
                        ++c2;
                    }
                    else
                    {
                        ++k;
                    }
                }
            }

            c2s.push_back(c2);
            if (i == 0)
            {
                k0 = k;
            }
            else if (k == k0)
            {
                c2 = (n1 - 1) / i * (c2 - c2s[0]) + c2s[0];
                c2 += c2s[(n1 - 1) % i] - c2s[0];
                break;
            }
        }

        return c2 / n2;
    }
};