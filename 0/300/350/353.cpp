/*
 * @Author: sanjusss
 * @Date: 2022-07-13 08:21:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-13 08:41:44
 * @FilePath: \0\300\350\353.cpp
 */
#include "leetcode.h"

class SnakeGame {
public:
    SnakeGame(int width, int height, vector<vector<int>>& food)
        : m_width(width), m_height(height), m_food(std::move(food)) {
        m_body.push(0);
        m_pos.insert(0);
    }

    int move(string direction) {
        int di = 0;
        int dj = 0;
        switch (direction[0]) {
            case 'L':
                dj = -1;
                break;
            case 'R':
                dj = 1;
                break;
            case 'U':
                di = -1;
                break;
            case 'D':
                di = 1;
                break;

            default:
                return -1;
        }

        m_i += di;
        m_j += dj;
        if (m_i < 0 || m_i >= m_height || m_j < 0 || m_j >= m_width) {
            return -1;
        }

        if (m_curFood < m_food.size() && m_food[m_curFood][0] == m_i && m_food[m_curFood][1] == m_j) {
            ++m_curFood;
        }
        else {
            m_pos.erase(m_body.front());
            m_body.pop();
        }
        
        int64_t p = (((int64_t)m_i) << 32) | ((int64_t)m_j);
        if (m_pos.count(p)) {
            return -1;
        }

        m_pos.insert(p);
        m_body.push(p);

        return m_body.size() - 1;
    }

private:
    int m_width;
    int m_height;
    vector<vector<int>> m_food;
    int m_curFood = 0;
    int m_i = 0;
    int m_j = 0;
    queue<int64_t> m_body;
    unordered_set<int64_t> m_pos;
};