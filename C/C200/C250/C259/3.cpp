/*
 * @Author: sanjusss
 * @Date: 2021-09-19 10:50:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-19 11:03:18
 * @FilePath: \C\C200\C250\C259\3.cpp
 */
#include "leetcode.h"

class DetectSquares {
public:
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        ++cnt[point[0]][point[1]];
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        if (cnt.count(x) == 0) {
            return 0;
        }

        int ans = 0;
        for (auto [y2, c] : cnt[x]) {
            if (y2 == y) {
                continue;
            }

            int e = abs(y2 - y);
            int x2 = x - e;
            if (x2 >= 0 && cnt.count(x2) && cnt[x2][y2] && cnt[x2][y]) {
                ans += cnt[x2][y2] * cnt[x2][y] * c;
            }

            x2 = x + e;
            if (cnt.count(x2) && cnt[x2][y2] && cnt[x2][y]) {
                ans += cnt[x2][y2] * cnt[x2][y] * c;
            }
        }

        return ans;
    }

private:
    unordered_map<int, unordered_map<int, int>> cnt;
};
