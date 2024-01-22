#include "leetcode.h"

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> bits;
        for (int i = num; i; i /= 10) {
            bits.push_back(i % 10);
        }

        vector<int> tar = bits;
        sort(tar.begin(), tar.end());
        int n = bits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (bits[i] == tar[i]) {
                continue;
            }

            for (int j = 0; j < i; ++j) {
                if (bits[j] == tar[i]) {
                    swap(bits[i], bits[j]);
                    break;
                }
            }

            break;
        }

        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans *= 10;
            ans += bits[i];
        }

        return ans;
    }
};