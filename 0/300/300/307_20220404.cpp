/*
 * @Author: sanjusss
 * @Date: 2022-04-04 14:26:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-04 15:34:05
 * @FilePath: \0\300\300\307_20220404.cpp
 */
#include "leetcode.h"

class NumArray {
public:
    NumArray(vector<int>& nums) : m_n(nums.size()) {
        m_nums.resize(m_n * 2);
        for (int i = 0; i < m_n; ++i) {
            m_nums[i + m_n] = nums[i];
        }

        for (int i = m_n - 1; i > 0; --i) {
            m_nums[i] = m_nums[i * 2] + m_nums[i * 2 + 1];
        }
    }
    
    void update(int index, int val) {
        index += m_n;
        int diff = val - m_nums[index];
        while (index > 0) {
            m_nums[index] += diff;
            index /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        left += m_n;
        right += m_n;
        int ans = 0;
        while (left <= right) {
            if (left % 2 == 1) {
                ans += m_nums[left++];
            }

            if (right % 2 == 0) {
                ans += m_nums[right--];
            }

            left /= 2;
            right /= 2;
        }

        return ans;
    }

private:
    const int m_n;
    vector<int> m_nums;
};