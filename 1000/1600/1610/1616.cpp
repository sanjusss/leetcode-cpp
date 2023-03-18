#include "leetcode.h"

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return isPalindrome(a, b) || isPalindrome(b, a);
    }

private:
    bool isPalindrome(const string& a, const string& b) {
        int left = 0;
        int right = b.size() - 1;
        while (left < right && a[left] == b[right]) {
            ++left;
            --right;
        }

        return isPartPalindrome(a, left, right) || isPartPalindrome(b, left, right);
    }

    bool isPartPalindrome(const string& a, int left, int right) {
        while (left < right && a[left] == a[right]) {
            ++left;
            --right;
        }

        return left >= right;
    }
};