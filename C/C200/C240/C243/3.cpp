/*
 * @Author: sanjusss
 * @Date: 2021-05-30 10:29:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-30 11:36:28
 * @FilePath: \C\C200\C240\C243\3.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
//         priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
//         for (int i = 0; i < servers.size(); ++i) {
//             q.emplace(0, servers[i], i);
//         }

//         vector<int> ans;
//         ans.reserve(tasks.size());
//         for (int j = 0; j < tasks.size(); ++j) {
//             while (get<0>(q.top()) < j) {
//                 auto [time, w, i] = q.top();
//                 q.pop();
//                 q.emplace(j, w, i);
//             }

//             auto [time, w, i] = q.top();
//             q.pop();
//             ans.push_back(i);
//             q.emplace(time + tasks[j], w, i);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> workEnd(n);//工作结束时间
        auto cmpAv = [&servers](int a, int b) {
            if (servers[a] == servers[b]) {
                return a > b;
            }
            else {
                return servers[a] > servers[b];
            }
        };
        auto cmpWork = [&workEnd](int a, int b) {
            return workEnd[a] > workEnd[b];
        };

        priority_queue<int, vector<int>, decltype(cmpAv)> av(cmpAv);//可用队列
        priority_queue<int, vector<int>, decltype(cmpWork)> work(cmpWork);//工作中的队列
        for (int i = 0; i < n; ++i) {
            av.push(i);
        }

        vector<int> ans;
        ans.reserve(m);
        int cur = 0;//当前时间
        for (int t = 0; t < m; ++t) {
            cur = max(cur, t);
            while (av.empty() || (!work.empty() && workEnd[work.top()] <= cur)) {
                cur = max(cur, workEnd[work.top()]);
                av.push(work.top());
                work.pop();
            }

            int i = av.top();
            av.pop();
            ans.push_back(i);
            workEnd[i] = cur + tasks[t];
            work.push(i);
        }

        return ans;
    }
};

TEST(&Solution::assignTasks)