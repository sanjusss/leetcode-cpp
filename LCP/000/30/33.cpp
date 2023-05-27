#include "leetcode.h"

class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        if (accumulate(vat.begin(), vat.end(), 0) == 0) {
            return 0;
        }

        int n = bucket.size();
        int ans = INT_MAX;
        int maxStore = 0;
        for (int i = 0; i < n; ++i) {
            if (vat[i] == 0) {
                continue;
            }

            int d = max(1, bucket[i]);
            maxStore = max(maxStore, (vat[i] + d - 1) / d);
        }

        for (int stores = 1; stores <= maxStore; ++stores) {
            int t = stores;
            for (int i = 0; i < n; ++i) {
                if (vat[i] == 0) {
                    continue;
                }

                t += max(0, (vat[i] + stores - 1) / stores - bucket[i]);
            }

            ans = min(ans, t);
        }

        return ans;
    }
};