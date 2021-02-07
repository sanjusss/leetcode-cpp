#include "leetcode.h"

// class Solution {
// public:
//     string largestMerge(string word1, string word2) {
//         string ans;
//         int n1 = word1.size();
//         int n2 = word2.size();
//         ans.reserve(n1 + n2);
//         int i = 0;
//         int j = 0;
//         string_view s1 = word1;
//         string_view s2 = word2;
//         while (i < n1 && j < n2) {
//             if (s1.substr(i) > s2.substr(j)) {
//                 ans.push_back(s1[i++]);
//             }
//             else {
//                 ans.push_back(s2[j++]);
//             }
//         }

//         ans += s1.substr(i);
//         ans += s2.substr(j);
//         return ans;
//     }
// };

class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans;
        int n1 = word1.size();
        int n2 = word2.size();
        ans.reserve(n1 + n2);
        int i = 0;
        int j = 0;
        while (i < n1 && j < n2) {
            bool addI = false;
            int k = 0;
            while (i + k < n1 && j + k < n2) {
                if (word1[i + k] > word2[j + k]) {
                    addI = true;
                    break;
                }
                else if (word1[i + k] < word2[j + k]) {
                    break;
                }
                else {
                    ++k;
                }
            }

            if (i + k == n1 || j + k == n2) {
                addI = j + k == n2;
            }

            if (addI) {
                ans.push_back(word1[i++]);
            }
            else {
                ans.push_back(word2[j++]);
            }
        }

        ans += word1.substr(i) + word2.substr(j);
        return ans;
    }
};

TEST(&Solution::largestMerge)