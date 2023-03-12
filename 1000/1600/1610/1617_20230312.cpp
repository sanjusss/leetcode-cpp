#include "leetcode.h"

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> nexts(n);
        for (auto& e : edges) {
            nexts[e[0] - 1].push_back(e[1] - 1);
            nexts[e[1] - 1].push_back(e[0] - 1);
        }

        vector<int> ans(n - 1);
        queue<int> q;
        for (int mask = (1 << n) - 1; mask > 0; --mask) {
            if (__builtin_popcount(mask) < 2) {
                continue;
            }

            int dis = 0;
            for (int i = 0; i < n; ++i) {
                if (!(mask & (1 << i))) {
                    continue;
                }

                int cur = 1 << i;
                int d = -1;
                q.push(i);
                while (!q.empty()) {
                    for (int qi = q.size(); qi > 0; --qi) {
                        int j = q.front();
                        q.pop();
                        for (int k : nexts[j]) {
                            if (!(mask & (1 << k))) {
                                continue;
                            }
                            else if (cur & (1 << k)) {
                                continue;
                            }

                            cur |= 1 << k;
                            q.push(k);
                        }
                    }

                    ++d;
                }

                if (cur != mask) {
                    dis = 0;
                    break;
                }
                else {
                    dis = max(dis, d);
                }
            }

            if (dis > 0) {
                ++ans[dis - 1];
            }
        }

        return ans;
    }
};