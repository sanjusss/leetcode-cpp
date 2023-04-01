#include "leetcode.h"

static vector<int> primes;
static constexpr int maxI = 1000;
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
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                continue;
            }

            auto p = lower_bound(primes.begin(), primes.end(), nums[i] + 1 - nums[i + 1]);
            if (p == primes.end() || *p >= nums[i]) {
                return false;
            }

            nums[i] -= *p;
        }

        return true;
    }
};

TEST(&Solution::primeSubOperation)