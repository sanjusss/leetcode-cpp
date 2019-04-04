#include <vector>

using namespace std;

namespace _0136
{
    class Solution 
    {
    public:
        int singleNumber(vector<int> &nums) 
        {
            int n = 0;
            for (int i : nums)
            {
                n ^= i;
            }

            return n;
        }
    };
}