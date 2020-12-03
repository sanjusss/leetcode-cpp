#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     int countPrimes(int n) {
//         if (n < 2) {
//             return 0;
//         }

//         vector<bool> nums(n);
//         nums[0] = true;
//         nums[1] = true;
//         int end = min((int)sqrt(n) + 1, n - 1);
//         for (int i = 2; i <= end; ++i) {
//             if (nums[i]) {
//                 continue;
//             }

//             for (int j = i + i; j < n; j += i) {
//                 nums[j] = true;
//             }
//         }

//         return count(nums.begin(), nums.end(), false);
//     }
// };

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        vector<int> primes;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }

            for (int j = 0; j < primes.size() && i * primes[j] < n; ++j) {
                isPrime[i * primes[j]] = false;
                if (i % primes[j] == 0) {
                    break;
                }
            }
        }

        return primes.size();
    }
};