#include "leetcode.h"

class Solution 
{
public:
    //使用哈希映射
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> res;
        unordered_multiset<int> vs;
        vector<int>& a = nums1.size() > nums2.size() ? nums2 : nums1;
        vector<int>& b = nums1.size() > nums2.size() ? nums1 : nums2;

        for (auto i : a)
        {
            vs.insert(i);
        }

        for (auto i : b)
        {
            auto f = vs.find(i);
            if (f != vs.end())
            {
                res.push_back(i);
                vs.erase(f);
            }
        }

        return res;
    }

    //排序后比较
    //vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    //{
    //    sort(nums1.begin(), nums1.end());
    //    sort(nums2.begin(), nums2.end());
    //    list<int> res;
    //    int i = 0;
    //    int j = 0;
    //    while (i < nums1.size() && j < nums2.size())
    //    {
    //        if (nums1[i] == nums2[j])
    //        {
    //            res.push_back(nums1[i]);
    //            ++i;
    //            ++j;
    //        }
    //        else if (nums1[i] > nums2[j])
    //        {
    //            ++j;
    //        }
    //        else
    //        {
    //            ++i;
    //        }
    //    }

    //    return vector<int>(res.begin(), res.end());
    //}

    //vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    //{
    //    sort(nums1.begin(), nums1.end());
    //    sort(nums2.begin(), nums2.end());
    //    vector<int> res;
    //    set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), insert_iterator<vector<int>>(res, res.begin()));
    //    return res;
    //}
};