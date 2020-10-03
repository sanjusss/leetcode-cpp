#include "leetcode.h"

// class Solution 
// {
// public:
//     //使用哈希映射
//     //vector<int> twoSum(vector<int>& nums, int target) 
//     //{
//     //    unordered_map<int, int> hash;
//     //    for (int i = 0; i < nums.size(); ++i)
//     //    {
//     //        if (hash.count(target - nums[i]) > 0)
//     //        {
//     //            return { hash[target - nums[i]], i };
//     //        }
//     //        else if (hash.count(nums[i]) == 0)
//     //        {
//     //            hash[nums[i]] = i;
//     //        }
//     //    }

//     //    return { -1, -1 };
//     //}

//     vector<int> twoSum(vector<int>& nums, int target) 
//     {
//         multimap<int, int> vs;
//         int length = nums.size();
//         for (int i = 0; i < length; ++i)
//         {
//             vs.insert(make_pair(nums[i], i));
//         }

//         auto endIter = vs.upper_bound(target / 2);
//         int a;
//         int b;
//         for (auto i = vs.cbegin(); i != endIter; ++i)
//         {
//             a = i->first;
//             b = target - a;
//             if (a == b)
//             {
//                 int index = i->second;
//                 ++i;
//                 if (i != vs.cend())
//                 {
//                     return { index, i->second };
//                 }
//             }
//             else
//             {
//                 auto bIter = vs.find(b);
//                 if (bIter != vs.cend())
//                 {
//                     return { i->second, bIter->second };
//                 }
//             }
//         }

//         return vector<int>();
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> v2i;
        for (int i = 0; i < nums.size(); ++i) {
            auto pos = v2i.find(target - nums[i]);
            if (pos != v2i.end()) {
                return { i, pos->second };
            }
            else {
                v2i[nums[i]] = i;
            }
        }

        return {};
    }
};