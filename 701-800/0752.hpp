#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int openLock(vector<string>& deadends, string target) 
    {
        set<string> deadset(deadends.cbegin(), deadends.cend());
        queue<string> q({ "0000" });
        int n = 0;
        do
        {
            int length = q.size();
            for (int i = 0; i < length; ++i)
            {
                string current = q.front();
                q.pop();
                if (deadset.find(current) != deadset.cend())
                {
                    continue;
                }

                if (current == target)
                {
                    return n;
                }

                deadset.insert(current);
                for (int j = 0; j < 4; ++j)
                {
                    string add = current;
                    string sub = current;
                    if (current[j] == '0')
                    {
                        ++add[j];
                        sub[j] = '9';
                    }
                    else if (current[j] == '9')
                    {
                        add[j] = '0';
                        --sub[j];
                    }
                    else
                    {
                        ++add[j];
                        --sub[j];
                    }

                    q.push(add);
                    q.push(sub);
                }
            }

            ++n;
        } while (q.empty() == false);
        return -1;
    }
};