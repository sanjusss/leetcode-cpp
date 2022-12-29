/*
 * @Author: sanjusss
 * @Date: 2022-12-27 09:20:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-27 09:35:00
 * @FilePath: \0\300\300\302.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = image[0].size();
        int top = findTop(image, x, n);
        int buttom = findButtom(image, x, m, n);
        int left = findLeft(image, y, top, buttom);
        int right = findRight(image, y, n, top, buttom);
        return (right - left + 1) * (buttom - top + 1);
    }

private:
    int findTop(vector<vector<char>>& image, int x, int n) {
        int top = 0;
        int buttom = x;
        while (top < buttom) {
            int mid = (top + buttom) / 2;
            bool found = false;
            for (int i = 0; i < n; ++i) {
                if (image[mid][i] == '1') {
                    found = true;
                    break;
                }
            }

            if (found) {
                buttom = mid;
            }
            else {
                top = mid + 1;
            }
        }

        return top;
    }

    int findButtom(vector<vector<char>>& image, int x, int m, int n) {
        int top = x;
        int buttom = m - 1;
        while (top < buttom) {
            int mid = (top + buttom + 1) / 2;
            bool found = false;
            for (int i = 0; i < n; ++i) {
                if (image[mid][i] == '1') {
                    found = true;
                    break;
                }
            }

            if (found) {
                top = mid;
            }
            else {
                buttom = mid - 1;
            }
        }

        return buttom;
    }

    int findLeft(vector<vector<char>>& image, int y, int top, int buttom) {
        int left = 0;
        int right = y;
        while (left < right) {
            int mid = (left + right) / 2;
            bool found = false;
            for (int i = top; i <= buttom; ++i) {
                if (image[i][mid] == '1') {
                    found = true;
                    break;
                }
            }

            if (found) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }

    int findRight(vector<vector<char>>& image, int y, int n, int top, int buttom) {
        int left = y;
        int right = n - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            bool found = false;
            for (int i = top; i <= buttom; ++i) {
                if (image[i][mid] == '1') {
                    found = true;
                    break;
                }
            }

            if (found) {
                left = mid;
            }
            else {
                right = mid - 1;
            }
        }

        return right;
    }
};