#include "leetcode.h"

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        int plen = pattern.size();
        for (auto& q : queries) {
            int qlen = q.size();
            int qi = 0;
            int pi = 0;
            while (qi < qlen) {
                if (pi == plen || q[qi] != pattern[pi]) {
                    if (q[qi] >= 'A' && q[qi] <= 'Z') {
                        break;
                    }
                    else {
                        ++qi;
                    }
                }
                else {
                    ++qi;
                    ++pi;
                }
            }

            ans.push_back(qi == qlen && pi == plen);
        }

        return ans;
    }
};