/*
 * @Author: sanjusss
 * @Date: 2024-04-26 08:35:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-04-26 08:44:20
 * @FilePath: \1000\1100\1140\1146.cpp
 */
#include "leetcode.h"

class SnapshotArray {
public:
    SnapshotArray(int length) : m_data(length, vector<pair<int, int>>(1)) {

    }
    
    void set(int index, int val) {
        auto &arr = m_data[index];
        if (arr.back().first != m_curSnap) {
            arr.emplace_back(m_curSnap, val);
        }
        else {
            arr.back().second = val;
        }
    }
    
    int snap() {
        return m_curSnap++;
    }
    
    int get(int index, int snap_id) {
        auto &arr = m_data[index];
        auto p = upper_bound(arr.begin(), arr.end(), snap_id, [](const int &a, const pair<int, int> &b) {
            return a < b.first;
        });
        return prev(p)->second;
    }

private:
    int m_curSnap = 0;
    vector<vector<pair<int, int>>> m_data;
};
