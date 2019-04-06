#include <vector>
#include <set>

using namespace std;
namespace _0036
{
    class Solution 
    {
    public:
        bool isValidSudoku(vector<vector<char>>& board) 
        {
            set<char> vset[9];
            set<char> hset[9];
            set<char> nset[9];
            char judge;
            int row;
            for (int i = 0; i < 9; ++i)
            {
                int row = i / 3;
                for (int j = 0; j < 9; ++j)
                {
                    judge = board[i][j];
                    if (judge == '.')
                    {
                        continue;
                    }

                    if (vset[i].find(judge) == vset[i].cend())
                    {
                        vset[i].insert(judge);
                    }
                    else
                    {
                        return false;
                    }

                    if (hset[j].find(judge) == hset[j].cend())
                    {
                        hset[j].insert(judge);
                    }
                    else
                    {
                        return false;
                    }

                    int col = j / 3;
                    int n = row * 3 + col;
                    if (nset[n].find(judge) == nset[n].cend())
                    {
                        nset[n].insert(judge);
                    }
                    else
                    {
                        return false;
                    }
                }
            }

            return true;
        }
    };
}