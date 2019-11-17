#pragma once
#include "leetcode.h"

class Solution 
{
    struct Point
    {
        int bx = -1;
        int by = -1;
        int sx = -1;
        int sy = -1;

        Point()
        {

        }

        Point(int bx, int by, int sx, int sy) :
            bx(bx),
            by(by),
            sx(sx),
            sy(sy)
        {

        }

        bool isVaild() const
        {
            return bx != -1 && by != -1 && sx != -1 && sy != -1;
        }
    };

public:
    int minPushBox(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size(); 
        Point begin = Point();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                switch (grid[i][j])
                {
                case 'S':
                    begin.sx = i;
                    begin.sy = j;
                    grid[i][j] = '.';
                    break;

                case 'B':
                    begin.bx = i;
                    begin.by = j;
                    break;

                default:
                    break;
                }
            }
        }

        if (begin.isVaild() == false)
        {
            return -1;
        }

        queue<Point> q({ begin });
        int step = 0;
        do
        {
            int count = q.size();
            for (int i = 0; i < count; ++i)
            {
                auto p = q.front();
                q.pop();

                if (grid[p.bx][p.by] == 'T')
                {
                    return step;
                }

                grid[p.bx][p.by] = 'B';
                Point next;
                if (p.bx > 0 && p.bx < n - 1)
                {
                    next = Point(p.bx - 1, p.by, p.bx, p.by);
                    if (canMove(grid[p.bx - 1][p.by]) &&
                        isPassed(next) == false &&
                        canSAccess(grid, n, m, p.sx, p.sy, p.bx + 1, p.by))
                    {
                        q.push(next);
                        markPassed(next);
                    }

                    next = Point(p.bx + 1, p.by, p.bx, p.by);
                    if (canMove(grid[p.bx + 1][p.by]) &&
                        isPassed(next) == false &&
                        canSAccess(grid, n, m, p.sx, p.sy, p.bx - 1, p.by))
                    {
                        q.push(next);
                        markPassed(next);
                    }
                }

                if (p.by > 0 && p.by < m - 1)
                {
                    next = Point(p.bx, p.by - 1, p.bx, p.by);
                    if (canMove(grid[p.bx][p.by - 1]) &&
                        isPassed(next) == false &&
                        canSAccess(grid, n, m, p.sx, p.sy, p.bx, p.by + 1))
                    {
                        q.push(next);
                        markPassed(next);
                    }

                    next = Point(p.bx, p.by + 1, p.bx, p.by);
                    if (canMove(grid[p.bx][p.by + 1]) &&
                        isPassed(next) == false &&
                        canSAccess(grid, n, m, p.sx, p.sy, p.bx, p.by - 1))
                    {
                        q.push(next);
                        markPassed(next);
                    }
                }

                grid[p.bx][p.by] = '.';
            }

            ++step;
        } while (q.empty() == false);

        return -1;
    }

private:
    bool canSAccess(vector<vector<char>> grid, int n, int m, int sx, int sy, int tx, int ty)
    {
        queue<pair<int, int>> q({ { sx, sy } });
        do
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x == tx && y == ty)
            {
                return true;
            }

            grid[x][y] = '1';

            if (x > 0 && canMove(grid[x - 1][y]))
            {
                q.push({ x - 1, y });
            }

            if (x < n - 1 && canMove(grid[x + 1][y]))
            {
                q.push({ x + 1, y });
            }

            if (y > 0 && canMove(grid[x][y - 1]))
            {
                q.push({ x, y - 1 });
            }

            if (y < m - 1 && canMove(grid[x][y + 1]))
            {
                q.push({ x, y + 1 });
            }
        } while (q.empty() == false);
        return false;
    }

    bool canMove(char c)
    {
        switch (c)
        {
        case '.':
        case 'T':
            return true;

        default:
            return false;
        }
    }

    void markPassed(const Point& p)
    {
        m_passed.insert(passedKey(p));
    }

    bool isPassed(const Point& p)
    {
        return m_passed.find(passedKey(p)) != m_passed.end();
    }

    int passedKey(const Point& p)
    {
        int key = p.bx;
        key <<= 8; 
        key += p.by;
        key <<= 8;
        key += p.sx;
        key <<= 8;
        key += p.sy;
        return key;
    }

    set<int> m_passed;
};