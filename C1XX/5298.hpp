#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool isSolvable(vector<string>& words, string result) 
    {
        unordered_set<char> cs;
        unordered_set<char> unzeros;
        initChars(words, cs, unzeros);
        initChars(result, cs, unzeros);
        vector<char> nums(cs.begin(), cs.end());
        for (int i = nums.size(); i < 10; ++i)
        {
            nums.push_back((char)i);
        }

        sort(nums.begin(), nums.end());
        int c2i[256] = { 0 };
        while (next_permutation(nums.begin(), nums.end()))
        {
            if (unzeros.find(nums[0]) != unzeros.end())
            {
                continue;
            }

            for (int i = 0; i < 10; ++i)
            {
                c2i[nums[i]] = i;
            }

            int sum = 0;
            for (auto& s : words)
            {
                sum += string2Int(s, c2i);
            }

            if (sum == string2Int(result, c2i))
            {
                return true;
            }
        }

        return false;
    }

private:
    void initChars(string& s, unordered_set<char>& cs, unordered_set<char>& unzeros)
    {
        for (auto c : s)
        {
            cs.insert(c);
        }

        unzeros.insert(s[0]);
    }

    void initChars(vector<string>& words, unordered_set<char>& cs, unordered_set<char>& unzeros)
    {
        for (auto& s : words)
        {
            initChars(s, cs, unzeros);
        }
    }

    int string2Int(string& s, int* c2i)
    {
        int res = 0;
        for (auto c : s)
        {
            res = 10 * res + c2i[c];
        }

        return res;
    }
};