#include "leetcode.h"

class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int i = 0;
        int length = nums.size();
        for (int j = 0; j < length; ++j)
        {
            if (nums[j] != 0)
            {
                nums[i++] = nums[j];
            }
        }

        while (i < length)
        {
            nums[i++] = 0;
        }
    }
};