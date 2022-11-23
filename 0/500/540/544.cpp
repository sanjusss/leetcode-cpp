/*
 * @Author: sanjusss
 * @Date: 2022-11-23 08:55:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-23 09:10:39
 * @FilePath: \0\500\540\544.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string findContestMatch(int n) {
        vector<int> arr(n);
        arr[0] = 1;
        arr[1] = 2;
        for (int cnt = 2; cnt < n; cnt *= 2) {
            int sum = cnt * 2 + 1;
            for (int i = cnt - 1; i >= 0; --i) {
                arr[i * 2] = arr[i];
                arr[i * 2 + 1] = sum - arr[i * 2];
            }
        }

        queue<string> q;
        for (int i : arr) {
            q.push(to_string(i));
        }

        while (q.size() > 1) {
            string a = q.front();
            q.pop();
            string b = q.front();
            q.pop();
            q.push("("s + a + ","s + b + ")");
        }

        return q.front();
    }
};