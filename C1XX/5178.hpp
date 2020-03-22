#pragma once
#include "leetcode.h"

vector<int> primes;
void init()
{
    static bool hasInit = false;
    if (hasInit)
    {
        return;
    }

    hasInit = true;
    array<bool, 100001> n;
    n.fill(true);
    n[0] = false;
    n[1] = false;
    for (int i = 2; i <= 100000; ++i)
    {
        if (n[i] == false)
        {
            continue;
        }

        primes.push_back(i);
        for (int j = i + i; j <= 100000; j += i)
        {
            n[j] = false;
        }
    }
}

class Solution
{
public:
    int sumFourDivisors(vector<int>& nums)
    {
        init();
        int ans = 0;
        for (auto i : nums)
        {
            int count = 0;
            int a = 0;
            int b = 0;
            for (auto j : primes)
            {
                if (j >= i)
                {
                    break;
                }

                if (i % j == 0)
                {
                    ++count;
                    if (count == 1)
                    {
                        a = j;
                    }
                    else if (count == 2)
                    {
                        b = j;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            if (count == 2)
            {
                if (i == a * b)
                {
                    ans += 1 + a + b + i;
                }
            }
            else if (count == 1)
            {
                if (i == a * a * a)
                {
                    ans += 1 + a + a * a + i;
                }
            }
        }

        return ans;
    }
};