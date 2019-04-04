#include <vector>
#include <list>

using namespace std;

namespace _0066
{
    class Solution 
    {
    public:
        vector<int> plusOne(vector<int>& digits) 
        {
            list<int> res;
            int last = 1;
            int value = 0;
            for (int i = digits.size() - 1; i >= 0; --i)
            {
                value = last + digits[i];
                if (value >= 10)
                {
                    last = value / 10;
                    value %= 10;
                }
                else
                {
                    last = 0;
                }

                res.push_front(value);
            }

            if (last > 0)
            {
                res.push_front(last);
            }

            return vector<int>(res.begin(), res.end());
        }
    };
}