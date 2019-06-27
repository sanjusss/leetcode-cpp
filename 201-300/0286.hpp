#pragma once
#include "leetcode.h"

class Solution 
{
public:
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        int m = rooms.size();
        if (m == 0)
        {
            return;
        }

        int n = rooms[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (rooms[i][j] == 0)
                {
                    calc(rooms, m, n, i, j, 0);
                }
            }
        }
    }

    void calc(vector<vector<int>>& rooms, int m, int n, int x, int y, int step)
    {
        if (rooms[x][y] < 0)
        {
            return;
        }

        if (rooms[x][y] == 0)
        {
            if (step > 0)
            {
                return;
            }
        }
        else
        {
            if (step >= rooms[x][y])
            {
                return;
            }

            rooms[x][y] = step;
        }

        ++step;

        if (x > 0)
        {
            calc(rooms, m, n, x - 1, y, step);
        }

        if (x < m - 1)
        {
            calc(rooms, m, n, x + 1, y, step);
        }

        if (y > 0)
        {
            calc(rooms, m, n, x, y - 1, step);
        }

        if (y < n - 1)
        {
            calc(rooms, m, n, x, y + 1, step);
        }
    }
};

//class Solution
//{
//public:
//    void wallsAndGates(vector<vector<int>>& rooms)
//    {
//        int m = rooms.size();
//        if (m == 0)
//        {
//            return;
//        }
//
//        int n = rooms[0].size();
//        queue<pair<int, int>> q;
//        for (int i = 0; i < m; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                if (rooms[i][j] == 0)
//                {
//                    q.push(make_pair(i, j));
//                }
//            }
//        }
//
//        for (int dis = 1; q.empty() == false; ++dis)
//        {
//            int length = q.size();
//            for (int i = 0; i < length; ++i)
//            {
//                int x = q.front().first;
//                int y = q.front().second;
//                q.pop();
//
//                if (x > 0)
//                {
//                    if (rooms[x - 1][y] > dis)
//                    {
//                        rooms[x - 1][y] = dis;
//                        q.push(make_pair(x - 1, y));
//                    }
//                }
//
//                if (x < m - 1)
//                {
//                    if (rooms[x + 1][y] > dis)
//                    {
//                        rooms[x + 1][y] = dis;
//                        q.push(make_pair(x + 1, y));
//                    }
//                }
//
//                if (y > 0)
//                {
//                    if (rooms[x][y - 1] > dis)
//                    {
//                        rooms[x][y - 1] = dis;
//                        q.push(make_pair(x, y - 1));
//                    }
//                }
//
//                if (y < n - 1)
//                {
//                    if (rooms[x][y + 1] > dis)
//                    {
//                        rooms[x][y + 1] = dis;
//                        q.push(make_pair(x, y + 1));
//                    }
//                }
//            }
//        }
//    }
//};