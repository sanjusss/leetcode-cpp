/*
 * @Author: sanjusss
 * @Date: 2023-05-05 08:50:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-05 08:52:32
 * @FilePath: \2000\2400\2430\2432.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int id = -1;
        int t = 0;
        int pre = 0;
        for (auto& l : logs) {
            int use = l[1] - pre;
            if (use > t) {
                t = use;
                id = l[0];
            }
            else if (use == t) {
                id = min(id, l[0]);
            }

            pre = l[1];
        }

        return id;
    }
};