#pragma once
#include "leetcode.h"

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int ringSize = ring.size();
        vector<vector<int>> positions(27);
        for (int i = 0; i < ringSize; ++i) {
            positions[ring[i] - 'a'].push_back(i);
        }

        positions[26].push_back(0);

        int ans = 0;
        vector<int> steps(ringSize);
        vector<int> nexts(ringSize);
        int prev = 26;
        int cur;
        int step;
        for (char i : key) {
            fill(nexts.begin(), nexts.end(), INT_MAX);
            int cur = i - 'a';
            auto& curs = positions[cur];
            auto& prevs = positions[prev];
            ans = INT_MAX;
            for (int j : prevs) {
                step = steps[j] + 1;
                for (int k : curs) {
                    nexts[k] = min({nexts[k], step + abs(k - j), step + ringSize - abs(k - j) });
                    ans = min(ans, nexts[k]);
                }
            }

            prev = cur;
            swap(nexts, steps);
        }

        return ans;
    }
};