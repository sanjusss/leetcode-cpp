#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int size = s.size();
        string_view text = s;
        vector<string> ans;
        for (int i = 1; i < size; ++i) {
            int ip1 = svtoi(text.substr(0, i));
            if (ip1 > 255) {
                break;
            }

            for (int j = i + 1; j < size; ++j) {
                int ip2 = svtoi(text.substr(i, j - i));
                if (ip2 > 255) {
                    break;
                }

                for (int k = j + 1; k < size; ++k) {
                    int ip3 = svtoi(text.substr(j, k - j));
                    if (ip3 > 255) {
                        break;
                    }

                    int ip4 = svtoi(text.substr(k, size - k));
                    if (ip4 > 255) {
                        continue;
                    }

                    ans.push_back(to_string(ip1) + "." + to_string(ip2) + "." + to_string(ip3) + "." + to_string(ip4));
                }
            }
        }

        return ans;
    }

private:
    int svtoi(string_view s) {
        int n = 0;
        if (s.size() > 1 && s[0] == '0') {
            return 256;
        }

        for (auto i : s) {
            n = n * 10 + i - '0';
            if (n > 255) {
                break;
            }
        }

        return n;
    }
};