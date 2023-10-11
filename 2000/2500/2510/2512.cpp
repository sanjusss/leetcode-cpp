/*
 * @Author: sanjusss
 * @Date: 2023-10-11 09:18:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-10-11 09:35:14
 * @FilePath: \2000\2500\2510\2512.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> pos(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> neg(negative_feedback.begin(), negative_feedback.end());
        vector<pair<int, int>> arr;
        int n = report.size();
        for (int i = 0; i < n; ++i) {
            string &s = report[i];
            int m = s.size();
            string word;
            int score = 0;
            for (int j = 0; j <= m; ++j) {
                if (j == m || s[j] == ' ') {
                    if (pos.count(word)) {
                        score += 3;
                    }
                    else if (neg.count(word)) {
                        score -= 1;
                    }

                    word.clear();
                }
                else {
                    word.push_back(s[j]);
                }
            }

            arr.emplace_back(score, student_id[i]);
        }

        partial_sort(arr.begin(), arr.begin() + k, arr.end(), [] (const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            else {
                return a.first > b.first;
            }
        });
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(arr[i].second);
        }

        return ans;
    }
};