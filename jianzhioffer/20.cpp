/*
 * @Author: sanjusss
 * @Date: 2021-08-31 09:04:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-31 09:44:07
 * @FilePath: \jianzhioffer\20.cpp
 */
#include "leetcode.h"

class Solution {
    enum State {
        Start,
        Space1,
        Pos1,
        Neg1,
        D1,
        Dot1,  //之前有D1，
        Dot2,  //之前没D1,
        D2,
        e,
        E,
        Pos2,
        Neg2,
        D3,
        Space2
    };

public:
    bool isNumber(string s) {
        static unordered_map<State, unordered_map<char, State>> nexts = createNexts();
        State cur = Start;
        for (char i : s) {
            auto& next = nexts[cur];
            auto p = next.find(i);
            if (p == next.end()) {
                return false;
            }
            else {
                cur = p->second;
            }
        }

        switch (cur) {
            case D1:
            case Dot1:
            case D2:
            case D3:
            case Space2:
                return true;

            default:
                return false;
        }
    }

private:
    static unordered_map<State, unordered_map<char, State>> createNexts() {
        unordered_map<State, unordered_map<char, State>> c;
        auto addD = [&c] (State from, State to) {
            auto& n = c[from];
            for (char i = '0'; i <= '9'; ++i) {
                n[i] = to;
            }
        };
        auto addE = [&c] (State from) {
            auto& n = c[from];
            n['e'] = e;
            n['E'] = E;
        };

        c[Start][' '] = Space1;
        c[Start]['+'] = Pos1;
        c[Start]['-'] = Neg1;
        c[Start]['.'] = Dot2;
        addD(Start, D1);

        c[Space1]['+'] = Pos1;
        c[Space1]['-'] = Neg1;
        c[Space1]['.'] = Dot2;
        c[Space1][' '] = Space1;
        addD(Space1, D1);

        c[Pos1]['.'] = Dot2;
        addD(Pos1, D1);
        c[Neg1]['.'] = Dot2;
        addD(Neg1, D1);

        c[D1]['.'] = Dot1;
        c[D1][' '] = Space2;
        addD(D1, D1);
        addE(D1);

        c[Dot1][' '] = Space2;
        addD(Dot1, D2);
        addE(Dot1);

        addD(Dot2, D2);

        c[D2][' '] = Space2;
        addD(D2, D2);
        addE(D2);

        c[e]['+'] = Pos2;
        c[e]['-'] = Neg2;
        addD(e, D3);

        c[E]['+'] = Pos2;
        c[E]['-'] = Neg2;
        addD(E, D3);

        addD(Pos2, D3);
        addD(Neg2, D3);

        c[D3][' '] = Space2;
        addD(D3, D3);

        c[Space2][' '] = Space2;

        return c;
    }
};

TEST(&Solution::isNumber)