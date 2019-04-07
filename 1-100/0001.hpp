#include "leetcode.h"

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        multimap<int, int> vs;
        int length = nums.size();
        for (int i = 0; i < length; ++i)
        {
            vs.insert(make_pair(nums[i], i));
        }

        auto endIter = vs.upper_bound(target / 2);
        int a;
        int b;
        for (auto i = vs.cbegin(); i != endIter; ++i)
        {
            a = i->first;
            b = target - a;
            if (a == b)
            {
                int index = i->second;
                ++i;
                if (i != vs.cend())
                {
                    return { index, i->second };
                }
            }
            else
            {
                auto bIter = vs.find(b);
                if (bIter != vs.cend())
                {
                    return { i->second, bIter->second };
                }
            }
        }

        return vector<int>();
    }
};