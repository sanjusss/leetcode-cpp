/*
 * @Author: sanjusss
 * @Date: 2023-03-07 09:48:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-07 10:19:39
 * @FilePath: \1000\1000\1090\1096.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        auto arr = calc(expression);
        vector<string> res(arr.begin(), arr.end());
        sort(res.begin(), res.end());
        return res;
    }

private:
    unordered_set<string> calc(string_view exp) {
        unordered_set<string> arr;
        arr.emplace(""s);
        int n = exp.size();
        for (int i = 0; i < n; ++i) {
            if (exp[i] != '{') {
                unordered_set<string> next;
                for (auto& s : arr) {
                    next.insert(s + exp[i]);
                }

                swap(next, arr);
                continue;
            }

            int left = 1;
            int j = i + 1;
            while (left > 0) {
                if (exp[j] == '{') {
                    ++left;
                }
                else if (exp[j] == '}') {
                    --left;
                }

                ++j;
            }

            auto sub = op(exp.substr(i + 1, j - i - 2));
            unordered_set<string> next;
            for (auto& a : arr) {
                for (auto& b : sub) {
                    next.insert(a + b);
                }
            }

            swap(next, arr);
            i = j - 1;
        }

        return arr;
    }

    unordered_set<string> op(string_view exp) {
        unordered_set<string> arr;
        int n = exp.size();
        int start = 0;
        int left = 0;
        for (int i = 0; i <= n; ++i) {
            if (i == n || (left == 0 && exp[i] == ',')) {
                auto sub = calc(exp.substr(start, i - start));
                for (auto& s : sub) {
                    arr.insert(s);
                }

                start = i + 1;
            }
            else {
                if (exp[i] == '{') {
                    ++left;
                }
                else if (exp[i] == '}') {
                    --left;
                }
            }
        }

        return arr;
    }
};

TEST(&Solution::braceExpansionII)