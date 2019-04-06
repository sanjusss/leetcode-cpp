#include "leetcode.h"

class Solution 
{
public:
    bool isAnagram(string s, string t)
    {
        int sc[26] = { 0 };
        int tc[26] = { 0 };

        for (auto i : s)
        {
            ++sc[i - 'a'];
        }

        for (auto i : t)
        {
            ++tc[i - 'a'];
        }

        for (int i = 0; i < 26; ++i)
        {
            if (sc[i] != tc[i])
            {
                return false;
            }
        }

        return true;
    }

    //bool isAnagram(string s, string t)
    //{
    //    sort(s.begin(), s.end());
    //    sort(t.begin(), t.end());
    //    return s == t;
    //}
};