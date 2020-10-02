#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        unordered_map<char, vector<char>>& dic = createDic();
        vector<string> ans;
        for (auto i : digits)
        {
            vector<string> temp;
            for (auto j : dic[i])
            {
                if (ans.empty())
                {
                    temp.push_back(string(1, j));
                }
                else
                {
                    for (auto& k : ans)
                    {
                        temp.push_back(k + j);
                    }
                }
            }

            temp.swap(ans);
        }

        return ans;
    }

private:
    static unordered_map<char, vector<char>>& createDic()
    {
        static unordered_map<char, vector<char>> dic;
        if (dic.empty())
        {
            char c = 'a';
            for (int i = 2; i <= 9; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    dic[i + '0'].push_back(c++);
                }

                if (i == 7 || i == 9)
                {
                    dic[i + '0'].push_back(c++);
                }
            }
        }

        return dic;
    }
};