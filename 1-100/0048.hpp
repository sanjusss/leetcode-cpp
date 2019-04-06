#include <vector>

using namespace std;

namespace _0048
{
    class Solution 
    {
    public:
        void rotate(vector<vector<int>>& matrix) 
        {
            int length = matrix.size();
            int maxIndex = length / 2;
            int temp;
            int min;
            int max;
            int lastX;
            int lastY;
            int x;
            int y;
            for (int i = 0; i < maxIndex; ++i)
            {
                min = i;
                max = length - 1 - i;
                for (int j = min; j < max; ++j)
                {
                    lastX = min;
                    lastY = min;
                    temp = matrix[lastX][lastY];
                    x = min + 1;
                    y = min;
                    while (x != min || y != min)
                    {
                        matrix[lastX][lastY] = matrix[x][y];
                        lastX = x;
                        lastY = y;
                        if (y == min)
                        {
                            if (x == max)
                            {
                                ++y;
                            }
                            else
                            {
                                ++x;
                            }
                        }
                        else if (x == max)
                        {
                            if (y == max)
                            {
                                --x;
                            }
                            else
                            {
                                ++y;
                            }
                        }
                        else if (y == max)
                        {
                            if (x == min)
                            {
                                --y;
                            }
                            else
                            {
                                --x;
                            }
                        }
                        else
                        {
                            --y;
                        }
                    }

                    matrix[min][min + 1] = temp;
                }
            }
        }
    };
}