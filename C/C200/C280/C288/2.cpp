/*
 * @Author: sanjusss
 * @Date: 2022-04-10 10:28:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-10 11:13:43
 * @FilePath: \C\C200\C280\C288\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string minimizeResult(string expression) {
        int pos = expression.find('+');
        int a = stoi(expression.substr(0, pos));
        int asize = pos;
        int b = stoi(expression.substr(pos + 1));
        int bsize = expression.size() - pos - 1;

        int result = INT_MAX;
        int apos = 0;
        int bpos = 0;
        int abits = 1;
        for (int ai = 0; ai < asize; ++ai) {
            abits *= 10;
            int suba = a % abits;
            int afactor = a / abits;
            if (afactor == 0) {
                afactor = 1;
            }
            
            int bbits = 1;
            for (int bi = 0; bi < bsize; ++bi) {
                int subb = b / bbits;
                int bfactor = b % bbits;
                if (bfactor == 0) {
                    bfactor = 1;
                }

                int val = afactor * (suba + subb) * bfactor;
                if (val < result) {
                    result = val;
                    apos = ai;
                    bpos = bi;
                }

                bbits *= 10;
            }
        }

        expression.insert(pos - 1 - apos, "("s);
        expression.insert(expression.size() - bpos, ")"s);
        return expression;
    }
};

TEST(&Solution::minimizeResult)