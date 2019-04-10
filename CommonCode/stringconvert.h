#pragma once

#include <sstream>
#include <iostream>

#include "leetcode.h"

class StringConvertor
{
public:
    static vector<int> toIntArray(string s)
    {
        if (s[0] == '[')
        {
            s.erase(0, 1);
        }

        if (s[s.length() - 1] == ']')
        {
            s.erase(s.length() - 1, 1);
        }

        vector<string> strs = split(s, ",");
        vector<int> res;
        for (auto i : strs)
        {
            res.push_back(stoi(i));
        }

        return res;
    }

    static vector<vector<int>> toInt2DArray(string s)
    {
        if (s.substr(0, 2) == "[[")
        {
            s.erase(0, 2);
        }

        if (s.substr(s.length() - 2, 2) == "]]")
        {
            s.erase(s.length() - 2, 2);
        }

        vector<string> strs = split(s, "],[");
        vector<vector<int>> res;
        for (auto i : strs)
        {
            res.push_back(toIntArray(i));
        }

        return res;
    }

    static vector<string> toStringArray(string s)
    {
        s.erase(remove(s.begin(), s.end(), '['), s.end());
        s.erase(remove(s.begin(), s.end(), ']'), s.end());
        s.erase(remove(s.begin(), s.end(), '"'), s.end());
        return split(s, ",");
    }

    static vector<vector<string>> toString2DArray(string s)
    {
        if (s.substr(0, 2) == "[[")
        {
            s.erase(0, 2);
        }

        if (s.substr(s.length() - 2, 2) == "]]")
        {
            s.erase(s.length() - 2, 2);
        }

        vector<string> strs = split(s, "],[");
        vector<vector<string>> res;
        for (auto i : strs)
        {
            res.push_back(toStringArray(i));
        }

        return res;
    }

    static vector<char> toCharArray(string s)
    {
        auto strs = toStringArray(s);
        vector<char> res;
        for (auto i : strs)
        {
            res.push_back(i[0]);
        }

        return res;
    }

    static vector<vector<char>> toChar2DArray(string s)
    {
        if (s.substr(0, 2) == "[[")
        {
            s.erase(0, 2);
        }

        if (s.substr(s.length() - 2, 2) == "]]")
        {
            s.erase(s.length() - 2, 2);
        }

        vector<string> strs = split(s, "],[");
        vector<vector<char>> res;
        for (auto i : strs)
        {
            res.push_back(toCharArray(i));
        }

        return res;
    }

    static vector<string> split(const string& s, const string& seperator)
    {
        vector<string> output;

        string::size_type prev_pos = 0, pos = 0;

        while ((pos = s.find(seperator, pos)) != string::npos)
        {
            string substring(s.substr(prev_pos, pos - prev_pos));

            output.push_back(substring);

            pos += seperator.length();
            prev_pos = pos;
        }

        output.push_back(s.substr(prev_pos, pos - prev_pos)); // Last word

        return output;
    }
};