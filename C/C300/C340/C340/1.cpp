#include "leetcode.h"

static vector<int> primes;
static constexpr int maxI = 4e6;
static vector<bool> isPrime(maxI + 1, true);

static int init = [] () {
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
} ();

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (isPrime[nums[i][i]]) {
                ans = max(nums[i][i], ans);
            }

            if (isPrime[nums[i][n - 1 - i]]) {
                ans = max(nums[i][n - 1 - i], ans);
            }
        }

        return ans;
    }
};