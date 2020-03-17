#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int majorityElement(vector<int>& nums) 
//    {
//        unordered_map<int, int> cs;
//        for (auto i : nums)
//        {
//            ++cs[i];
//        }
//
//        pair<int, int> ans = *cs.begin();
//        for (auto i = next(cs.begin()); i != cs.end(); ++i)
//        {
//            if (i->second > ans.second)
//            {
//                ans = *i;
//            }
//        }
//
//        return ans.first;
//    }
//};

//Boyer - Moore ͶƱ�㷨
/*
�����ϣ� Boyer-Moore �㷨������ nums ��һ����׺ sufsuf ������ suf[0]suf[0] ���Ǻ�׺�е�������
����ά��һ�����������������һ������Ŀǰ�ĺ�ѡ�������ͽ���������һ�������һ��
ֻҪ���������� 0 �����Ǿͽ� nums ��֮ǰ���ʵ�����ȫ�� ���� ��������һ�����ֵ�����ѡ��������

���ߣ�LeetCode
���ӣ�https://leetcode-cn.com/problems/majority-element/solution/qiu-zhong-shu-by-leetcode-2/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int ans = 0;
        int records = 0;
        for (auto i : nums)
        {
            if (records == 0)
            {
                ans = i;
                ++records;
            }
            else if (i == ans)
            {
                ++records;
            }
            else
            {
                --records;
            }
        }

        return ans;
    }
};