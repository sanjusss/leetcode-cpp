#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        vector<bool> visited(rooms.size(), false);
        stack<int> s;
        s.push(0);
        do
        {
            int cur = s.top();
            s.pop();
            if (visited[cur])
            {
                continue;
            }

            visited[cur] = true;
            for (auto i : rooms[cur])
            {
                s.push(i);
            }
        } while (s.empty() == false);

        return find(visited.cbegin(), visited.cend(), false) == visited.cend();
    }
};