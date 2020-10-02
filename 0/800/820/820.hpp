#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int minimumLengthEncoding(vector<string>& words) 
//    {
//        set<string> rstrs;
//        for (string& s : words)
//        {
//            string r = s;
//            reverse(r.begin(), r.end());
//            auto i = rstrs.lower_bound(r);
//
//            if (i != rstrs.end())
//            {
//                if ((*i).rfind(r, 0) == 0)//代替C++20的start_with 
//                {
//                    continue;
//                }
//            }
//
//            if (i != rstrs.begin())
//            {
//                --i;
//                if (r.rfind(*i, 0) == 0)
//                {
//                    rstrs.erase(i);
//                }
//            }
//
//            rstrs.insert(r);
//        }
//
//        int ans = 0;
//        for (auto& i : rstrs)
//        {
//            ans += i.size() + 1;
//        }
//
//        return ans;
//    }
//};

class Solution
{
    struct Node
    {
        Node()
        {
            children.fill(nullptr);
        }

        ~Node()//提交时可以注释，省去30%时间
        {
            for (auto i : children)
            {
                delete i;
            }
        }

        array<Node*, 26> children;
    };

public:
    int minimumLengthEncoding(vector<string>& words)
    {
        Node root;
        for (auto& s : words)
        {
            auto cur = &root;
            for (auto i = s.rbegin(); i != s.rend(); ++i)
            {
                auto j = *i - 'a';
                if (cur->children[j] == nullptr)
                {
                    cur->children[j] = new Node();
                }

                cur = cur->children[j];
            }
        }

        return calc(&root, 1);
    }

private:
    int calc(Node* node, int has)
    {
        int res = 0;
        for (auto i : node->children)
        {
            if (i != nullptr)
            {
                res += calc(i, has + 1);
            }
        }

        return res == 0 ? has : res;
    }
};