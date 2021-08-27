/*
 * @Author: sanjusss
 * @Date: 2021-08-27 14:00:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-27 14:02:58
 * @FilePath: \0\200\290\295.cpp
 */
#include "leetcode.h"

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (smaller.size() > bigger.size()) {
            smaller.push(num);
            bigger.push(smaller.top());
            smaller.pop();
        }
        else {
            bigger.push(num);
            smaller.push(bigger.top());
            bigger.pop();
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
