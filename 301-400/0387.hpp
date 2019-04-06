#include "leetcode.h"

class Solution 
{
public:
    int firstUniqChar(string s) 
    {
        int length = s.length();
        int id[26] = { 0 };//保存的索引号会+1
        int n;
        for (int i = 0; i < length; ++i)
        {
            n = s[i] - 'a';
            if (id[n] == -1)
            {
                continue;
            }
            else if (id[n] == 0)
            {
                id[n] = i + 1;
            }
            else
            {
                id[n] = -1;
            }
        }

        int res = INT_MAX;
        for (auto i : id)
        {
            if (i > 0)
            {
                res = min(res, i);
            }
        }

        if (res == INT_MAX)
        {
            return -1;
        }
        else
        {
            return res - 1;
        }
    }

    //int firstUniqChar(string s)
    //{
    //    int length = s.length();
    //    map<char, int> ci;
    //    for (int i = 0; i < length; ++i)
    //    {
    //        if (ci.find(s[i]) == ci.cend())
    //        {
    //            ci[s[i]] = i;
    //        }
    //        else
    //        {
    //            s[ci[s[i]]] = '0';
    //            s[i] = '0';
    //        }
    //    }

    //    for (int i = 0; i < length; ++i)
    //    {
    //        if (s[i] != '0')
    //        {
    //            return i;
    //        }
    //    }

    //    return -1;
    //}
};