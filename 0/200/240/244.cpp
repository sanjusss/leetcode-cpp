/*
 * @Author: sanjusss
 * @Date: 2022-02-10 11:02:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-10 11:15:36
 * @FilePath: \0\200\240\244.cpp
 */
#include "leetcode.h"

class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); ++i) {
            m_pos[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int ans = INT_MAX;
        auto& i1 = m_pos[word1];
        auto& i2 = m_pos[word2];
        int j1 = 0;
        int j2 = 0;
        while (j1 < i1.size() && j2 < i2.size()) {
            ans = min(abs(i1[j1] - i2[j2]), ans);
            if (i1[j1] < i2[j2]) {
                j1++;
            }
            else {
                j2++;
            }

        }

        return ans;
    }

private:
    unordered_map<string, vector<int>> m_pos;
};