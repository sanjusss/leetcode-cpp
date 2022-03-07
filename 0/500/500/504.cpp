#include "leetcode.h"

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0"s;
        }

        bool ng = num < 0;
        num = abs(num);
        string ans;
        while (num != 0) {
            ans.push_back('0' + (num % 7));
            num /= 7;
        }

        if (ng) {
            ans.push_back('-');
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};