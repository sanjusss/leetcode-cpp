#include "leetcode.h"

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qb;
        for (auto& f : flowers) {
            qb.emplace(f[0], f[1]);
        }

        priority_queue<int, vector<int>, greater<int>> qe;
        int plen = people.size();
        vector<int> pis(plen);
        iota(pis.begin(), pis.end(), 0);
        sort(pis.begin(), pis.end(), [&people](int a, int b) {
            return people[a] < people[b];
        });
        vector<int> ans(plen);
        for (int pi : pis) {
            int day = people[pi];
            while (!qb.empty() && qb.top().first <= day) {
                qe.push(qb.top().second);
                qb.pop();
            }

            while (!qe.empty() && qe.top() < day) {
                qe.pop();
            }

            ans[pi] = qe.size();
        }

        return ans;
    }
};