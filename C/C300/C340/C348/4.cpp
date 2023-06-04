/*
 * @Author: sanjusss
 * @Date: 2023-06-04 10:29:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-04 13:39:34
 * @FilePath: \C\C300\C340\C348\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        return (sc_mod + dfs(num2, min_sum, max_sum) - dfs(num1, min_sum, max_sum) + calc(num1, min_sum, max_sum)) %
               sc_mod;
    }

private:
    int64_t dfs(string_view num, int min_sum, int max_sum) {
        while (num.empty() == false && num[0] == '0') {
            num.remove_prefix(1);
        }

        int n = num.size();
        if (n == 0) {
            return 0;
        }

        int first = num[0] - '0';
        if (n == 1) {
            return max(min(first, max_sum) - min_sum + 1, 0);
        }

        int64_t ans = 0;
        unordered_map<int, int64_t> curSum;
        curSum[0] = 1;
        for (int b = 1; b <= n; ++b) {
            unordered_map<int, int64_t> nextSum;
            for (int i = (b == 1 ? first - 1 : 9); i >= 0; --i) {
                for (auto [cur, cnt] : curSum) {
                    if (cur + i > max_sum) {
                        continue;
                    }

                    auto& sum = nextSum[cur + i];
                    sum += cnt;
                    sum %= sc_mod;
                    if (b == n && cur + i >= min_sum) {
                        ans += cnt;
                        ans %= sc_mod;
                    }
                }
            }

            swap(nextSum, curSum);
        }

        if (first <= max_sum) {
            if (first >= min_sum) {
                ans += 1;
            }
            
            if (first < max_sum) {
                ans += dfs(num.substr(1), max(1, min_sum - first), max_sum - first);
            }

            ans %= sc_mod;
        }

        return ans;
    }

    int calc(string_view num, int min_sum, int max_sum) {
        int sum = 0;
        for (char c : num) {
            sum += c - '0';
        }

        return (sum >= min_sum && sum <= max_sum) ? 1 : 0;
    }

private:
    static constexpr int64_t sc_mod = 1e9 + 7;
};

TEST(&Solution::count)