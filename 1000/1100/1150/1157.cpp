/*
 * @Author: sanjusss
 * @Date: 2023-04-16 16:00:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-16 16:11:11
 * @FilePath: \1000\1100\1150\1157.cpp
 */
#include "leetcode.h"

class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            for (int b = 0; b < 16; ++b) {
                if (arr[i] & (1 << b)) {
                    m_0bitSum[b].push_back(m_0bitSum[b].back());
                    m_1bitSum[b].push_back(m_1bitSum[b].back() + 1);
                }
                else {
                    m_0bitSum[b].push_back(m_0bitSum[b].back() + 1);
                    m_1bitSum[b].push_back(m_1bitSum[b].back());
                }
            }

            m_valPos[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int threshold) {
        int val = 0;
        for (int b = 0; b < 16; ++b) {
            if (m_1bitSum[b][right + 1] - m_1bitSum[b][left] >= threshold) {
                val |= 1 << b;
            }
            else if (m_0bitSum[b][right + 1] - m_0bitSum[b][left] < threshold) {
                return -1;
            }
        }

        auto& pos = m_valPos[val];
        int cnt = upper_bound(pos.begin(), pos.end(), right) - lower_bound(pos.begin(), pos.end(), left);
        if (cnt >= threshold) {
            return val;
        }
        else {
            return -1;
        }
    }

private:
    vector<vector<int>> m_0bitSum{ 16, vector<int>(1) };
    vector<vector<int>> m_1bitSum{ 16, vector<int>(1) };
    vector<vector<int>> m_valPos{ 20001 };
};
