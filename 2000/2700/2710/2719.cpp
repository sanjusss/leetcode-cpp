#include "leetcode.h"

class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        static constexpr int mod = 1e9 + 7;
        unordered_map<int, int> dp;
        function<int(int, int)> dfs = [&] (int pre, int size) -> int {
            int key = pre * 100 + size;
            if (dp.count(key)) {
                return dp[key];
            }

            int& res = dp[key];
            for (int i = 0; i <= 9 && pre + i <= max_sum; ++i) {
                if (size == 1) {
                    if (pre + i >= min_sum) {
                        res = (res + 1) % mod;
                    }
                }
                else {
                    res += dfs(pre + i, size - 1);
                    res %= mod;
                }
            }

            return res;
        };
        function<int(string_view)> calc = [&](string_view num) -> int {
            int pre = 0;
            int res = 0;
            while (num.size() > 1 && pre <= max_sum) {
                int size = num[0] - '0';
                for (int i = 0; i < size; ++i) {
                    res += dfs(pre + i, num.size() - 1);
                    res %= mod;
                }

                pre += size;
                num.remove_prefix(1);
            }

            for (int i = 0; i <= num[0] - '0' && pre + i <= max_sum; ++i) {
                if (pre + i >= min_sum) {
                    ++res;
                    res %= mod;
                }
            }

            return res;
        };
        int sum1 = 0;
        for (char c : num1) {
            sum1 += c - '0';
        }

        int add1 = (sum1 >= min_sum && sum1 <= max_sum) ? 1 : 0;
        return (calc(num2) + mod - calc(num1) + add1) % mod;
    }
};