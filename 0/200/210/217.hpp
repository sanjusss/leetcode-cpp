#include "leetcode.h"

class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> vs(nums.begin(), nums.end());
        return vs.size() != nums.size();
    }

    //bool containsDuplicate(vector<int> &nums) 
    //{
    //    std::sort(nums.begin(), nums.end());
    //    int length = nums.size() - 1;
    //    for (int i = 0; i < length; ++i)
    //    {
    //        if (nums[i] == nums[i + 1])
    //        {
    //            return true;
    //        }
    //    }

    //    return false;
    //}


    //bool containsDuplicate(vector<int>& nums)
    //{
    //    set<int> vs;
    //    for (int i : nums)
    //    {
    //        if (vs.find(i) == vs.end())
    //        {
    //            vs.insert(i);
    //        }
    //        else
    //        {
    //            return true;
    //        }
    //    }

    //    return false;
    //}
};