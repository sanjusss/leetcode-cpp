/*
 * @Author: sanjusss
 * @Date: 2021-06-17 08:48:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-17 10:08:23
 * @FilePath: \0\0\60\65_20210617.cpp
 */
#include "leetcode.h"

class Solution {
    enum State : int { ERROR = 0, DOT, POS_1, POS_2, NEG_1, NEG_2, E_LOW, E_UP, X_DOT, BEGIN, D_1, D_2, D_3 };

public:
    bool isNumber(string s) {
        unordered_map<State, unordered_map<char, State>>& trans = init();

        State cur = BEGIN;
        for (char i : s) {
            cur = trans[cur][i];
            if (cur == ERROR) {
                return false;
            }
        }

        switch (cur) {
            case X_DOT:
            case D_1:
            case D_2:
            case D_3:
                return true;

            default:
                return false;
        }
    }

private:
    static unordered_map<State, unordered_map<char, State>>& init() {
        static unordered_map<State, unordered_map<char, State>> trans;
        if (!trans.empty()) {
            return trans;
        }

        auto addDigit = [](State from, State to) {
            for (char i = '0'; i <= '9'; ++i) {
                trans[from][i] = to;
            }
        };
        addDigit(DOT, D_2);
        trans[POS_1]['.'] = DOT;
        addDigit(POS_1, D_1);
        addDigit(POS_2, D_3);
        trans[NEG_1]['.'] = DOT;
        addDigit(NEG_1, D_1);
        addDigit(NEG_2, D_3);
        trans[E_LOW]['+'] = POS_2;
        trans[E_UP]['+'] = POS_2;
        trans[E_LOW]['-'] = NEG_2;
        trans[E_UP]['-'] = NEG_2;
        addDigit(E_LOW, D_3);
        addDigit(E_UP, D_3);
        trans[X_DOT]['e'] = E_LOW;
        trans[X_DOT]['E'] = E_UP;
        addDigit(X_DOT, D_2);
        trans[BEGIN]['.'] = DOT;
        trans[BEGIN]['+'] = POS_1;
        trans[BEGIN]['-'] = NEG_1;
        addDigit(BEGIN, D_1);
        trans[D_1]['e'] = E_LOW;
        trans[D_1]['E'] = E_UP;
        trans[D_1]['.'] = X_DOT;
        addDigit(D_1, D_1);
        trans[D_2]['e'] = E_LOW;
        trans[D_2]['E'] = E_UP;
        addDigit(D_2, D_2);
        addDigit(D_3, D_3);
        return trans;
    }
};

TEST(&Solution::isNumber)