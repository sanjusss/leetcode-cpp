/*
 * @Author: sanjusss
 * @Date: 2021-06-25 08:15:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-25 08:46:20
 * @FilePath: \0\700\750\752_20210625.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int des = toInt(target);
        if (des == 0) {
            return 0;
        }

        vector<int> used(10000);
        for (auto& s : deadends) {
            used[toInt(s)] = true;
        }

        if (used[0]) {
            return -1;
        }

        used[0] = true;
        int turns = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            ++turns;
            for (int i = q.size(); i > 0; --i) {
                int cur = q.front();
                q.pop();
                int temp = cur;
                for (int b = 1; b <= 1000; b *= 10) {
                    int curB = temp % 10;
                    int sign = 1;
                    for (int j = 0; j < 2; ++j) {
                        int nextB = curB + sign;
                        if (nextB < 0) {
                            nextB = 9;
                        }
                        else if (nextB > 9) {
                            nextB = 0;
                        }

                        int next = cur + (nextB - curB) * b;
                        if (des == next) {
                            return turns;
                        }
                        if (!used[next]) {
                            used[next] = true;
                            q.push(next);
                        }

                        sign *= -1;
                    }

                    temp /= 10;
                    
                }
            }
        }

        return -1;
    }

private:
    static int toInt(const string& s) {
        return (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
    }
};

TEST(&Solution::openLock)