#pragma once
#include "leetcode.h"

class ArrayReader
{
public:
    ArrayReader(const vector<int>& arr) : m_a(arr)
    {

    }

    int get(int k) const
    {
        if (k >= m_a.size() || k < 0)
        {
            return 2147483647;
        }
        else
        {
            return m_a[k];
        }
    }

private:
    vector<int> m_a;
};

//下面是需要提交的部分

class ArrayReader;

class Solution 
{
public:
    int search(const ArrayReader& reader, int target) 
    {
        int left = 0;
        int right = 10000;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int value = reader.get(mid);
            if (target == value)
            {
                return mid;
            }
            else if (value > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return -1;
    }
};