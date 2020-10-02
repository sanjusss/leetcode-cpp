#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    //�о����ٶȿ죬ʵ��ִ��ʱ����������
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
//    ////ǿ�бȽ�����ֵ��ȡ������������¶����͸ĳ�double�ͻᳬʱ��
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

//����ջ
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