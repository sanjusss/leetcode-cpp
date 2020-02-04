#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
//    {
//        int size = beginWord.size();
//        int endIndex = distance(wordList.begin(), find(wordList.begin(), wordList.end(), endWord));
//        if (endIndex == wordList.size())
//        {
//            return 0;
//        }
//
//        int startIndex = distance(wordList.begin(), find(wordList.begin(), wordList.end(), beginWord));
//        if (startIndex == wordList.size())
//        {
//            wordList.push_back(beginWord);
//        }
//
//        vector<vector<bool>> m(wordList.size(), vector<bool>(wordList.size()));
//        for (int i = 0; i < wordList.size(); ++i)
//        {
//            for (int j = i + 1; j < wordList.size(); ++j)
//            {
//                int diff = 0;
//                for (int k = 0; k < size; ++k)
//                {
//                    if (wordList[i][k] != wordList[j][k])
//                    {
//                        ++diff;
//                    }
//                }
//
//                if (diff == 1)
//                {
//                    m[i][j] = true;
//                    m[j][i] = true;
//                }
//            }
//        }
//
//        unordered_set<int> q({ startIndex });
//        unordered_set<int> passed;
//        int ans = 0;
//        while (q.empty() == false)
//        {
//            ++ans;
//            unordered_set<int> next;
//            for (int i : q)
//            {
//                if (i == endIndex)
//                {
//                    return ans;
//                }
//
//                if (passed.find(i) != passed.end())
//                {
//                    continue;
//                }
//
//                passed.insert(i);
//                for (int j = 0; j < wordList.size(); ++j)
//                {
//                    if (m[i][j])
//                    {
//                        next.insert(j);
//                    }
//                }
//            }
//
//            q.swap(next);
//        }
//
//        return 0;
//    }
//};

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        int size = beginWord.size();
        int ans = 1;
        unordered_set<string> reachable(wordList.begin(), wordList.end());
        if (reachable.find(endWord) == reachable.end())
        {
            return 0;
        }

        unordered_set<string> frontList({ beginWord });
        unordered_set<string> backList({ endWord });
        while (frontList.empty() == false)
        {
            ++ans;
            for (auto& s : frontList)
            {
                reachable.erase(s);
            }

            unordered_set<string> next;
            for (auto& s : frontList)
            {
                for (int i = 0; i < size; ++i)
                {
                    string ts = s;
                    for (char j = 'a'; j <= 'z'; ++j)
                    {
                        ts[i] = j;
                        if (reachable.find(ts) != reachable.end())
                        {
                            if (backList.find(ts) == backList.end())
                            {
                                next.insert(ts);
                            }
                            else
                            {
                                return ans;
                            }
                        }
                    }
                }
            }

            if (next.size() >= backList.size())
            {
                frontList = move(backList);
                backList = move(next);
            }
            else
            {
                frontList = move(next);
            }
        }

        return 0;
    }
};