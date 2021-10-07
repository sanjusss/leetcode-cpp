/*
 * @Author: sanjusss
 * @Date: 2021-10-05 10:12:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-05 11:21:33
 * @FilePath: \0\200\280\284.cpp
 */
#include "leetcode.h"

class Iterator {
    struct Data;
    Data* data;

public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!cur) {
            cur = Iterator::next();
        }

        return cur.value();
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (cur) {
            int v = cur.value();
            cur.reset();
            return v;
        }
        else {
            cur.reset();
            return Iterator::next();
        }
    }

    bool hasNext() const {
        return cur || Iterator::hasNext();
    }

private:
    optional<int> cur;
};