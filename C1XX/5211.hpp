#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
//        double ans = 0;
//        vector<vector<double>> succ(n, vector<double>(n));
//        vector<unordered_set<int>> acc(n);
//        for (int i = 0; i < edges.size(); ++i) {
//            acc[edges[i][0]].insert(edges[i][1]);
//            acc[edges[i][1]].insert(edges[i][0]);
//            succ[edges[i][0]][edges[i][1]] = succProb[i];
//            succ[edges[i][1]][edges[i][0]] = succProb[i];
//        }
//
//        if (!acc[start].empty() && !acc[end].empty()) {
//            vector<double> facts(n);
//            stack<pair<int, double>> s;
//            s.push({ start, 1.0 });
//            do {
//                int cur = s.top().first;
//                double f = s.top().second;
//                s.pop();
//                if (f < facts[cur]) {
//                    continue;
//                }
//
//                double next;
//                for (int i : acc[cur]) {
//
//                    if (i == start) {
//                        continue;
//                    }
//                    
//                    next = f * succ[cur][i];
//                    if (i == end) {
//                        ans = max(ans, next);
//                    }
//                    else if (facts[i] < next) {
//                        facts[i] = next;
//                        s.push({ i, next });
//                    }
//                }
//            } while (!s.empty());
//        }
//
//        return ans;
//    }
//};

//class Solution {
//public:
//    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
//        double ans = 0;
//        unordered_map<int, unordered_map<int, double>> succ;
//        unordered_map<int, unordered_set<int>> acc(n);
//        for (int i = 0; i < edges.size(); ++i) {
//            acc[edges[i][0]].insert(edges[i][1]);
//            acc[edges[i][1]].insert(edges[i][0]);
//            succ[edges[i][0]][edges[i][1]] = succProb[i];
//            succ[edges[i][1]][edges[i][0]] = succProb[i];
//        }
//
//        if (!acc[start].empty() && !acc[end].empty()) {
//            vector<double> facts(n);
//            stack<pair<int, double>> s;
//            s.push({ start, 1.0 });
//            do {
//                int cur = s.top().first;
//                double f = s.top().second;
//                s.pop();
//                if (f < facts[cur] + 1e-5 || f < ans + 1e-5) {
//                    continue;
//                }
//
//                facts[cur] = f;
//                double next;
//                for (int i : acc[cur]) {
//
//                    if (i == start) {
//                        continue;
//                    }
//
//                    next = f * succ[cur][i];
//                    if (next < facts[i] + 1e-5 || next < ans + 1e-5) {
//                        continue;
//                    }
//
//                    if (i == end) {
//                        ans = next;
//                    }
//                    else {
//                        s.push({ i, next });
//                    }
//                }
//            } while (!s.empty());
//        }
//
//        return ans;
//    }
//};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, unordered_map<int, double>> succ;
        for (int i = 0; i < edges.size(); ++i) {
            succ[edges[i][0]][edges[i][1]] = succProb[i];
            succ[edges[i][1]][edges[i][0]] = succProb[i];
        }

        priority_queue<pair<double, int>> q;
        q.push({ 1, start });
        vector<double> olds(n);
        do {
            int cur = q.top().second;
            double fact = q.top().first;
            q.pop();
            if (cur == end) {
                return fact;
            }

            double next;
            for (auto& i : succ[cur]) {
                next = i.second * fact;
                if (olds[i.first] < next) {
                    olds[i.first] = next;
                    q.push({ i.second * fact, i.first });
                }
            }
        } while (!q.empty());

        return 0;
    }
};