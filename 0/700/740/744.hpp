#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    char nextGreatestLetter(vector<char>& letters, char target) 
//    {
//        if (target == 'z')
//        {
//            target = 'a';
//        }
//        else
//        {
//            ++target;
//        }
//
//        auto res = lower_bound(letters.begin(), letters.end(), target);
//        if (res == letters.end())
//        {
//            return letters.front();
//        }
//        else
//        {
//            return *res;
//        }
//    }
//};
class Solution
{
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
        if (target == 'z')
        {
            target = 'a';
        }
        else
        {
            ++target;
        }

        int left = 0;
        int right = letters.size();
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (letters[mid] >= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        if (left == letters.size() || letters[left] < target)
        {
            return letters.front();
        }
        else
        {
            return letters[left];
        }
    }
};