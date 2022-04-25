/*
 * @Author: sanjusss
 * @Date: 2022-04-25 08:49:51
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-25 08:57:18
 * @FilePath: \0\300\390\398.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     Solution(vector<int>& nums) {
//         int n = nums.size();
//         for (int i = 0; i < n; ++i) {
//             m_pos[nums[i]].push_back(i);
//         }
//     }
    
//     int pick(int target) {
//         const auto& arr = m_pos[target];
//         return arr[rand() % arr.size()];
//     }

// private:
//     unordered_map<int, vector<int>> m_pos;
// };

class Solution {
public:
    Solution(vector<int>& nums) : m_nums(nums) {
        
    }
    
    int pick(int target) {
        int n = m_nums.size();
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (m_nums[i] != target) {
                continue;
            }

            ++cnt;
            if (rand() % cnt == 0) {
                ans = i;
            }
        }

        return ans;
    }

private:
    const vector<int>& m_nums; 
};