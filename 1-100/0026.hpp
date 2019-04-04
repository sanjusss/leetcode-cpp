#include <vector>

using namespace std;
namespace _0026
{
    class Solution
    {
    public:
        int removeDuplicates(vector<int>& nums)
        {
            int index = 0;
            int last = INT_MIN;
            for (int i : nums)
            {
                if (i != last)
                {
                    last = i;
                    nums[index] = i;
                    ++index;
                }
            }

            return index;
        }
    };
}