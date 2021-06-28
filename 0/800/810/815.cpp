/*
 * @Author: sanjusss
 * @Date: 2021-06-28 08:33:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-28 08:54:53
 * @FilePath: \0\800\810\815.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
//         if (source == target) {
//             return 0;
//         }

//         unordered_map<int, vector<int>> sites;
//         for (int i = routes.size() - 1; i >= 0; --i) {
//             for (int s : routes[i]) {
//                 sites[s].push_back(i);
//             }
//         }

//         int turns = 0;
//         unordered_set<int> passedSites{ source };
//         vector<bool> passedReoutes(routes.size());
//         queue<int> q;
//         q.push(source);
//         while (!q.empty()) {
//             ++turns;
//             for (int i = q.size(); i > 0; --i) {
//                 int s = q.front();
//                 q.pop();
//                 for (int r : sites[s]) {
//                     if (passedReoutes[r]) {
//                         continue;
//                     }

//                     passedReoutes[r] = true;
//                     for (int next : routes[r]) {
//                         if (next == target) {
//                             return turns;
//                         }
//                         else if (passedSites.find(next) == passedSites.end()) {
//                             passedSites.insert(next);
//                             q.push(next);
//                         }
//                     }
//                 }
//             }
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> sites;
        for (int i = routes.size() - 1; i >= 0; --i) {
            for (int s : routes[i]) {
                sites[s].push_back(i);
            }
        }

        int turns = 0;
        vector<bool> passedReoutes(routes.size());
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            ++turns;
            for (int i = q.size(); i > 0; --i) {
                int s = q.front();
                q.pop();
                for (int r : sites[s]) {
                    if (passedReoutes[r]) {
                        continue;
                    }

                    passedReoutes[r] = true;
                    for (int next : routes[r]) {
                        if (next == target) {
                            return turns;
                        }
                        else {
                            q.push(next);
                        }
                    }
                }
            }
        }

        return -1;
    }
};

TEST(&Solution::numBusesToDestination)