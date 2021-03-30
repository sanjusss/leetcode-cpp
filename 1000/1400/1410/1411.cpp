#include "leetcode.h"

class Solution {
public:
    int numOfWays(int n) {
        static const int64_t mod = 1e9 + 7;
        int64_t aba = 6;
        int64_t abc = 6;
        for (int i = 2; i <= n; ++i) {
            tie(aba, abc) = make_pair((aba * 3 + abc * 2) % mod, (aba * 2 + abc * 2) % mod);
        }

        return (aba + abc) % mod;
    }
};

TEST(&Solution::numOfWays)