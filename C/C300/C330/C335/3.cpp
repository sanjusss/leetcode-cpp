/*
 * @Author: sanjusss
 * @Date: 2023-03-05 10:28:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-09 08:52:14
 * @FilePath: \C\C300\C330\C335\3.cpp
 */
#include "leetcode.h"

static vector<int> primes;
static constexpr int maxI = 1e6;
static vector<bool> isPrime(maxI + 1, true);

static int init = []() {
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= maxI; ++i) {
        if (!isPrime[i]) {
            continue;
        }

        primes.push_back(i);
        for (int j = i + i; j <= maxI; j += i) {
            isPrime[j] = false;
        }
    }
    return 0;
}();

class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> factors(n);
        unordered_map<int, int> right;
        for (int i = 0; i < n; ++i) {
            int j = nums[i];
            if (j == 1) { // 1对互质没影响，直接跳过
                continue;
            }

            auto& fac = factors[i];

            for (int k : primes) {
                if (isPrime[j]) {
                    fac.push_back(j);
                    ++right[j];
                    break;
                }
                else if (k > j) {
                    break;
                }
                else if (j % k != 0) {
                    continue;
                }

                fac.push_back(k);
                ++right[k];
                while (j % k == 0) {
                    j /= k;
                }
            }
        }

        int share = 0;
        unordered_set<int> left;
        for (int i = 0; i < n - 1; ++i) {
            for (int j : factors[i]) {
                if (--right[j] == 0) {
                    --share;
                }

                if (left.insert(j).second) {
                    ++share;
                }
            }

            if (share == 0) {
                return i;
            }
        }

        return -1;
    }
};

TEST(&Solution::findValidSplit)