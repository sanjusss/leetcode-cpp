#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int majorityElement(vector<int>& nums) 
//    {
//        unordered_map<int, int> cs;
//        for (auto i : nums)
//        {
//            ++cs[i];
//        }
//
//        pair<int, int> ans = *cs.begin();
//        for (auto i = next(cs.begin()); i != cs.end(); ++i)
//        {
//            if (i->second > ans.second)
//            {
//                ans = *i;
//            }
//        }
//
//        return ans.first;
//    }
//};

//Boyer - Moore 投票算法
/*
本质上， Boyer-Moore 算法就是找 nums 的一个后缀 sufsuf ，其中 suf[0]suf[0] 就是后缀中的众数。
我们维护一个计数器，如果遇到一个我们目前的候选众数，就将计数器加一，否则减一。
只要计数器等于 0 ，我们就将 nums 中之前访问的数字全部 忘记 ，并把下一个数字当做候选的众数。

作者：LeetCode
链接：https://leetcode-cn.com/problems/majority-element/solution/qiu-zhong-shu-by-leetcode-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int ans = 0;
        int records = 0;
        for (auto i : nums)
        {
            if (records == 0)
            {
                ans = i;
                ++records;
            }
            else if (i == ans)
            {
                ++records;
            }
            else
            {
                --records;
            }
        }

        return ans;
    }
};