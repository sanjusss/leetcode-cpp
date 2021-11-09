/*
 * @Author: sanjusss
 * @Date: 2021-11-09 13:18:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-09 20:19:40
 * @FilePath: \0\400\480\488.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findMinStep(string board, string hand) {
        unordered_map<char, int> remain;
        for (char i : hand) {
            ++remain[i];
        }

        int ans = INT_MAX;
        int cur = 0;
        int size = board.size();
        stack<pair<char, int>> state;
        function<void(int)> dfs = [&](int i) {
            if (cur >= ans) {
                return;
            }
            else if (i == size) {
                if (state.empty()) {
                    ans = cur;
                }

                return;
            }

            // 更新栈内容
            if (!state.empty() && state.top().first == board[i]) {
                ++state.top().second;
            }
            else {
                state.emplace(board[i], 1);
            }

            auto [c, cnt] = state.top();
            bool notFollowSame = i + 1 == size || board[i + 1] != c;  // 后面的与当前不同
            if (cnt < 3) {                                            // 当前不满足3个相连
                dfs(i + 1);                                           // 不从当前插入
                if (notFollowSame) {                                  // 从当前插入相同颜色
                    for (int j = min(3 - cnt, remain[c]); j > 0; --j) {
                        cur += j;
                        remain[c] -= j;
                        state.top().second += j;
                        if (state.top().second >= 3) {
                            state.pop();
                            dfs(i + 1);
                            state.emplace(c, cnt);
                        }
                        else {
                            dfs(i + 1);
                            state.top().second -= j;
                        }

                        remain[c] += j;
                        cur -= j;
                    }
                }
            }
            // 当前大于等于3个相连
            else if (notFollowSame) {
                state.pop();
                dfs(i + 1);
                state.emplace(c, cnt);
            }
            else {  // 后面一个球和现在一样
                dfs(i + 1);

                // 尝试插入额外的球
                state.pop();
                for (auto [cj, r] : remain) {
                    if (cj == c) {
                        continue;
                    }

                    for (
                        int j = min(3, r); j > 0;
                        --j) {  // 插入3个（实际上时间有先后，比如先1个，处理完其他后再插入2个）表示牺牲3个球，分隔当前和后面连续的
                        if (state.empty() || state.top().first != cj) {
                            state.emplace(cj, j);
                        }
                        else {
                            state.top().second += j;
                        }

                        cur += j;
                        remain[cj] -= j;
                        if (state.top().second >= 3) {
                            auto tmp = state.top();
                            state.pop();
                            dfs(i + 1);
                            state.push(tmp);
                        }
                        else {
                            dfs(i + 1);
                        }

                        remain[cj] += j;
                        cur -= j;
                        if (state.top().second == j) {
                            state.pop();
                        }
                        else {
                            state.top().second -= j;
                        }
                    }
                }

                state.emplace(c, cnt);
            }

            // 撤销对栈的修改
            if (cnt == 1) {
                state.pop();
            }
            else {
                --state.top().second;
            }
        };

        dfs(0);
        return ans == INT_MAX ? -1 : ans;
    }
};

TEST(&Solution::findMinStep)