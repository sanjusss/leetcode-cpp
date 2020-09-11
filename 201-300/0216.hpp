#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    vector<vector<int>> combinationSum3(int k, int n) {
//        vector<vector<int>> ans;
//        if (k > 0) {
//            dfs(ans, k, n, {}, 1);
//        }
//
//        return ans;
//    }
//
//private:
//    void dfs(vector<vector<int>>& ans, int k, int n, vector<int> cur, int i) {
//        cur.push_back(0);
//        for (int j = i; j <= 9 - k + 1; ++j) {
//            if (n - j < 0) {
//                break;
//            }
//            
//            cur.back() = j;
//            if (n - j == 0) {
//                if (k == 1) {
//                    ans.push_back(cur);
//                }
//                else {
//                    break;
//                }
//            }
//            else {
//                if (k > 1) {
//                    dfs(ans, k - 1, n - j, cur, j + 1);
//                }
//            }
//        }
//    }
//};

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if (k > 0) {
            vector<int> cur;
            dfs(ans, k, n, cur, 1);
        }

        return ans;
    }

private:
    void dfs(vector<vector<int>>& ans, int k, int n, vector<int>& cur, int i) {
        cur.push_back(0);
        for (int j = i; j <= 9 - k + 1; ++j) {
            if (n - j < 0) {
                break;
            }

            cur.back() = j;
            if (n - j == 0) {
                if (k == 1) {
                    ans.push_back(cur);
                }
                else {
                    break;
                }
            }
            else {
                if (k > 1) {
                    dfs(ans, k - 1, n - j, cur, j + 1);
                }
            }
        }

        cur.pop_back();
    }
};