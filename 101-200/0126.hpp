#pragma once
#include "leetcode.h"

namespace _0126
{

    class Solution
    {
    public:
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
        {
            unordered_map<string, int> words;
            for (int i = 0; i < wordList.size(); ++i)
            {
                words[wordList[i]] = i;
            }

            if (words.find(endWord) == words.end())
            {
                return vector<vector<string>>();
            }

            if (words.find(beginWord) == words.end())
            {
                words[beginWord] = wordList.size();
                wordList.push_back(beginWord);
            }

            int beginIndex = words[beginWord];
            int endIndex = words[endWord];
            int size = beginWord.size();

            vector<bool> used(wordList.size());
            unordered_map<int, vector<vector<int>>> frontList;
            frontList[beginIndex] = { { beginIndex } };
            unordered_map<int, vector<vector<int>>> backList;
            backList[endIndex] = { { endIndex } };
            vector<vector<int>> ansIndex;
            bool frontIsBegin = true;
            while (ansIndex.empty() && frontList.empty() == false)
            {
                for (auto& i : frontList)
                {
                    used[i.first] = true;
                }

                unordered_map<int, vector<vector<int>>> next;
                for (auto& i : frontList)
                {
                    for (int j = 0; j < size; ++j)
                    {
                        string ts = wordList[i.first];
                        for (char k = 'a'; k <= 'z'; ++k)
                        {
                            ts[j] = k;
                            if (words.find(ts) == words.end() ||
                                used[words[ts]])
                            {
                                continue;
                            }

                            int cur = words[ts];
                            if (backList.find(cur) == backList.end())
                            {
                                for (vector<int> l : i.second)
                                {
                                    l.push_back(cur);
                                    next[cur].push_back(move(l));
                                }
                            }
                            else
                            {
                                if (frontIsBegin)
                                {
                                    for (auto& l : i.second)
                                    {
                                        for (auto& m : backList[cur])
                                        {
                                            auto route = l;
                                            for (auto n = m.rbegin(); n != m.rend(); ++n)
                                            {
                                                route.push_back(*n);
                                            }

                                            ansIndex.push_back(move(route));
                                        }
                                    }
                                }
                                else
                                {
                                    for (auto& l : backList[cur])
                                    {
                                        for (auto& m : i.second)
                                        {
                                            auto route = l;
                                            for (auto n = m.rbegin(); n != m.rend(); ++n)
                                            {
                                                route.push_back(*n);
                                            }

                                            ansIndex.push_back(move(route));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                if (next.size() >= backList.size())
                {
                    frontIsBegin = !frontIsBegin;
                    frontList = move(backList);
                    backList = move(next);
                }
                else
                {
                    frontList = move(next);
                }
            }

            vector<vector<string>> ans;
            for (auto& i : ansIndex)
            {
                vector<string> route;
                for (auto& j : i)
                {
                    route.push_back(wordList[j]);
                }

                ans.push_back(move(route));
            }

            return ans;
        }
    };

}