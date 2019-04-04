#include <vector>

using namespace std;

namespace _0189
{
    class Solution 
    {
    public:
        void rotate(vector<int> &nums, int k) 
        {
            int length = nums.size();
            k %= length;
            if (k == 0)
            {
                return;
            }

            reverse(nums, 0, length - k - 1);
            reverse(nums, length - k, length - 1);
            reverse(nums, 0, length - 1);
        }

        void reverse(vector<int> &nums, int start, int end)
        {
            while (start < end)
            {
                std::swap(nums[start++], nums[end--]);
            }
        }
    };
}