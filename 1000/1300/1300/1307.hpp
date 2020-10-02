#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    bool isSolvable(vector<string>& words, string result) 
//    {
//        int coe;
//        for (string& word : words)
//        {
//            if (word.size() > result.size())
//            {
//                return false;
//            }
//
//            coe = 1;
//            for (int i = word.size() - 1; i >= 0; --i)
//            {
//                m_items[word[i]] += coe;
//                coe *= 10;
//            }
//
//            if (word.size() > 1)
//            {
//                m_unzeros[word[0]] = true;
//            }
//        }
//
//        coe = -1;
//        for (int i = result.size() - 1; i >= 0; --i)
//        {
//            m_items[result[i]] += coe;
//            coe *= 10;
//        }
//
//        if (result.size() > 1)
//        {
//            m_unzeros[result[0]] = true;
//        }
//
//        for (char i = 'A'; i <= 'Z'; ++i)
//        {
//            if (m_items[i] != 0)
//            {
//                m_cs[m_nCharCount++] = i;
//            }
//        }
//
//        return dfs(0, 0);
//    }
//
//private:
//    bool dfs(int cur, int sum)
//    {
//        if (cur == m_nCharCount)
//        {
//            return sum == 0;
//        }
//
//        for (int i = m_unzeros[m_cs[cur]] ? 1 : 0;
//            i <= 9;
//            ++i)
//        {
//            if (m_used[i])
//            {
//                continue;
//            }
//
//            m_used[i] = true;
//            if (dfs(cur + 1, sum + i * m_items[m_cs[cur]]))
//            {
//                return true;
//            }
//
//            m_used[i] = false;
//        }
//
//        return false;
//    }
//
//private:
//    int m_items[CHAR_MAX + 1] = { 0 };
//    bool m_unzeros[CHAR_MAX + 1] = { 0 };
//    bool m_used[10] = { 0 };
//    char m_cs[CHAR_MAX + 1] = { 0 };
//    int m_nCharCount = 0;
//};

class Solution
{
    using PCI = pair<char, int>;
public:
    bool isSolvable(vector<string>& words, string result)
    {
        unordered_map<char, int> items;
        int coe;
        for (string& word : words)
        {
            if (word.size() > result.size())
            {
                return false;
            }

            coe = 1;
            for (int i = word.size() - 1; i >= 0; --i)
            {
                items[word[i]] += coe;
                coe *= 10;
            }

            if (word.size() > 1)
            {
                m_leads[word[0]] = 1;
            }
        }

        coe = -1;
        for (int i = result.size() - 1; i >= 0; --i)
        {
            items[result[i]] += coe;
            coe *= 10;
        }

        if (result.size() > 1)
        {
            m_leads[result[0]] = 1;
        }

        m_items = vector<PCI>(items.begin(), items.end());
        sort(m_items.begin(), m_items.end(), [](const PCI& a, const PCI& b) { return abs(a.second) > abs(b.second); });
        m_nCharCount = m_items.size();
        m_mins.resize(m_nCharCount);
        m_maxs.resize(m_nCharCount);
        
        for (int i = 0; i < m_nCharCount; ++i)
        {
            vector<int> pos;
            vector<int> neg;
            for (int j = i; j < m_nCharCount; ++j)
            {
                if (m_items[j].second < 0)
                {
                    neg.push_back(m_items[j].second);
                }
                else if (m_items[j].second > 0)
                {
                    pos.push_back(m_items[j].second);
                }
            }

            for (int j = 0; j < pos.size(); ++j)
            {
                m_mins[i] += pos[j] * j;
                m_maxs[i] += pos[j] * (9 - j);
            }

            for (int j = 0; j < neg.size(); ++j)
            {
                m_mins[i] += neg[j] * (9 - j);
                m_maxs[i] += neg[j] * j;
            }
        }

        return dfs(0, 0);
    }

private:
    bool dfs(int cur, int sum)
    {
        if (cur == m_nCharCount)
        {
            return sum == 0;
        }

        if ((sum + m_mins[cur] <= 0 && sum + m_maxs[cur] >= 0) == false)
        {
            return false;
        }

        for (int i = m_leads[m_items[cur].first];
            i <= 9;
            ++i)
        {
            if (m_used[i])
            {
                continue;
            }

            m_used[i] = true;
            if (dfs(cur + 1, sum + i * m_items[cur].second))
            {
                return true;
            }

            m_used[i] = false;
        }
        
        return false;
    }

private:
    vector<PCI> m_items;
    int m_leads[CHAR_MAX + 1] = { 0 };
    bool m_used[10] = { 0 };
    int m_nCharCount = 0;
    vector<int> m_mins;
    vector<int> m_maxs;
};