#pragma once
#include "leetcode.h"

//class CQueue 
//{
//public:
//    CQueue() 
//    {
//
//    }
//
//    void appendTail(int value) 
//    {
//        while (m_q.empty() == false)
//        {
//            m_temp.push(m_q.top());
//            m_q.pop();
//        }
//
//        m_q.push(value);
//        while (m_temp.empty() == false)
//        {
//            m_q.push(m_temp.top());
//            m_temp.pop();
//        }
//    }
//
//    int deleteHead() 
//    {
//        if (m_q.empty())
//        {
//            return -1;
//        }
//
//        int res = m_q.top();
//        m_q.pop();
//        return res;
//    }
//
//private:
//    stack<int> m_q;
//    stack<int> m_temp;
//};

class CQueue
{
public:
    CQueue()
    {

    }

    void appendTail(int value)
    {
        m_q_in.push(value);
    }

    int deleteHead()
    {
        if (m_q_out.empty())
        {
            while (m_q_in.empty() == false)
            {
                m_q_out.push(m_q_in.top());
                m_q_in.pop();
            }
        }

        if (m_q_out.empty())
        {
            return -1;
        }

        int res = m_q_out.top();
        m_q_out.pop();
        return res;
    }

private:
    stack<int> m_q_in;
    stack<int> m_q_out;
};