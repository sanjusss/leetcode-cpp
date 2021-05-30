/*
 * @Author: sanjusss
 * @Date: 2021-05-30 10:29:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-30 10:48:52
 * @FilePath: \C\C200\C240\C243\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string maxValue(string n, int x) {
        char t = x + '0';
        int size = n.size();
        if (size == 1 && n[0] == '0') {
            n[0] = t;
        }
        else if (n[0] == '-') {
            if (x != 0) {
                for (int i = 1; i < size; ++i) {
                    if (t < n[i]) {
                        n.insert(i, 1, t);
                        break;
                    }
                }

                if (n.size() == size) {
                    n.push_back(t);
                }
            }
        }
        else {
            for (int i = 0; i < size; ++i) {
                if (t > n[i]) {
                    n.insert(i, 1, t);
                    break;
                }
            }
            
            if (n.size() == size) {
                n.push_back(t);
            }
        }

        return n;
    }
};