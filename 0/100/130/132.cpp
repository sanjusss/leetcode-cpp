/*
 * @Author: sanjusss
 * @Date: 2021-01-31 13:36:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-31 14:05:36
 * @FilePath: \0\100\130\132.cpp
 */
#include "leetcode.h"

class Solution {
    class Partition {
    public:
        Partition(const string& s) {
            int n = s.size() * 2 + 1;
            string temp;
            temp.reserve(n);
            temp.push_back('#');
            for (char i : s) {
                temp.push_back(i);
                temp.push_back('#');
            }

            m_length.reserve(n);
            int left = 0;
            int right = -1;
            for (int i = 0; i < n; ++i) {
                if (i >= left && i <= right) {
                    m_length.push_back(min((right - i) * 2 + 1, m_length[right + left - i]));
                }
                else {
                    m_length.push_back(1);
                }

                int j = m_length[i] / 2 + 1;
                while (i - j >= 0 && i + j < n && temp[i - j] == temp[i + j]) {
                    ++j;
                }

                if (j > m_length[i] / 2 + 1) {
                    m_length[i] = j * 2 - 1;
                    left = i - j + 1;
                    right = i + j - 1;
                }
            }
        }

        bool isPalindrome(int begin, int end) const {
            return m_length[end + begin] / 2 >= end - begin;
        }

    private:
        vector<int> m_length;
    };

public:
    int minCut(string s) {
        Partition part(s);
        
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (part.isPalindrome(j, i + 1)) {
                    dp[i + 1] = min(dp[i + 1], dp[j] + 1);
                }
            }
        }

        return dp[n] - 1;
    }
};

TEST(Solution::minCut)