#pragma once
#include "leetcode.h"

class ValidWordAbbr 
{
public:
    ValidWordAbbr(vector<string>& dictionary) 
    {
        for (string i : dictionary)
        {
            if (words.find(i) != words.end())
            {
                continue;
            }

            ++shorts[key(i)];
            words.insert(i);
        }
    }

    bool isUnique(string word) 
    {
        auto k = key(word);
        if (shorts.find(k) == shorts.end())
        {
            return true;
        }
        else
        {
            return shorts[k] == 1 && words.find(word) != words.end();
        }
    }

private:
    string key(string value)
    {
        if (value.size() <= 2)
        {
            return value;
        }

        string res;
        res += value.front();
        res += to_string(value.size() - 2);
        res += value.back();
        return res;
    }

    unordered_map<string, int> shorts;
    unordered_set<string> words;
};