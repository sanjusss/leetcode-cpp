/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-13 11:24:47
 * @FilePath: \C\C300\C350\C358\4.cpp
 */
#include "leetcode.h"

static vector<int> primes;
static constexpr int maxI = 1e5;
static vector<bool> isPrime(maxI + 1, true);
static vector<int> score(maxI + 1);

static int init = []() {
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= maxI; ++i) {
        if (!isPrime[i]) {
            continue;
        }

        score[i] = 1;
        primes.push_back(i);
        for (int j = i + i; j <= maxI; j += i) {
            isPrime[j] = false;
            ++score[j];
        }
    }
    return 0;
}();

int64_t bigpow(int64_t a, int64_t b) {
    static const int64_t mod = 1e9 + 7;
    a %= mod;
    int64_t ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return ans;
}

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        static constexpr int64_t mod = 1e9 + 7;
        int n = nums.size();
        map<int, int64_t> cnt;
        stack<int> s;
        s.push(-1);
        for (int i = 0; i <= n; ++i) {
            while (s.size() > 1 && (i == n || score[nums[s.top()]] < score[nums[i]])) {
                int j = s.top();
                s.pop();
                cnt[nums[j]] += (int64_t)(j - s.top()) * (int64_t)(i - j);
            }

            s.push(i);
        }

        int64_t ans = 1;
        int64_t needs = k;
        for (auto i = cnt.rbegin(); needs > 0 && i != cnt.rend(); ++i) {
            int64_t used = min(i->second, needs);
            ans *= bigpow(i->first, used);
            ans %= mod;
            needs -= used;
        }

        return ans;
    }
};

TEST(&Solution::maximumScore)