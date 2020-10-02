#pragma once
#include "leetcode.h"

class Logger 
{
public:
    /** Initialize your data structure here. */
    Logger() 
    {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) 
    {
        if (m_msg.find(message) == m_msg.end() || m_msg[message] + 10 <= timestamp)
        {
            m_msg[message] = timestamp;
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    map<string, int> m_msg;
};