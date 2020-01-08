#pragma once
#include "leetcode.h"

/*
在计算机界中，我们总是追求用有限的资源获取最大的收益。
现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。
你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。

注意:
给定 0 和 1 的数量都不会超过 100。
给定字符串数组的长度不会超过 600。

示例 1:
输入: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
输出: 4
解释: 总共 4 个字符串可以通过 5 个 0 和 3 个 1 拼出，即 "10","0001","1","0" 。

示例 2:
输入: Array = {"10", "0", "1"}, m = 1, n = 1
输出: 2
解释: 你可以拼出 "10"，但之后就没有剩余数字了。更好的选择是拼出 "0" 和 "1" 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ones-and-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//class Solution 
//{
//public:
//    int findMaxForm(vector<string>& strs, int m, int n) 
//    {
//        vector<pair<int, int>> resources;
//        for (auto& s : strs)
//        {
//            int count0 = 0;
//            int count1 = 0;
//            for (auto c : s)
//            {
//                if (c == '0')
//                {
//                    ++count0;
//                }
//                else
//                {
//                    ++count1;
//                }
//            }
//
//            resources.push_back({ count0, count1 });
//        }
//
//        int rsize = resources.size();
//        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//        vector<vector<vector<bool>>> used(m + 1, vector<vector<bool>>(n + 1, vector<bool>(rsize, false)));
//        for (int i = 0; i <= m; ++i)
//        {
//            for (int j = 0; j <= n; ++j)
//            {
//                for (int k = 0; k < rsize; ++k)
//                {
//                    int use0 = resources[k].first;
//                    int use1 = resources[k].second;
//                    if (i < use0 || j < use1 ||
//                        used[i - use0][j - use1][k])
//                    {
//                        continue;
//                    }
//
//                    if (dp[i][j] < dp[i - use0][j - use1] + 1)
//                    {
//                        dp[i][j] = dp[i - use0][j - use1] + 1;
//                        used[i][j] = used[i - use0][j - use1];
//                        used[i][j][k] = true;
//                    }
//                }
//            }
//        }
//
//        return dp[m][n];
//    }
//};

class Solution
{
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto& s : strs)
        {
            int count0 = 0;
            int count1 = 0;
            for (auto c : s)
            {
                if (c == '0')
                {
                    ++count0;
                }
                else
                {
                    ++count1;
                }
            }

            for (int i = m; i >= count0; --i)
            {
                for (int j = n; j >= count1; --j)
                {
                    dp[i][j] = max(dp[i][j], dp[i - count0][j - count1] + 1);
                }
            }
        }

        return dp[m][n];
    }
};