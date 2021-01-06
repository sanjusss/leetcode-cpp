#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> kvs;
        int conditionSize = equations.size();
        for (int i = 0; i < conditionSize; ++i) {
            kvs[equations[i][0]][equations[i][1]] = values[i];
            kvs[equations[i][1]][equations[i][0]] = 1 / values[i];
        }

        vector<double> ans;
        for (auto& query : queries) {
            if (kvs.find(query[0]) == kvs.end() || kvs.find(query[1]) == kvs.end()) {
                ans.push_back(-1);
                continue;
            }

            if (query[0] == query[1]) {
                ans.push_back(1);
                continue;
            }

            auto& kv = kvs[query[0]];
            if (kv.find(query[1]) != kv.end()) {
                ans.push_back(kv[query[1]]);
                continue;
            }
            queue<pair<string, double>> q;
            unordered_set<string> passed;
            for (auto& [k, v] : kv) {
                q.emplace(k, v);
                passed.insert(k);
            }

            bool end = false;
            while (!q.empty() && !end) {
                auto p = q.front();
                q.pop();
                auto& nkv = kvs[p.first];
                for (auto& [k, v] : nkv) {
                    if (passed.find(k) != passed.end()) {
                        continue;
                    }

                    if (k == query[1]) {
                        ans.push_back(p.second * v);
                        end = true;
                        break;
                    }
                    else {
                        passed.insert(k);
                        q.emplace(k, p.second * v);
                    }
                }
            }

            if (!end) {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};