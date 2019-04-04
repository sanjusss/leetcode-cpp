#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

namespace _0350
{
    class Solution 
    {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
        {
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            list<int> res;
            int i = 0;
            int j = 0;
            while (i < nums1.size() && j < nums2.size())
            {
                if (nums1[i] == nums2[j])
                {
                    res.push_back(nums1[i]);
                    ++i;
                    ++j;
                }
                else if (nums1[i] > nums2[j])
                {
                    ++j;
                }
                else
                {
                    ++i;
                }
            }

            return vector<int>(res.begin(), res.end());
        }

        //vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
        //{
        //    multiset<int> set1(nums1.begin(), nums1.end());
        //    multiset<int> set2(nums2.begin(), nums2.end());
        //    vector<int> res;
        //    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), insert_iterator<vector<int>>(res, res.begin()));
        //    return res;
        //}
    };
}