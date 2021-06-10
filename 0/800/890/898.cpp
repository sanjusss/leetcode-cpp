/*
 * @Author: sanjusss
 * @Date: 2021-06-10 08:34:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-10 09:19:33
 * @FilePath: \0\800\890\898.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> all;
        set<int> cur{ 0 };
        set<int> prev;
        for (int i : arr) {
            swap(cur, prev);
            cur.clear();
            cur.insert(i);
            for (int j : prev) {
                i |= j;
                cur.insert(i);
            }

            for (int j : cur) {
                all.insert(j);
            }
        }

        return all.size();
    }
};

TEST(&Solution::subarrayBitwiseORs)