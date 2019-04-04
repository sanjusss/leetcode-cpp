#include <set>
#include <vector>
#include <algorithm>

using namespace std;

namespace _0217
{
    class Solution 
    {
    public:
        bool containsDuplicate(vector<int> &nums) 
        {
            std::sort(nums.begin(), nums.end());
            int length = nums.size() - 1;
            for (int i = 0; i < length; ++i)
            {
                if (nums[i] == nums[i + 1])
                {
                    return true;
                }
            }

            return false;
        }


        //bool containsDuplicate(vector<int>& nums)
        //{
        //    set<int> vs;
        //    for (int i : nums)
        //    {
        //        if (vs.find(i) == vs.end())
        //        {
        //            vs.insert(i);
        //        }
        //        else
        //        {
        //            return true;
        //        }
        //    }

        //    return false;
        //}
    };
}