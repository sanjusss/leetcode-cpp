#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int nums = 0;
        int xLength = grid.size();
        if (xLength == 0)
        {
            return nums;
        }

        int yLength = grid[0].size();
        for (int x = 0; x < xLength; ++x)
        {
            for (int y = 0; y < yLength; ++y)
            {
                if (grid[x][y] == '1')
                {
                    ++nums;
                    clearLand(x, y, xLength, yLength, grid);
                }
            }
        }

        return nums;
    }

private:
    void  clearLand(int x, int y, int xLength, int yLength, vector<vector<char>>& grid)
    {
        grid[x][y] = '0';

        if (x != 0 && grid[x - 1][y] == '1')
        {
            clearLand(x - 1, y, xLength, yLength, grid);
        }

        if (y != 0 && grid[x][y - 1] == '1')
        {
            clearLand(x, y - 1, xLength, yLength, grid);
        }

        if (x + 1 != xLength && grid[x + 1][y] == '1')
        {
            clearLand(x + 1, y, xLength, yLength, grid);
        }

        if (y + 1 != yLength && grid[x][y + 1] == '1')
        {
            clearLand(x, y + 1, xLength, yLength, grid);
        }
    }
};

//class Solution
//{
//public:
//    int numIslands(vector<vector<char>>& grid)
//    {
//        int nums = 0;
//        m_xLength = grid.size();
//        if (m_xLength == 0)
//        {
//            return nums;
//        }
//
//        m_yLength = grid[0].size();
//        if (m_yLength == 0)
//        {
//            return nums;
//        }
//
//        m_used.clear();
//        m_q = queue<pair<int, int>>({ { 0, 0 } });
//        do
//        {
//            int length = m_q.size();
//            for (int i = 0; i < length; ++i)
//            {
//                auto pos = m_q.front();
//                m_q.pop();
//
//                if (m_used.find(pos) != m_used.cend())
//                {
//                    continue;
//                }
//                else if (grid[pos.first][pos.second] == '0')
//                {
//                    m_used.insert(pos);
//                    createNextQueue(pos, m_q);
//                    continue;
//                }
//
//                completeLand(pos, grid);
//                ++nums;
//            }
//        } while (m_q.empty() == false);
//
//        return nums;
//    }
//
//private:
//    list<pair<int, int>> neighbors(pair<int, int> pos)
//    {
//        list<pair<int, int>> res;
//        if (pos.first > 0)
//        {
//            pair<int, int> n = { pos.first - 1, pos.second };
//            if (m_used.find(n) == m_used.cend())
//            {
//                res.push_back(n);
//            }
//        }
//
//        if (pos.second > 0)
//        {
//            pair<int, int> n = { pos.first, pos.second - 1 };
//            if (m_used.find(n) == m_used.cend())
//            {
//                res.push_back(n);
//            }
//        }
//
//        if (pos.first < m_xLength - 1)
//        {
//            pair<int, int> n = { pos.first + 1, pos.second };
//            if (m_used.find(n) == m_used.cend())
//            {
//                res.push_back(n);
//            }
//        }
//
//        if (pos.second < m_yLength - 1)
//        {
//            pair<int, int> n = { pos.first, pos.second + 1 };
//            if (m_used.find(n) == m_used.cend())
//            {
//                res.push_back(n);
//            }
//        }
//
//        return res;
//    }
//
//    void completeLand(pair<int, int> pos, vector<vector<char>> & grid)
//    {
//        queue<pair<int, int>> q({ pos });
//        do
//        {
//            auto p = q.front();
//            q.pop();
//            if (m_used.find(p) != m_used.cend())
//            {
//                continue;
//            }
//
//            m_used.insert(p);
//            if (grid[p.first][p.second] == '0')
//            {
//                createNextQueue(p, m_q);
//            }
//            else
//            {
//                createNextQueue(p, q);
//            }
//        } while (q.empty() == false);
//    }
//
//    void createNextQueue(pair<int, int> pos, queue<pair<int, int>> & q)
//    {
//        auto ns = neighbors(pos);
//        for (auto i : ns)
//        {
//            q.push(i);
//        }
//    }
//
//private:
//    int m_xLength;
//    int m_yLength;
//    queue<pair<int, int>> m_q;
//    set<pair<int, int>> m_used;
//};