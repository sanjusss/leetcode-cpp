/*
 * @Author: sanjusss
 * @Date: 2023-11-13 08:42:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-11-13 09:06:29
 * @FilePath: \0\300\300\307_20231113.cpp
 */
#include "leetcode.h"

class NumArray {
public:
    NumArray(vector<int>& nums) : m_n(nums.size()), m_arr(nums.size() + 1), m_src(nums.size()) {
        for (int i = 0; i < m_n; ++i) {
            update(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        int diff = val - m_src[index];
        m_src[index] = val;
        int i = index + 1;
        while (i <= m_n) {
            m_arr[i] += diff;
            i += lowbit(i);
        }
    }
    
    int sumRange(int left, int right) {
        return querySum(right) - querySum(left - 1);
    }

private:
    // sum [0, i]
    int querySum(int i) {
        i += 1;
        int sum = 0;
        while (i > 0) {
            sum += m_arr[i];
            i -= lowbit(i);
        }

        return sum;
    }

private:
    int lowbit(int x) {
        return x & -x;
    }

private:
    const int m_n;
    vector<int> m_arr;
    vector<int> m_src;
};
