/*
 * @Author: sanjusss
 * @Date: 2021-07-18 15:57:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-18 16:14:10
 * @FilePath: \chengxuyuanmianshijindian\1002.cpp
 */
#include "leetcode.h"

class Solution {
    struct ArrayHash {
        constexpr size_t operator()(array<int, 26> const& arr) const {
            string_view s((char const*)arr.data(), 26 * sizeof(int));
            return hash<string_view>{}(s);
        }
    };

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        array<int, 26> cnt = { 0 };
        unordered_map<array<int, 26>, vector<string>, ArrayHash> groups(0, ArrayHash());
        for (string& s : strs) {
            cnt.fill(0);
            for (char i : s) {
                ++cnt[i - 'a'];
            }

            groups[cnt].emplace_back(move(s));
        }

        vector<vector<string>> ans;
        for (auto& [_, vec] : groups) {
            ans.emplace_back(move(vec));
        }

        return ans;
    }
};