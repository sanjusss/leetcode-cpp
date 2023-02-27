/*
 * @Author: sanjusss
 * @Date: 2023-02-27 10:52:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-27 11:34:19
 * @FilePath: \1000\1200\1250\1255.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
//         vector<int> letterCnt(26);
//         for (char c : letters) {
//             ++letterCnt[c - 'a'];
//         }

//         vector<string> valid;
//         for (auto& w : words) {
//             auto tmp = letterCnt;
//             if (useWord(w, tmp, score) > 0) {
//                 valid.push_back(move(w));
//             }
//         }

//         return calc(valid, letterCnt, score, 0);
//     }

// private:
//     int calc(const vector<string>& words, vector<int>& letterCnt, const vector<int>& score, int index) {
//         if (index == words.size()) {
//             return 0;
//         }

//         auto tempCnt = letterCnt;
//         int cur = useWord(words[index], tempCnt, score);
//         int next = calc(words, letterCnt, score, index + 1);
//         if (cur == 0) {
//             return next;
//         }

//         return max(cur + calc(words, tempCnt, score, index + 1), next);
//     }

//     int useWord(const string& word, vector<int>& letterCnt, const vector<int>& score) {
//         int res = 0;
//         for (char c : word) {
//             int i = c - 'a';
//             if (--letterCnt[i] >= 0) {
//                 res += score[i];
//             }
//             else {
//                 return 0;
//             }
//         }

//         return res;
//     }
// };

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> letterCnt(26);
        for (char c : letters) {
            ++letterCnt[c - 'a'];
        }

        int len = 0;
        for (int i = 0; i < words.size(); ++i) {
            int s = 0;
            auto cnt = letterCnt;
            for (char c : words[i]) {
                if (--cnt[c - 'a'] >= 0) {
                    s += score[c - 'a'];
                }
                else {
                    s = 0;
                    break;
                }
            }

            if (s == 0) {
                continue;
            }

            if (i != len) {
                swap(words[i], words[len]);
            }

            ++len;
        }
        
        words.resize(len);
        int ans = 0;
        for (int mask = (1 << len) - 1; mask > 0; --mask) {
            auto cnt = letterCnt;
            int s = 0;
            bool success = true;
            for (int i = 0; i < len && success; ++i) {
                if (!(mask & (1 << i))) {
                    continue;
                }

                for (char c : words[i]) {
                    if (--cnt[c - 'a'] >= 0) {
                        s += score[c - 'a'];
                    }
                    else {
                        success = false;
                        break;
                    }
                }
            }

            if (success) {
                ans = max(s, ans);
            }
        }

        return ans;
    }
};