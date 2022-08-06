/*
 * @Author: sanjusss
 * @Date: 2022-07-31 10:24:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-31 10:59:04
 * @FilePath: \C\C300\C300\C304\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dis1(n, INT_MAX);
        vector<int> dis2(n, INT_MAX);
        for (int i = 0; i < n && (node1 >= 0 || node2 >= 0); ++i) {
            if (node1 >= 0) {
                if (dis1[node1] < INT_MAX) {
                    node1 = -1;
                }
                else {
                    dis1[node1] = i;
                    node1 = edges[node1];
                }
            }
            
            if (node2 >= 0) {
                if (dis2[node2] < INT_MAX) {
                    node2 = -1;
                }
                else {
                    dis2[node2] = i;
                    node2 = edges[node2];
                }
            }
        }

        int minDis = INT_MAX;
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int dis = max(dis1[i], dis2[i]);
            if (dis < minDis) {
                ans = i;
                minDis = dis;
            }
        }

        return ans;
    }
};

TEST(&Solution::closestMeetingNode)