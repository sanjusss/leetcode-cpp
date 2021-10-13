/*
 * @Author: sanjusss
 * @Date: 2021-10-13 08:28:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-13 08:31:20
 * @FilePath: \0\400\410\412_20211013.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) {
                ans.push_back("FizzBuzz"s);
            }
            else if (i % 3 == 0) {
                ans.push_back("Fizz"s);
            }
            else if (i % 5 == 0) {
                ans.push_back("Buzz"s);
            }
            else {
                ans.push_back(to_string(i));
            }
        }

        return ans;
    }
};