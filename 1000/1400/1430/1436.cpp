/*
 * @Author: sanjusss
 * @Date: 2021-10-01 13:00:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-01 13:03:38
 * @FilePath: \1000\1400\1430\1436.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> start;
        unordered_set<string> stop;
        for (auto& p : paths) {
            start.insert(p[0]);
            stop.insert(p[1]);
        }

        for (auto& i : stop) {
            if (!start.count(i)) {
                return i;
            }
        }
        
        return {};
    }
};

TEST(&Solution::destCity)