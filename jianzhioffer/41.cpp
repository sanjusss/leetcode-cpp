/*
 * @Author: sanjusss
 * @Date: 2021-08-22 10:11:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-22 10:25:36
 * @FilePath: \jianzhioffer\41.cpp
 */
#include "leetcode.h"

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (smaller.size() > bigger.size()) {
            bigger.push(num);
        }
        else {
            smaller.push(num);
        }

        if (!smaller.empty() && !bigger.empty() && smaller.top() > bigger.top()) {
            int b = smaller.top();
            smaller.pop();
            int s = bigger.top();
            bigger.pop();
            smaller.push(s);
            bigger.push(b);
        }
    }
    
    double findMedian() {
        if (smaller.size() > bigger.size()) {
            return smaller.top();
        }
        else {
            return (smaller.top() + bigger.top()) / 2.0;
        }
    }

private:
    priority_queue<int> smaller;
    priority_queue<int, vector<int>, greater<int>> bigger;
};