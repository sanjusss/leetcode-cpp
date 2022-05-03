/*
 * @Author: sanjusss
 * @Date: 2022-05-03 14:59:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-03 15:17:42
 * @FilePath: \0\900\930\937.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<tuple<string_view, string_view, string_view>> arr;
        vector<string_view> numbers;
        for (string_view s : logs) {
            auto first = s.find(' ');
            string_view content = s.substr(first + 1);
            bool hasAlpha = any_of(content.begin(), content.end(), [](char c) { return isalpha(c); });
            if (hasAlpha) {
                string_view tag = s.substr(0, first);
                arr.emplace_back(s, tag, content);
            }
            else {
                numbers.emplace_back(s);
            }
        }

        sort(arr.begin(), arr.end(),
             [](const tuple<string_view, string_view, string_view>& a,
                const tuple<string_view, string_view, string_view>& b) {
                 auto& [sa, ta, ca] = a;
                 auto& [sb, tb, cb] = b;
                 if (ca != cb) {
                     return ca < cb;
                 }
                 else {
                     return ta < tb;
                 }
             });
        vector<string> ans;
        for (auto& [s, _1, _2] : arr) {
            ans.emplace_back(s);
        }

        for (auto& s : numbers) {
            ans.emplace_back(s);
        }

        return ans;
    }
};