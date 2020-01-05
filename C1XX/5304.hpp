#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
//    {
//        vector<int> res;
//        for (auto& query : queries)
//        {
//            int start = query[0];
//            int end = query[1];
//            int temp = arr[start];
//            for (int i = start + 1; i <= end; ++i)
//            {
//                temp ^= arr[i];
//            }
//
//            res.push_back(temp);
//        }
//
//        return res;
//    }
//};
class Solution
{
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
    {
        vector<int> xors(arr.size() + 1, 0);
        for (int i = 0; i < arr.size(); ++i)
        {
            xors[i + 1] = xors[i] ^ arr[i];
        }

        vector<int> res;
        for (auto& i : queries)
        {
            res.push_back(xors[i[0]] ^ xors[i[1] + 1]);
        }

        return res;
    }
};