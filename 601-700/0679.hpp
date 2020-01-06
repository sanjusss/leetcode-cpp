#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool judgePoint24(vector<int>& nums) 
    {
        vector<double> values;
        for (auto i : nums)
        {
            values.push_back(i);
        }

        return judgePoint24(values);
    }

private:
    bool judgePoint24(const vector<double>& nums)
    {
        int size = nums.size();
        if (size == 0)
        {
            return false;
        }
        else if (size == 1)
        {
            return fabs(nums[0] - 24) < 1e-5;
        }
        else
        {
            for (int i = 0; i < size; ++i)
            {
                for (int j = 0; j < size; ++j)
                {
                    if (i == j)
                    {
                        continue;
                    }

                    vector<double> nexts;
                    for (int k = 0; k < size; ++k)
                    {
                        if (k != i && k != j)
                        {
                            nexts.push_back(nums[k]);
                        }
                    }

                    nexts.push_back(0);
                    for (int k = 0; k < 4; ++k)
                    {
                        if (i > j && k < 2)
                        {
                            continue;
                        }

                        nexts[size - 2] = operate(nums[i], nums[j], k);
                        if (judgePoint24(nexts))
                        {
                            return true;
                        }
                    }
                }
            }

            return false;
        }
    }

    double operate(double a, double b, int op)
    {
        switch (op)
        {
        case 0:
            return a + b;

        case 1:
            return a * b;

        case 2:
            return a - b;

        default:
            return a / b;
        }
    }
};