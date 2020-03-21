#pragma once
#include "leetcode.h"

//class Q : public priority_queue<int>
//{
//public:
//    using priority_queue<int>::priority_queue;
//    vector<int>& container()
//    {
//        return c;
//    }
//};
//
//class Solution
//{
//public:
//    vector<int> getLeastNumbers(vector<int>& arr, int k)
//    {
//        Q q;
//        for (auto i : arr)
//        {
//            q.push(i);
//            if (q.size() > k)
//            {
//                q.pop();
//            }
//        }
//
//        vector<int> ans;
//        ans.swap(q.container());
//        return ans;
//    }
//};

//class Solution
//{
//public:
//    vector<int> getLeastNumbers(vector<int>& arr, int k) 
//    {
//        if (arr.size() <= k)
//        {
//            return arr;
//        }
//
//        sort(arr.begin(), arr.end());
//        arr.resize(k);
//        return arr;
//    }
//};

class Solution
{
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        if (arr.size() <= k)
        {
            return arr;
        }

        nth_element(arr.begin(), arr.begin() + k, arr.end());
        arr.resize(k);
        return arr;
    }
};