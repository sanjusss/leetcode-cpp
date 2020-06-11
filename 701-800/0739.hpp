#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    //感觉上速度快，实际执行时间大于下面的
//    vector<int> dailyTemperatures(vector<int>& T)
//    {
//        int length = T.size();
//        vector<int> res(length, 0);
//        for (int i = length - 2; i >= 0; --i)
//        {
//            int c = i + 1;
//            do
//            {
//                if (T[i] < T[c])
//                {
//                    res[i] = c - i;
//                    break;
//                }
//                else if (res[c] == 0)
//                {
//                    res[i] = 0;
//                    break;
//                }
//                else
//                {
//                    c += res[c];
//                }
//            } while (true);
//        }
//
//        return res;
//    }
//
//    ////强行比较所有值的取巧做法，如果温度类型改成double就会超时。
//    //vector<int> dailyTemperatures(vector<int>& T) 
//    //{
//    //    int length = T.size();
//    //    vector<int> res(length, 0);
//    //    map<int, int> temps;
//    //    for (int i = length - 1; i >= 0; --i)
//    //    {
//    //        int pos = INT_MAX;
//    //        for (auto j = temps.upper_bound(T[i]); j != temps.end(); ++j)
//    //        {
//    //            pos = min(j->second, pos);
//    //        }
//
//    //        if (pos != INT_MAX)
//    //        {
//    //            res[i] = pos - i;
//    //        }
//
//    //        temps[T[i]] = i;
//    //    }
//
//    //    return res;
//    //}
//};

//单调栈
class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& T) 
    {
        stack<int> s;
        int size = T.size();
        vector<int> ans(size);
        for (int i = 0; i < size; ++i)
        {
            while (!s.empty() && T[s.top()] < T[i])
            {
                ans[s.top()] = i - s.top();
                s.pop();
            }

            s.push(i);
        }

        return ans;
    }
};