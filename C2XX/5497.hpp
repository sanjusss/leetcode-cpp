#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    int findLatestStep(vector<int>& arr, int m) {
//        int n = arr.size();
//        if (m == n) {
//            return n;
//        }
//
//        vector<int> bits(n + 1, 1);
//        bits[0] = 0;
//        for (int i = n - 1; i >= m; --i) {
//            bits[arr[i]] = 0;
//            int l = 0;
//            int maxL = 0;
//            for (int j : bits) {
//                if (j == 0) {
//                    if (l == m) {
//                        return i;
//                    }
//                    else {
//                        maxL = max(maxL, l);
//                        l = 0;
//                    }
//                }
//                else {
//                    ++l;
//                }
//            }
//
//            if (l == m) {
//                return i;
//            }
//
//            maxL = max(maxL, l);
//            if (maxL < m) {
//                return -1;
//            }
//        }
//
//        return -1;
//    }
//};

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if (m == n) {
            return n;
        }

        map<int, int> lines;
        int ans = -1;
        unordered_set<int> founds;
        for (int i = 0; i < n; ++i) {
            int cur = arr[i];
            if (lines.empty()) {
                lines[cur] = cur;
                if (m == 1) {
                    founds.insert(cur);
                }
            }
            else {
                auto pos = lines.upper_bound(cur);
                if (pos == lines.begin()) {
                    if (cur + 1 == pos->first) {
                        founds.erase(pos->first);
                        pair<int, int> p = { cur, pos->second };
                        lines.erase(pos);
                        lines.insert(p);
                    }
                    else {
                        lines[cur] = cur;
                    }

                    if (lines[cur] - cur + 1 == m) {
                        founds.insert(cur);
                    }
                }
                else if (pos == lines.end()) {
                    auto p = prev(pos);
                    if (p->second + 1 == cur) {
                        p->second = cur;
                        if (cur - p->first + 1 == m) {
                            founds.insert(p->first);
                        }
                        else {
                            founds.erase(p->first);
                        }
                    }
                    else {
                        lines[cur] = cur;
                        if (m == 1) {
                            founds.insert(cur);
                        }
                    }
                }
                else {
                    auto before = prev(pos);
                    if (before->second + 1 == cur && pos->first - 1 == cur) {
                        founds.erase(pos->first);
                        if (pos->second - before->first + 1 == m) {
                            founds.insert(before->first);
                        }
                        else {
                            founds.erase(before->first);
                        }

                        before->second = pos->second;
                        lines.erase(pos);
                    }
                    else if (before->second + 1 == cur) {
                        before->second = cur;
                        if (cur - before->first + 1 == m) {
                            founds.insert(before->first);
                        }
                        else {
                            founds.erase(before->first);
                        }
                    }
                    else if (cur + 1 == pos->first) {
                        founds.erase(pos->first);
                        if (pos->second - cur + 1 == m) {
                            founds.insert(cur);
                        }                       
                        
                        pair<int, int> p = { cur, pos->second };
                        lines.erase(pos);
                        lines.insert(p);
                    }
                    else {
                        lines[cur] = cur;
                        if (m == 1) {
                            founds.insert(cur);
                        }
                    }
                }
            }

            if (!founds.empty()) {
                ans = i + 1;
            }
        }

        return ans;
    }
};