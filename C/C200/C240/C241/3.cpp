/*
 * @Author: sanjusss
 * @Date: 2021-05-16 10:27:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-16 11:03:08
 * @FilePath: \C\C200\C240\C241\3.cpp
 */
#include "leetcode.h"

class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : m_nums2(nums2.begin(), nums2.end()) {
        for (int i : nums1) {
            ++m_cnt1[i];
        }

        for (int i : nums2) {
            ++m_cnt2[i];
        }
    }
    
    void add(int index, int val) {
        --m_cnt2[m_nums2[index]];
        m_nums2[index] += val;
        ++m_cnt2[m_nums2[index]];
    }
    
    int count(int tot) {
        int ans = 0;
        for (auto& [k, c] : m_cnt1) {
            auto p = m_cnt2.find(tot - k);
            if (p != m_cnt2.end()) {
                ans += c * p->second;
            }
        }

        return ans;
    }

private:
    unordered_map<int, int> m_cnt1;
    vector<int> m_nums2;
    unordered_map<int, int> m_cnt2;
};