/*
 * @Author: sanjusss
 * @Date: 2023-07-26 08:16:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-26 11:37:33
 * @FilePath: \2000\2500\2560\2569.cpp
 */
#include "leetcode.h"

class Tree {
public:
    Tree(const vector<int>& nums) : m_n(nums.size()) {
        m_sums.resize(m_n * 2);
        m_lefts.resize(m_n * 2, INT_MAX);
        m_rights.resize(m_n * 2, INT_MIN);
        m_updates.resize(m_n * 2);
        for (int i = 0; i < m_n; ++i) {
            for (int j = i + m_n; j > 0; j /= 2) {
                m_sums[j] += nums[i];
                m_lefts[j] = min(m_lefts[j], i);
                m_rights[j] = max(m_rights[j], i);
            }
        }
    }

    int sum() {
        return m_sums[1];
    }

    void flip(int left, int right) {
        update(1, left, right);
    }

private:
    void update(int i, int left, int right) {
        if (m_updates[i] == 1) {
            m_sums[i] = m_rights[i] - m_lefts[i] + 1 - m_sums[i];
            if (i < m_n) {
                m_updates[i * 2] ^= 1;
                m_updates[i * 2 + 1] ^= 1;
            }

            m_updates[i] = 0;
        }

        if (m_rights[i] < left || m_lefts[i] > right) {
            return;
        }

        if (m_lefts[i] >= left && m_rights[i] <= right) {
            m_sums[i] = m_rights[i] - m_lefts[i] + 1 - m_sums[i];
            if (i < m_n) {
                m_updates[i * 2] ^= 1;
                m_updates[i * 2 + 1] ^= 1;
            }

            return;
        }
        else if (i >= m_n) {
            return;
        }

        update(i * 2, left, right);
        update(i * 2 + 1, left, right);
        m_sums[i] = m_sums[i * 2] + m_sums[i * 2 + 1];
    }

private:
    const int m_n;
    vector<int> m_sums;
    vector<int> m_lefts;
    vector<int> m_rights;
    vector<int> m_updates;
};

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        Tree tree(nums1);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0ll);
        vector<long long> ans;
        for (auto& q : queries) {
            if (q[0] == 3) {
                ans.push_back(sum2);
            }
            else if (q[0] == 2) {
                sum2 += (long long)tree.sum() * q[1];
            }
            else {
                tree.flip(q[1], q[2]);
            }
        }

        return ans;
    }
};

TEST(&Solution::handleQuery)