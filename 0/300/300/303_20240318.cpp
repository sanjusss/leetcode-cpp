#include "leetcode.h"

class NumArray {
public:
    NumArray(vector<int>& nums) {
        m_sums.push_back(0);
        for (int i : nums) {
            m_sums.push_back(i + m_sums.back());
        }
    }
    
    int sumRange(int left, int right) {
        return m_sums[right + 1] - m_sums[left];
    }

private:
    vector<int> m_sums;
};