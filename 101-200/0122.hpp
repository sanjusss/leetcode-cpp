#include <vector>

using namespace std;
namespace _0122
{
    class Solution
    {
    public:
        int maxProfit(vector<int>& prices)
        {
            int bought = INT_MIN;
            int count = prices.size();
            int maxIndex = count - 1;
            int profit = 0;
            for (int i = 0; i < count; ++i)
            {
                if (bought == INT_MIN)
                {
                    if (i < maxIndex && prices[i] < prices[i + 1])
                    {
                        bought = prices[i];
                    }
                }
                else
                {
                    if (prices[i] > bought &&
                        (i == maxIndex || prices[i] > prices[i + 1]))
                    {
                        profit += prices[i] - bought;
                        bought = INT_MIN;
                    }
                }
            }

            return profit;
        }
    };

    void Test()
    {

    }
}