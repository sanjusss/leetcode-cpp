/*
 * @Author: sanjusss
 * @Date: 2023-06-11 16:35:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-11 16:43:26
 * @FilePath: \解题模板\前缀和的树状数组.h
 */
#include "leetcode.h"

// 计算[0, n) 共n个元素的区间和
class TreeArray {
public:
    TreeArray(int n, int val = 0) : m_n(n + 1), m_arr(n + 1, val) {

    };

    // 更新第i个元素
    void update(int i, int val) {
        i += 1;
        while (i < m_n) {
            m_arr[i] += val;
            i += lowbit(i);
        }
    }

    // 查询[0, i]的和
    int query(int i) {
        int sum = 0;
        i += 1;
        while (i > 0) {
            sum += m_arr[i];
            i -= lowbit(i);
        }

        return sum;
    }

    // 查询区域[left, right]的和
    int range(int left, int right) {
        return query(right) - query(left - 1);
    }

private:
    int lowbit(int x) {
        return x & -x;
    }

private:
    const int m_n;
    vector<int> m_arr;
};