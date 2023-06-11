/*
 * @Author: sanjusss
 * @Date: 2023-06-11 16:44:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-11 16:53:01
 * @FilePath: \0\300\300\307_20230611.cpp
 */
#include "leetcode.h"

class NumArray {
public:
    NumArray(vector<int>& nums) : m_n(nums.size() + 1), m_prefix(nums.size() + 1), m_arr(nums.size()) {
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        add(index, val - m_arr[index]);
        m_arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        return sum(right) - sum(left - 1);
    }

private:
    int sum(int index) {
        int res = 0;
        index += 1;
        while (index > 0) {
            res += m_prefix[index];
            index -= index & -index;
        }

        return res;
    }

    void add(int index, int val) {
        index += 1;
        while (index < m_n) {
            m_prefix[index] += val;
            index += index & -index;
        }
    }

private:
    const int m_n;
    vector<int> m_prefix;
    vector<int> m_arr;
};