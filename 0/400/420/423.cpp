/*
 * @Author: sanjusss
 * @Date: 2021-11-24 14:22:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-24 14:46:49
 * @FilePath: \0\400\420\423.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> cnt;
        for (char i : s) {
            ++cnt[i];
        }

        vector<int> nums(10);
        // 0
        if (cnt['z'] > 0) {
            nums[0] = cnt['z'];
            cnt['e'] -= cnt['z'];
            cnt['r'] -= cnt['z'];
            cnt['o'] -= cnt['z'];
            cnt['z'] = 0;
        }

        // 2
        if (cnt['t'] > 0) {
            nums[2] = cnt['w'];
            cnt['t'] -= cnt['w'];
            cnt['o'] -= cnt['w'];
            cnt['w'] = 0;
        }

        // 6
        if (cnt['x'] > 0) {
            nums[6] = cnt['x'];
            cnt['s'] -= cnt['x'];
            cnt['i'] -= cnt['x'];
            cnt['x'] = 0;
        }

        // 8
        if (cnt['g'] > 0) {
            nums[8] = cnt['g'];
            cnt['e'] -= cnt['g'];
            cnt['i'] -= cnt['g'];
            cnt['h'] -= cnt['g'];
            cnt['t'] -= cnt['g'];
            cnt['g'] = 0;
        }

        // 7
        if (cnt['s'] > 0) {
            nums[7] = cnt['s'];
            cnt['e'] -= cnt['s'] * 2;
            cnt['v'] -= cnt['s'];
            cnt['n'] -= cnt['s'];
            cnt['s'] = 0;
        }

        // 5
        if (cnt['v'] > 0) {
            nums[5] = cnt['v'];
            cnt['f'] -= cnt['v'];
            cnt['i'] -= cnt['v'];
            cnt['e'] -= cnt['v'];
            cnt['v'] = 0;
        }

        // 4
        if (cnt['u'] > 0) {
            nums[4] = cnt['u'];
            cnt['f'] -= cnt['u'];
            cnt['o'] -= cnt['u'];
            cnt['r'] -= cnt['u'];
            cnt['u'] = 0;
        }

        // 3
        if (cnt['r'] > 0) {
            nums[3] = cnt['r'];
            cnt['t'] -= cnt['r'];
            cnt['h'] -= cnt['r'];
            cnt['e'] -= cnt['r'] * 2;
            cnt['r'] = 0;
        }

        // 9
        if (cnt['i'] > 0) {
            nums[9] = cnt['i'];
            cnt['n'] -= cnt['i'] * 2;
            cnt['e'] -= cnt['i'];
            cnt['i'] = 0;
        }

        // 1
        if (cnt['o'] > 0) {
            nums[1] = cnt['o'];
            cnt['n'] -= cnt['i'];
            cnt['e'] -= cnt['i'];
            cnt['o'] = 0;
        }

        string ans;
        for (int i = 0; i < 10; ++i) {
            for (int j = nums[i]; j > 0; --j) {
                ans.push_back('0' + i);
            }
        }

        return ans;
    }
};