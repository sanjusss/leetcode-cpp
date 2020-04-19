#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) 
    {
        set<string> names;
        map<int, vector<string>> tables;
        for (auto& o : orders)
        {
            names.insert(o[2]);
            int no = stoi(o[1]);
            tables[no].push_back(o[2]);
        }

        vector<vector<string>> ans;
        vector<string> headers;
        headers.push_back("Table");
        unordered_map<string, int> cols;
        for (auto& i : names)
        {
            cols[i] = headers.size();
            headers.push_back(i);
        }

        ans.push_back(headers);
        for (auto& t : tables)
        {
            vector<int> cs(headers.size());
            for (auto& name : t.second)
            {
                ++cs[cols[name]];
            }

            vector<string> row(headers.size());
            row[0] = to_string(t.first);

            for (int i = 1; i < row.size(); ++i)
            {
                row[i] = to_string(cs[i]);
            }

            ans.push_back(row);
        }

        return ans;
    }
};