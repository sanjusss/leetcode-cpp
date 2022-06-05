/*
 * @Author: sanjusss
 * @Date: 2022-06-05 09:29:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-05 09:45:54
 * @FilePath: \0\400\470\478.cpp
 */
#include "leetcode.h"

class Solution {
public:
    Solution(double radius, double x_center, double y_center)
        : m_r(radius), m_x(x_center), m_y(y_center), m_disR(-radius, radius) {
    }

    vector<double> randPoint() {
        double dx = m_disR(m_rd);
        double dy = m_disR(m_rd);
        while (dx * dx + dy * dy > m_r * m_r) {
            dx = m_disR(m_rd);
            dy = m_disR(m_rd);
        }

        return { { m_x + dx, m_y + dy } };
    }

private:
    double m_r;
    double m_x;
    double m_y;
    random_device m_rd;
    uniform_real_distribution<double> m_disR;
};