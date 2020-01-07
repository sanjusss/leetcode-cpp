#pragma once
#include "leetcode.h"

/*
假设我们在一条水平数轴上，列表 stations 来表示各个加油站的位置，加油站分别在 stations[0], stations[1], ..., stations[N-1] 的位置上，其中 N = stations.length。
现在我们希望增加 K 个新的加油站，使得相邻两个加油站的距离 D 尽可能的最小，请你返回 D 可能的最小值。

示例：
输入：stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
输出：0.500000

注：
stations.length 是在范围 [10, 2000] 内的整数
stations[i] 是在范围 [0, 10^8] 内的整数
K 是在范围 [1, 10^6] 内的整数
在 10^-6 以内的正确值会被视为正确的答案

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimize-max-distance-to-gas-station
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution 
{
public:
    double minmaxGasDist(vector<int>& stations, int K) 
    {
        vector<double> dists(stations.size() - 1);
        for (int i = 1; i < stations.size(); ++i)
        {
            dists[i - 1] = stations[i] - stations[i - 1];
        }

        double right = 1e8;
        double left = 0;
        double mid;
        while (fabs(right - left) > 1e-7)
        {
            mid = (left + right) / 2;
            if (isMinmaxGasDist(dists, K, mid))
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }

        return left;
    }

private:
    bool isMinmaxGasDist(vector<double>& dists, int K, double d)
    {
        int count = 0;
        for (double dist : dists)
        {
            count += (int)((dist - 1e-7) / d);
        }

        return count <= K;
    }
};