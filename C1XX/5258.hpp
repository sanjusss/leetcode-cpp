#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
    {
        vector<int> letterCount(26, 0);
        for (auto i : letters)
        {
            ++letterCount[i - 'a'];
        }

        vector<string> validWords;
        for (auto i : words)
        {
            auto temp = letterCount;
            if (wordScore(i, temp, score) > 0)
            {
                validWords.push_back(i);
            }
        }

        return maxScoreWords(validWords, letterCount, score, 0);
    }

    int maxScoreWords(const vector<string>& words, vector<int>& letterCount, const vector<int>& score, int index)
    {
        if (index == words.size())
        {
            return 0;
        }

        auto after = letterCount;
        int is = wordScore(words[index], after, score);
        int next = maxScoreWords(words, letterCount, score, index + 1);
        if (is == 0)
        {
            return next;
        }
        else
        {
            return max(is + maxScoreWords(words, after, score, index + 1), next);
        }
    }

    int wordScore(string word, vector<int>& letterCount, const vector<int>& score)
    {
        int count = 0;
        for (auto i : word)
        {
            if (letterCount[i - 'a'] > 0)
            {
                --letterCount[i - 'a'];
                count += score[i - 'a'];
            }
            else
            {
                return 0;
            }
        }

        return count;
    }
};