/*
 * @Author: sanjusss
 * @Date: 2023-01-16 11:54:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-16 12:06:52
 * @FilePath: \1000\1800\1810\1813.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.size() == sentence2.size()) {
            return sentence1 == sentence2;
        }
        else if (sentence1.size() < sentence2.size()) {
            swap(sentence1, sentence2);
        }

        auto startWith = [&sentence1, &sentence2] (int len) {
            for (int i = 0; i < len; ++i) {
                if (sentence1[i] != sentence2[i]) {
                    return false;
                }
            }

            return sentence1[len] == ' '; 
        };

        int n1 = sentence1.size();
        int n2 = sentence2.size();
        auto endWith = [&sentence1, &sentence2, &n1, &n2] (int len) {
            for (int i = 0; i < len; ++i) {
                if (sentence1[n1 - 1 - i] != sentence2[n2 - 1 - i]) {
                    return false;
                }
            }

            return sentence1[n1 - 1 - len] == ' '; 
        };
        if (startWith(n2) || endWith(n2)) {
            return true;
        }

        for (int i = 0; i < n2; ++i) {
            if (sentence2[i] != ' ') {
                continue;
            }

            if (startWith(i) && endWith(n2 - 1 - i)) {
                return true;
            }
        }

        return false;
    }
};