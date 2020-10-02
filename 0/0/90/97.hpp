#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    bool isInterleave(string s1, string s2, string s3) {
//        if (s1.size() + s2.size() != s3.size()) {
//            return false;
//        }
//
//        stack<tuple<string::iterator, string::iterator, string::iterator>> s;
//        s.push({ s1.begin(), s2.begin(), s3.begin() });
//        auto e1 = s1.end();
//        auto e2 = s2.end();
//        auto e3 = s3.end();
//        while (!s.empty()) {
//            auto& t = s.top();
//            auto t1 = get<0>(t);
//            auto t2 = get<1>(t);
//            auto t3 = get<2>(t);
//            s.pop();
//            if (t1 == e1 && t2 == e2) {
//                return true;
//            }
//            else if (t1 == e1) {
//                if (equal(t2, e2, t3, e3)) {
//                    return true;
//                }
//            }
//            else if (t2 == e2) {
//                if (equal(t1, e1, t3, e3)) {
//                    return true;
//                }
//            }
//            else {
//                if (*t1 == *t2) {
//                    if (*t1 == *t3) {
//                        if (equal(t1, e1, t2, e2)) {
//                            do {
//                                ++t1;
//                                ++t3;
//                            } while (t1 != e1 && *t1 == *t3);
//                            s.push({ t1, t2, t3 });
//                        }
//                        else {
//                            s.push({ t1, next(t2), next(t3) });
//                            s.push({ next(t1), t2, next(t3) });
//                        }
//                    }
//                }
//                else if (*t1 == *t3) {
//                    do {
//                        ++t1;
//                        ++t3;
//                    } while (t1 != e1 && *t1 != *t2 && *t1 == *t3);
//                    s.push({ t1, t2, t3 });
//                }
//                else if (*t2 == *t3) {
//                    do {
//                        ++t2;
//                        ++t3;
//                    } while (t2 != e2 && *t1 != *t2 && *t2 == *t3);
//                    s.push({ t1, t2, t3 });
//                }
//            }
//        }
//
//        return false;
//    }
//};

//class Solution {
//public:
//    bool isInterleave(string s1, string s2, string s3) {
//        int n1 = s1.size();
//        int n2 = s2.size();
//        int n3 = s3.size();
//        if (n1 + n2 != n3) {
//            return false;
//        }
//
//        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1));
//        dp[0][0] = true;
//        for (int i = 0; i < n1 && s1[i] == s3[i]; ++i) {
//            dp[i + 1][0] = true;
//        }
//
//        for (int j = 0; j < n2 && s2[j] == s3[j]; ++j) {
//            dp[0][j + 1] = true;
//        }
//
//        for (int i = 0; i < n1; ++i) {
//            for (int j = 0; j < n2; ++j) {
//                dp[i + 1][j + 1] = (s1[i] == s3[i + j + 1] && dp[i][j + 1]) || (s2[j] == s3[i + j + 1] && dp[i + 1][j]);
//            }
//        }
//
//        return dp[n1][n2];
//    }
//};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        if (s1.size() < s2.size()) {
            swap(s1, s2);
        }

        int n1 = s1.size();
        int n2 = s2.size();
        vector<bool> dp(n2 + 1);
        dp[0] = true;
        for (int i = 0; i <= n1; ++i) {
            for (int j = 0; j <= n2; ++j) {
                int k = i + j - 1;

                if (i > 0) {
                    dp[j] = dp[j] && (s1[i - 1] == s3[k]);
                }

                if (j > 0) {
                    dp[j] = dp[j] || (dp[j - 1] && s2[j - 1] == s3[k]);
                }
            }
        }

        return dp[n2];
    }
};