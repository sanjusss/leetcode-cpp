#include "leetcode.h"

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> em;
        for (auto e : employees) {
            em[e->id] = e;
        }

        queue<int> q;
        q.push(id);
        int ans = 0;
        while (!q.empty()) {
            auto e = em[q.front()];
            q.pop();
            ans += e->importance;
            for (int i : e->subordinates) {
                q.push(i);
            }
        }

        return ans;
    }
};

