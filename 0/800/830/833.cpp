#include "leetcode.h"

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int m = s.size();
        int n = indices.size();
        vector<int> is(n);
        iota(is.begin(), is.end(), 0);
        sort(is.begin(), is.end(), [&indices](int a, int b) { return indices[a] < indices[b]; });
        int cur = 0;
        string ans;
        for (int i : is) {
            int begin = indices[i];
            auto& src = sources[i];
            auto& tar = targets[i];
            while (cur < begin) {
                ans.push_back(s[cur++]);
            }

            int len = src.size();
            if (cur + len > m) {
                break;
            }

            bool success = true;
            for (int j = 0; j < len; ++j) {
                if (s[cur + j] != src[j]) {
                    success = false;
                    break;
                }
            }

            if (!success) {
                continue;
            }

            ans += tar;
            cur += len;
        }

        while (cur < m) {
            ans.push_back(s[cur++]);
        }

        return ans;
    }
};