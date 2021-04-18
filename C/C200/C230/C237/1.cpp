#include "leetcode.h"

class Solution {
public:
    bool checkIfPangram(string sentence) {
        array<int, 26> cnt = { 0 };
        for (char i : sentence) {
            cnt[i - 'a'] = 1;
        }

        for (int i : cnt) {
            if (i == 0) {
                return false;
            }
        }

        return true;
    }
};