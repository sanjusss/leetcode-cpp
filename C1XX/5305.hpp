#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) 
    {
        int n = watchedVideos.size();
        vector<bool> passed(n, false);
        passed[id] = true;
        unordered_map<string, int> fv;
        unordered_set<int> q(friends[id].begin(), friends[id].end());
        for (int i = 1; i <= level && q.empty() == false; ++i)
        {
            unordered_set<int> next;
            for (auto j : q)
            {
                if (passed[j])
                {
                    continue;
                }
                else
                {
                    passed[j] = true;
                }

                for (auto k : friends[j])
                {
                    next.insert(k);
                }

                if (i == level)
                {
                    for (auto& k : watchedVideos[j])
                    {
                        ++fv[k];
                    }
                }
            }

            q.swap(next);
        }

        map<int, set<string>> vs;
        for (auto i = fv.begin(); i != fv.end(); ++i)
        {
            vs[i->second].insert(i->first);
        }

        vector<string> res;
        for (auto i = vs.begin(); i != vs.end(); ++i)
        {
            for (auto& j : i->second)
            {
                res.push_back(j);
            }
        }

        return res;
    }
};