#include "leetcode.h"

//class Solution
//{
//public:
//    int maxProfit(vector<int>& prices)
//    {
//        int bought = INT_MIN;
//        int count = prices.size();
//        int maxIndex = count - 1;
//        int profit = 0;
//        for (int i = 0; i < count; ++i)
//        {
//            if (bought == INT_MIN)
//            {
//                if (i < maxIndex && prices[i] < prices[i + 1])
//                {
//                    bought = prices[i];
//                }
//            }
//            else
//            {
//                if (prices[i] > bought &&
//                    (i == maxIndex || prices[i] > prices[i + 1]))
//                {
//                    profit += prices[i] - bought;
//                    bought = INT_MIN;
//                }
//            }
//        }
//
//        return profit;
//    }
//};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }

        int hold = -prices[0];
        int none = 0;
        int doHold;
        int doSell;
        for (int i = 1; i < prices.size(); ++i) {
            doHold = max(hold, none - prices[i]);
            doSell = max(hold + prices[i], none);
            hold = doHold;
            none = doSell;
        }

        return max(hold, none);
    }
};