/*
 * @Author: sanjusss
 * @Date: 2021-07-06 08:58:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-06 09:33:47
 * @FilePath: \1000\1400\1410\1418.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        unordered_set<string> foods;
        unordered_map<int, unordered_map<string, int>> cnt;
        for (auto& o : orders) {
            foods.insert(o[2]);
            ++cnt[stoi(o[1])][o[2]];
        }

        set<string> allFoods(foods.begin(), foods.end());
        set<int> tables;
        for (auto& [t, _] : cnt) {
            tables.insert(t);
        }
        
        vector<vector<string>> ans;
        ans.reserve(tables.size() + 1);
        auto& headers = ans.emplace_back();
        headers.emplace_back("Table");
        copy(allFoods.begin(), allFoods.end(), back_inserter(headers));
        for (int t : tables) {
            vector<string> row;
            row.reserve(allFoods.size() + 1);
            row.emplace_back(to_string(t));
            auto& c = cnt[t];
            for (auto& f : allFoods) {
                auto p = c.find(f);
                if (p == c.end()) {
                    row.emplace_back("0"s);
                }
                else {
                    row.emplace_back(to_string(p->second));
                }
            }

            ans.emplace_back(move(row));
        }

        return ans;
    }
};

TEST(&Solution::displayTable)