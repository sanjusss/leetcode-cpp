/*
 * @Author: sanjusss
 * @Date: 2022-07-06 10:40:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-06 12:19:22
 * @FilePath: \0\700\730\736.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int evaluate(string expression) {
        return select(expression, {});
    }

private:
    string_view nextE(string_view& e) {
        size_t n = e.size();
        int left = 0;
        size_t i = 0;
        while (i < n) {
            if (e[i] == ' ') {
                if (left == 0) {
                    --i;
                    break;
                }
            }
            else if (e[i] == '(') {
                ++left;
            }
            else if (e[i] == ')') {
                if (--left == 0) {
                    break;
                }
            }

            ++i;
        }

        if (i == n || i == n - 1) {
            string_view res;
            swap(res, e);
            return res;
        }
        else {
            string_view res = e.substr(0, i + 1);
            e = e.substr(i + 2);
            return res;
        }
    }

    int select(string_view e, unordered_map<string_view, int> vars) {
        while (e[0] == '(') {
            e = e.substr(1, e.size() - 2);
        }

        string_view prefix = e.substr(0, 4);
        if (prefix == "let "sv) {
            return let(e.substr(4), move(vars));
        }
        else if (prefix == "add "sv) {
            return add(e.substr(4), move(vars));
        }
        else if (prefix == "mult"sv) {
            return mul(e.substr(5), move(vars));
        }
        else if (vars.count(e)) {
            return vars.at(e);
        }
        else {
            int val = 0;
            from_chars(e.data(), e.data() + e.size(), val);
            return val;
        }
    }

    int add(string_view e, unordered_map<string_view, int> vars) {
        string_view a = nextE(e);
        return select(a, vars) + select(e, vars);
    }

    int mul(string_view e, unordered_map<string_view, int> vars) {
        string_view a = nextE(e);
        return select(a, vars) * select(e, vars);
    }

    int let(string_view e, unordered_map<string_view, int> vars) {
        string_view first = nextE(e);
        while (!e.empty()) {
            string_view second = nextE(e);
            vars[first] = select(second, vars);
            first = nextE(e);
        }

        return select(first, vars);
    }
};

TEST(&Solution::evaluate)