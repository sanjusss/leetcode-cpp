/*
 * @Author: sanjusss
 * @Date: 2021-09-02 08:21:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-02 08:29:54
 * @FilePath: \jianzhioffer\38_20210902.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<string> permutation(string s) {
//         sort(s.begin(), s.end());
//         vector<string> ans;
//         do {
//             ans.push_back(s);
//         } while (next_permutation(s.begin(), s.end()));
//         return ans;
//     }
// };

class Solution {
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<string> ans;
        do {
            ans.push_back(s);
        } while (next(s));
        return ans;
    }

private:
    bool next(string& s) {
        int n = s.size();
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] >= s[i + 1]) {
                continue;
            }

            for (int j = n - 1; j > i; --j) {
                if (s[i] >= s[j]) {
                    continue;
                }

                swap(s[i], s[j]);
                int k = i + 1;
                int l = n - 1;
                while (k < l) {
                    swap(s[k++], s[l--]);
                }

                return true;
            }
        }

        return false;
    }
};