#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    vector<vector<int>> combine(int n, int k) {
//        vector<vector<int>> ans;
//        if (k <= 0) {
//            return ans;
//        }
//
//        multimap<int, vector<int>> cur;
//        for (int i = n - k + 1; i > 0; --i) {
//            cur.insert({ i, { i } });
//        }
//
//        for (int i = 2; i <= k; ++i) {
//            multimap<int, vector<int>> next;
//            for (int j = n - k + i; j >= i; --j) {
//                auto end = cur.lower_bound(j);
//                for (auto it = cur.begin(); it != end; ++it) {
//                    auto tmp = it->second;
//                    tmp.push_back(j);
//                    next.insert({ j, move(tmp) });
//                }
//            }
//
//            cur = move(next);
//        }
//
//        for (auto& p : cur) {
//            ans.push_back(move(p.second));
//        }
//
//        return ans;
//    }
//};

//class Solution {
//public:
//    vector<vector<int>> combine(int n, int k) {
//        vector<vector<int>> ans;
//        if (k <= 0) {
//            return ans;
//        }
//
//        for (int i = 1; i <= n;++i) {
//            ans.push_back({ i });
//        }
//
//        vector<vector<int>> index = ans;
//        auto cmp = [](const vector<int>& a, const vector<int>& b) {
//            return a.back() < b.back();
//        };
//        for (int i = 2; i <= k; ++i) {
//            sort(ans.begin(), ans.end(), cmp);
//            vector<vector<int>> next;
//            for (int j = n - k + i; j >= i; --j) {
//                auto end = lower_bound(ans.begin(), ans.end(), index[j - 1], cmp);
//                for (auto it = ans.begin(); it != end; ++it) {
//                    auto tmp = *it;
//                    tmp.push_back(j);
//                    next.push_back(move(tmp));
//                }
//            }
//
//            ans = move(next);
//        }
//
//        return ans;
//    }
//};

//class Solution {
//public:
//    vector<vector<int>> combine(int n, int k) {
//        vector<vector<int>> ans;
//        if (k <= 0) {
//            return ans;
//        }
//
//        vector<int> uses(n);
//        fill(uses.end() - k, uses.end(), 1);
//        do {
//            vector<int> tmp;
//            for (int i = 0; i < n; ++i) {
//                if (uses[i] == 1) {
//                    tmp.push_back(i + 1);
//                }
//            }
//
//            ans.push_back(tmp);
//        } while (next_permutation(uses.begin(), uses.end()));
//
//        return ans;
//    }
//};

//class Solution {
//public:
//    vector<vector<int>> combine(int n, int k) {
//        vector<vector<int>> ans;
//        if (k <= 0) {
//            return ans;
//        }
//
//        vector<int> uses(n);
//        fill(uses.end() - k, uses.end(), 1);
//        do {
//            vector<int> tmp;
//            for (int i = 0; i < n; ++i) {
//                if (uses[i] == 1) {
//                    tmp.push_back(i + 1);
//                }
//            }
//
//            ans.push_back(tmp);
//        } while (next_permutation(uses.begin(), uses.end()));
//
//        return ans;
//    }
//};

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        dfs(ans, n, k, {});
        return ans;
    }

private:
    void dfs(vector<vector<int>>& ans, int n, int k, vector<int> cur) {
        if (cur.size() == k) {
            ans.push_back(move(cur));
            return;
        }

        int begin = cur.empty() ? 1 : cur.back() + 1;
        int end = n - k + cur.size() + 1;
        cur.push_back(0);
        for (int i = begin; i <= end; ++i) {
            cur.back() = i;
            dfs(ans, n, k, cur);
        }
    }
};