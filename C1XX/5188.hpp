#pragma once
#include "leetcode.h"

//class TreeAncestor 
//{
//public:
//    TreeAncestor(int n, vector<int>& parent) :
//        m_des(n)
//    {
//        m_des[0] = { 0, 1 };
//        m_ancestors.push_back({ 0 });
//        stack<int> s;
//        for (int i = 1; i < n; ++i)
//        {
//            if (m_des[i].second > 0)
//            {
//                continue;
//            }
//
//            s.push(i);
//            while (s.empty() == false)
//            {
//                int node = s.top();
//                if (m_des[parent[node]].second == 0)
//                {
//                    s.push(parent[node]);
//                }
//                else if (m_des[parent[node]].second < m_ancestors[m_des[parent[node]].first].size())
//                {
//                    s.pop();
//                    vector<int> temp(m_ancestors[m_des[parent[node]].first].begin(), m_ancestors[m_des[parent[node]].first].begin() + m_des[parent[node]].second);
//                    temp.push_back(node);
//                    m_des[node] = { m_ancestors.size(), temp.size() };
//                    m_ancestors.push_back(move(temp));
//                }
//                else
//                {
//                    s.pop();
//                    m_ancestors[m_des[parent[node]].first].push_back(node);
//                    m_des[node] = { m_des[parent[node]].first, m_des[parent[node]].second + 1 };
//                }
//            }
//        }
//    }
//
//    int getKthAncestor(int node, int k) 
//    {
//        if (m_des[node].second <= k || k < 0)
//        {
//            return -1;
//        }
//        else
//        {
//            return m_ancestors[m_des[node].first][m_des[node].second - k - 1];
//        }
//    }
//
//private:
//    vector<pair<int, int>> m_des;
//    vector<vector<int>> m_ancestors;
//};

class TreeAncestor
{
public:
    TreeAncestor(int n, vector<int>& parent) :
        m_ancestors(n)
    {
        for (int i = 0; i < n; ++i)
        {
            m_ancestors[i].push_back(parent[i]);
        }

        bool goNext = true;
        int value;
        for (int j = 0; goNext; ++j)
        {
            goNext = false;
            for (int i = 0; i < n; ++i)
            {
                value = m_ancestors[i].back() == -1 ? -1 : m_ancestors[m_ancestors[i][j]][j];
                m_ancestors[i].push_back(value);
                if (value != -1)
                {
                    goNext = true;
                }
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        int pos = 0;
        while (k > 0 && node != -1)
        {
            if (pos >= m_ancestors[node].size())
            {
                return -1;
            }

            if (k & 1)
            {
                node = m_ancestors[node][pos];
            }

            k >>= 1;
            ++pos;
        }

        return node;
    }

private:
    vector<vector<int>> m_ancestors;
};
