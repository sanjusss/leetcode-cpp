#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
//    {
//        //相交面积大于0
//        long width = ((long)rec1[2] - (long)rec1[0]) + ((long)rec2[2] - (long)rec2[0]) - (max((long)rec1[2], (long)rec2[2]) - min((long)rec1[0], (long)rec2[0]));
//        long height = ((long)rec1[3] - (long)rec1[1]) + ((long)rec2[3] - (long)rec2[1]) - (max((long)rec1[3], (long)rec2[3]) - min((long)rec1[1], (long)rec2[1]));
//        return width > 0 && height > 0;
//    }
//};

class Solution
{
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
    {
        //相交面积大于0
        return !(rec1[2] <= rec2[0] || rec2[2] <= rec1[0] ||
            rec1[3] <= rec2[1] || rec2[3] <= rec1[1]);
    }
};