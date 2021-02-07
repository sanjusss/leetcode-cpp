#include "leetcode.h"

// class Solution {
// public:
//     int maximumScore(int a, int b, int c) {
//         sort(a, b, c);
//         int ans = 0;
//         while (b > 0) {
//             --a;
//             --b;
//             ++ans;
//             sort(a, b, c);
//         }

//         return ans;
//     }

// private:
//     void sort(int& a, int& b, int& c) {
//         if (a < b) {
//             swap(a, b);
//         }

//         if (b < c) {
//             swap(b, c);
//         }

//         if (a < b) {
//             swap(a, b);
//         }
//     }
// };

// class Solution {
// public:
//     int maximumScore(int a, int b, int c) {
//         array<int, 3> arr = { a, b, c };
//         sort(arr.rbegin(), arr.rend());
//         int& i0 = arr[0];
//         int& i1 = arr[1];
//         int& i2 = arr[2];
//         int ans = 0;
//         if (i1 != i2) {
//             ans += i1 - i2;
//             i0 -= i1 - i2;
//             i1 = i2;
//         }

//         ans += min(((i0 + i1 + i2) / 2), (i1 + i2));
//         return ans;
//     }
// };

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        array<int, 3> arr = { a, b, c };
        sort(arr.rbegin(), arr.rend());
        if (arr[1] + arr[2] > arr[0]) {
            return (arr[0] + arr[1] + arr[2]) / 2;
        }
        else {
            return arr[1] + arr[2];
        }
    }
};

TEST(&Solution::maximumScore)