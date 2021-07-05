/*
 * @Author: sanjusss
 * @Date: 2021-07-05 08:33:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-05 10:14:36
 * @FilePath: \0\700\720\726.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string countOfAtoms(string formula) {
        unordered_map<string_view, int> cnt;
        string_view sf = formula;
        countExpr(sf, cnt);
        map<string_view, int> atoms(cnt.begin(), cnt.end());
        string ans;
        for (auto& [a, c] : atoms) {
            ans += a;
            if (c > 1) {
                ans += to_string(c);
            }
        }

        return ans;
    }

private:
    void countExpr(string_view f, unordered_map<string_view, int>& cnt) {
        int n = f.size();
        int start = -1;
        string_view cur;
        int curCnt = 0;
        for (int i = 0; i < n; ++i) {
            if (islower(f[i])) {
                continue;
            }

            if (start >= 0) {
                cur = f.substr(start, i - start);
                start = -1;
            }

            if (isdigit(f[i])) {
                curCnt = curCnt * 10 + f[i] - '0';
            }
            else if (!cur.empty()) {
                cnt[cur] += curCnt == 0 ? 1 : curCnt;
                cur = string_view();
                curCnt = 0;
            }

            if (f[i] == '(') {
                int left = 0;
                int j = i;
                do {
                    if (f[j] == '(') {
                        ++left;
                    }
                    else if (f[j] == ')') {
                        --left;
                    }

                    ++j;
                } while (left > 0);
                unordered_map<string_view, int> sub;
                countExpr(f.substr(i + 1, j - i - 2), sub);
                for (i = j; i < n && isdigit(f[i]); ++i) {
                    curCnt = curCnt * 10 + f[i] - '0';
                }

                if (curCnt == 0) {
                    curCnt = 1;
                }

                for (auto& [a, c] : sub) {
                    cnt[a] += c * curCnt;
                }

                curCnt = 0;
                --i;
            }
            else if (isupper(f[i])) {
                start = i;
            }
        }

        if (start >= 0) {
            cur = f.substr(start);
        }

        if (!cur.empty()) {
            cnt[cur] += curCnt == 0 ? 1 : curCnt;
        }
    }
};

TEST(&Solution::countOfAtoms)