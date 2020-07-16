#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    bool isBipartite(vector<vector<int>>& graph) {
//        unordered_set<int> a;
//        unordered_set<int> b;
//        int n = graph.size();
//        vector<bool> used(n);
//
//        queue<int> q;
//        do {
//            while (!q.empty()) {
//                int size = q.size();
//                for (int k = 0; k < size; ++k) {
//                    int i = q.front();
//                    q.pop();
//                    used[i] = true;
//                    if (b.find(i) != b.end()) {
//                        return false;
//                    }
//
//                    a.insert(i);
//                    for (int j : graph[i]) {
//                        if (b.find(j) == b.end()) {
//                            q.push(j);
//                        }
//                    }
//                }
//
//                a.swap(b);
//            }
//
//
//            for (int i = 0; i < n; ++i) {
//                if (!graph[i].empty() && used[i] == false) {
//                    q.push(i);
//                    break;
//                }
//            }
//
//        } while (!q.empty());
//
//        return true;
//    }
//};

//class Solution {
//public:
//    bool isBipartite(vector<vector<int>>& graph) {
//        int n = graph.size();
//        vector<bool> used(n);
//        vector<bool> a(n);
//        vector<bool> b(n);
//
//        queue<int> q;
//        do {
//            while (!q.empty()) {
//                int size = q.size();
//                for (int k = 0; k < size; ++k) {
//                    int i = q.front();
//                    q.pop();
//                    used[i] = true;
//                    if (b[i]) {
//                        return false;
//                    }
//
//                    a[i] = true;
//                    for (int j : graph[i]) {
//                        if (b[j] == false) {
//                            q.push(j);
//                        }
//                    }
//                }
//
//                a.swap(b);
//            }
//
//
//            for (int i = 0; i < n; ++i) {
//                if (!graph[i].empty() && used[i] == false) {
//                    q.push(i);
//                    break;
//                }
//            }
//
//        } while (!q.empty());
//
//        return true;
//    }
//};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n);
        for (int i = 0; i < n; ++i) {
            if (colors[i] != 0) {
                continue;
            }

            colors[i] = 1;
            queue<int> q;
            q.push(i);

            do {
                int size = q.size();
                for (int j = 0; j < size; ++j) {
                    int cur = q.front();
                    q.pop();
                    
                    for (int next : graph[cur]) {
                        if (colors[next] == 0) {
                            colors[next] = -colors[cur];
                            q.push(next);
                        }
                        else if (colors[next] == colors[cur]) {
                            return false;
                        }
                    }
                }

            } while (!q.empty());
        }

        return true;
    }
};