/*
 * @Author: sanjusss
 * @Date: 2023-07-07 09:30:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-07 10:50:56
 * @FilePath: \2000\2500\2530\2532.cpp
 */
#include "leetcode.h"

/**
共有 k 位工人计划将 n 个箱子从旧仓库移动到新仓库。给你两个整数 n 和 k，以及一个二维整数数组 time ，数组的大小为 k x 4
，其中 time[i] = [leftToRighti, pickOldi, rightToLefti, putNewi] 。

一条河将两座仓库分隔，只能通过一座桥通行。旧仓库位于河的右岸，新仓库在河的左岸。开始时，所有 k
位工人都在桥的左侧等待。为了移动这些箱子，第 i 位工人（下标从 0 开始）可以：

从左岸（新仓库）跨过桥到右岸（旧仓库），用时 leftToRighti 分钟。
从旧仓库选择一个箱子，并返回到桥边，用时 pickOldi 分钟。不同工人可以同时搬起所选的箱子。
从右岸（旧仓库）跨过桥到左岸（新仓库），用时 rightToLefti 分钟。
将箱子放入新仓库，并返回到桥边，用时 putNewi 分钟。不同工人可以同时放下所选的箱子。
如果满足下面任一条件，则认为工人 i 的 效率低于 工人 j ：

leftToRighti + rightToLefti > leftToRightj + rightToLeftj
leftToRighti + rightToLefti == leftToRightj + rightToLeftj 且 i > j
工人通过桥时需要遵循以下规则：

如果工人 x 到达桥边时，工人 y 正在过桥，那么工人 x 需要在桥边等待。
如果没有正在过桥的工人，那么在桥右边等待的工人可以先过桥。如果同时有多个工人在右边等待，那么 效率最低 的工人会先过桥。
如果没有正在过桥的工人，且桥右边也没有在等待的工人，同时旧仓库还剩下至少一个箱子需要搬运，此时在桥左边的工人可以过桥。如果同时有多个工人在左边等待，那么
效率最低 的工人会先过桥。 所有 n 个盒子都需要放入新仓库，请你返回最后一个搬运箱子的工人 到达河左岸 的时间。
*/

class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        auto cmpb = [&time](int i, int j) {
            if (time[i][0] + time[i][2] == time[j][0] + time[j][2]) {
                return i < j;
            }
            else {
                return time[i][0] + time[i][2] < time[j][0] + time[j][2];
            }
        };
        auto cmpa = [&cmpb](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return cmpb(a.second, b.second);
            }
        };
        typedef priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmpa)> aqueue;
        typedef priority_queue<int, vector<int>, decltype(cmpb)> bqueue;
        aqueue leftBackQ(cmpa);
        aqueue rightBackQ(cmpa);
        bqueue leftQ(cmpb);
        bqueue rightQ(cmpb);
        for (int i = 0; i < k; ++i) {
            leftQ.emplace(i);
        }

        int emptyTime = 0;
        while (n > 0 || leftBackQ.size() + leftQ.size() != k) {
            while (!rightBackQ.empty() && rightBackQ.top().first <= emptyTime) {
                rightQ.emplace(rightBackQ.top().second);
                rightBackQ.pop();
            }
            
            int right;
            if (rightBackQ.empty() && rightQ.empty()) {
                right = INT_MAX;
            }
            else if (rightQ.empty()) {
                right = rightBackQ.top().first;
            }
            else {
                right = emptyTime;
            }


            while (!leftBackQ.empty() && leftBackQ.top().first <= emptyTime) {
                leftQ.emplace(leftBackQ.top().second);
                leftBackQ.pop();
            }
            
            int left;
            if ((leftBackQ.empty() && leftQ.empty()) || n == 0) {
                left = INT_MAX;
            }
            else if (leftQ.empty()) {
                left = leftBackQ.top().first;
            }
            else {
                left = emptyTime;
            }

            if (right <= left) {
                int i;
                if (rightQ.empty()) {
                    i = rightBackQ.top().second;
                    rightBackQ.pop();
                }
                else {
                    i = rightQ.top();
                    rightQ.pop();
                }

                emptyTime = right + time[i][2];
                leftBackQ.emplace(right + time[i][2] + time[i][3], i);
            }
            else {
                --n;
                int i;
                if (leftQ.empty()) {
                    i = leftBackQ.top().second;
                    leftBackQ.pop();
                }
                else {
                    i = leftQ.top();
                    leftQ.pop();
                }
                
                emptyTime = left + time[i][0];
                rightBackQ.emplace(left + time[i][0] + time[i][1], i);
            }
        }

        return emptyTime;
    }
};

TEST(&Solution::findCrossingTime)