#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<string> printVertically(string s) 
    {
        auto words = split(s, " ");
        int maxLength = 0;
        for (auto& i : words)
        {
            maxLength = max(maxLength, (int)i.size());
        }

        vector<string> ans(maxLength);
        for (int i = 0; i < maxLength; ++i)
        {
            for (auto& word : words)
            {
                if (word.size() <= i)
                {
                    ans[i].push_back(' ');
                }
                else
                {
                    ans[i].push_back(word[i]);
                }
            }

            ans[i] = ans[i].substr(0, ans[i].find_last_not_of(' ') + 1);
        }

        return ans;
    }

private:
    inline std::vector<std::string> split(const std::string& s, const std::string& seperator)
    {
        std::vector<std::string> output;

        std::string::size_type prev_pos = 0, pos = 0;

        while ((pos = s.find(seperator, pos)) != std::string::npos)
        {
            std::string subString(s.substr(prev_pos, pos - prev_pos));

            output.push_back(subString);

            pos += seperator.length();
            prev_pos = pos;
        }

        output.push_back(s.substr(prev_pos, pos - prev_pos)); // Last word

        return output;
    }
};