#include "leetcode.h"

class NumArray {
public:
    NumArray(vector<int>& nums) : m_sum(nums.size() + 1) {
        for (int i = 0; i < nums.size(); ++i) {
            m_sum[i + 1] = m_sum[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return m_sum[j + 1] - m_sum[i];
    }

private:
    vector<int> m_sum;
};

