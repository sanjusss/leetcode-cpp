#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool canReach(vector<int>& arr, int start) 
    {
        unordered_set<int> reached;
        return canReach(arr, start, reached);
    }

private:
    bool canReach(vector<int>& arr, int start, unordered_set<int>& reached)
    {
        reached.insert(start);
        if (arr[start] == 0)
        {
            return true;
        }

        bool res = false;
        int right = start + arr[start];
        if (right < arr.size() && reached.find(right) == reached.end())
        {
            res = canReach(arr, right, reached);
        }

        int left = start - arr[start];
        if (res == false && left >= 0 && reached.find(left) == reached.end())
        {
            res = canReach(arr, left, reached);
        }

        return res;
    }
};