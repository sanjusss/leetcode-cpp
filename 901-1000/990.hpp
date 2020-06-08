#pragma once
#include "leetcode.h"

//图的遍历
//class Solution 
//{
//public:
//    bool equationsPossible(vector<string>& equations) 
//    {
//        vector<vector<int>> conn(26, vector<int>(26));
//        for (string& e : equations)
//        {
//            int v = e[1] == '!' ? -1 : 1;
//            if (conn[e[0] - 'a'][e[3] - 'a'] != 0 && conn[e[0] - 'a'][e[3] - 'a'] != v)
//            {
//                return false;
//            }
//
//            conn[e[0] - 'a'][e[3] - 'a'] = e[1] == '!' ? -1 : 1;
//            conn[e[3] - 'a'][e[0] - 'a'] = e[1] == '!' ? -1 : 1;
//        }
//
//        vector<bool> value(26);
//        for (int i = 0; i < 26; ++i)
//        {
//            if (conn[i][i] == -1)
//            {
//                return false;
//            }
//
//            if (value[i])
//            {
//                continue;
//            }
//
//            vector<int> q;
//            q.push_back(i);
//            vector<bool> equal(26);
//            equal[i] = true;
//            vector<bool> notEqual(26);
//            do
//            {
//                vector<int> nexts;
//                for (int j : q)
//                {
//                    for (int k = 0; k < 26; ++k)
//                    {
//                        if (j == k)
//                        {
//                            continue;
//                        }
//
//                        if (conn[j][k] == 1)
//                        {
//                            if (notEqual[k])
//                            {
//                                return false;
//                            }
//
//                            if (equal[k] == false)
//                            {
//                                equal[k] = true;
//                                nexts.push_back(k);
//                            }
//                        }
//                        else if (conn[j][k] == -1)
//                        {
//                            if (equal[k])
//                            {
//                                return false;
//                            }
//
//                            notEqual[k] = true;
//                        }
//                    }
//                }
//
//                q = move(nexts);
//            } while (q.empty() == false);
//            for (int j = i; j < 26; ++j)
//            {
//                if (equal[j])
//                {
//                    value[i] = true;
//                }
//            }
//        }
//
//        return true;
//    }
//};

//并查集
class Solution 
{
public:
    bool equationsPossible(vector<string>& equations) 
    {
        vector<int> value(26);
        int cur = 1;
        int a;
        int b;
        for (string& e : equations)
        {
            if (e[1] != '=')
            {
                continue;
            }

            a = e[0] - 'a';
            b = e[3] - 'a';
            if (value[a] > 0 && value[b] > 0)
            {
                if (value[a] == value[b])
                {
                    continue;
                }

                int src = value[b];
                int des = value[a];
                for (int i = 0; i < 26; ++i)
                {
                    if (value[i] == src)
                    {
                        value[i] = des;
                    }
                }
            }
            else if (value[a] > 0)
            {
                value[b] = value[a];
            }
            else if (value[b] > 0)
            {
                value[a] = value[b];
            }
            else
            {
                value[a] = cur;
                value[b] = cur;
                ++cur;
            }
        }

        for (string& e : equations)
        {
            if (e[1] != '!')
            {
                continue;
            }

            a = e[0] - 'a';
            b = e[3] - 'a';
            if (a == b || (value[a] == value[b] && value[a] > 0 && value[b] > 0))
            {
                return false;
            }
        }

        return true;
    }
};