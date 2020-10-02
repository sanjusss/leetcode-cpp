#pragma once
#include "leetcode.h"

class Solution 
{
public:
    Solution(vector<int>& nums) :
        m_src(nums),
        m_arr(nums)
    {

    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() 
    {
        return m_src;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() 
    {
        //::shuffle(m_arr.begin(), m_arr.end(), m_rd);//一步到位
        uniform_int_distribution<int> dis;
        int max = m_arr.size() - 1;
        for (int i = max; i > 0; --i)
        {
            swap(m_arr[i], m_arr[dis(m_rd, uniform_int_distribution<int>::param_type(0, i))]);
        }

        return m_arr;
    }

private:
    vector<int> m_src;
    vector<int> m_arr;
    mt19937 m_rd = mt19937(time(nullptr));
};