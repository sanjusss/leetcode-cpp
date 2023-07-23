#include "leetcode.h"

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        ans.emplace_back();
        for (auto& s : words) {
            int n = s.size();
            for (int i = 0; i <= n; ++i) {
                if (i == n || s[i] == separator) {
                    if (ans.back().empty() == false) {
                        ans.emplace_back();
                    }
                }
                else {
                    ans.back().push_back(s[i]);
                }
            }
        }

        if (ans.back().empty()) {
            ans.pop_back();
        }

        return ans;
    }
};