#pragma once
#include "leetcode.h"

//struct pair_hash
//{
//    template <class T1, class T2>
//    size_t operator () (pair<T1, T2> const& pair) const
//    {
//        return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
//    }
//};
//
//class Solution
//{
//public:
//    bool canMeasureWater(int x, int y, int z)
//    {
//        if (x + y < z)
//        {
//            return false;
//        }
//
//        unordered_set<pair<int, int>, pair_hash> used;
//        stack<pair<int, int>> s;
//        s.push({ 0, 0 });
//        while (s.empty() == false)
//        {
//            auto p = s.top();
//            s.pop();
//            if (used.find(p) == used.end())
//            {
//                used.insert(p);
//            }
//            else
//            {
//                continue;
//            }
//
//            if (p.first == z || p.second == z || p.first + p.second == z)
//            {
//                return true;
//            }
//
//            if (p.first > 0)
//            {
//                s.push({ 0, p.second });
//            }
//
//            if (p.second > 0)
//            {
//                s.push({ p.first, 0 });
//            }
//
//            if (p.first < x)
//            {
//                s.push({ x, p.second });
//                if (p.second > 0)
//                {
//                    if (x - p.first > p.second)
//                    {
//                        s.push({ p.first + p.second, 0 });
//                    }
//                    else
//                    {
//                        s.push({ x, p.second - (x - p.first) });
//                    }
//                }
//            }
//
//            if (p.second < y)
//            {
//                s.push({ p.first, y });
//                if (p.first > 0)
//                {
//                    if (y - p.second > p.first)
//                    {
//                        s.push({ 0, p.first + p.second });
//                    }
//                    else
//                    {
//                        s.push({ p.first - (y - p.second), y });
//                    }
//                }
//            }
//        }
//
//        return false;
//    }
//};

class Solution 
{
public:
    bool canMeasureWater(int x, int y, int z) 
    {
        if (x + y < z)
        {
            return false;
        }

        if (x == 0 || y == 0)
        {
            return z == 0 || x + y == z;
        }
        else
        {
            return z % gcd(x, y) == 0;
        }
    }

private:
    int gcd(int a, int b)
    {
        if (a % b == 0)
        {
            return b;
        }
        else
        {
            return gcd(b, a % b);
        }
    }
};