#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <queue>

#include "..\Json\single_include\nlohmann\json.hpp"

#include "listnode.h"
#include "treenode.h"

namespace Microsoft
{
    namespace VisualStudio
    {
        namespace CppUnitTestFramework
        {
            template<class _T>
            inline std::vector<_T> toArray(std::string s)
            {
                auto j = nlohmann::json::parse(s);
                return j.get<std::vector<_T>>();
            }

            inline std::vector<std::string> split(const std::string& s, const std::string& seperator)
            {
                std::vector<std::string> output;

                std::string::size_type prev_pos = 0, pos = 0;

                while ((pos = s.find(seperator, pos)) != std::string::npos)
                {
                    std::string subString(s.substr(prev_pos, pos - prev_pos));

                    output.push_back(subString);

                    pos += seperator.length();
                    prev_pos = pos;
                }

                output.push_back(s.substr(prev_pos, pos - prev_pos)); // Last word

                return output;
            }
            
            inline std::string replaceAllString(std::string str, const std::string& from, const std::string& to) 
            {
                size_t start_pos = 0;
                while ((start_pos = str.find(from, start_pos)) != std::string::npos) 
                {
                    str.replace(start_pos, from.length(), to);
                    start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
                }

                return str;
            }

            inline std::vector<int> toIntArray(std::string s)
            {
                return toArray<int>(s);
            }

            inline std::vector<std::vector<int>> toInt2DArray(std::string s)
            {
                return toArray<std::vector<int>>(s);
            }

            inline std::vector<std::string> toStringArray(std::string s)
            {
                return toArray<std::string>(s);
            }

            inline std::vector<std::vector<std::string>> toString2DArray(std::string s)
            {
                return toArray<std::vector<std::string>>(s);
            }

            inline std::vector<char> toCharArray(std::string s)
            {
                auto strings = toArray<std::string>(s);
                std::vector<char> res;
                for (auto i : strings)
                {
                    res.push_back(i.front());
                }

                return res;
            }

            inline std::vector<std::vector<char>> toChar2DArray(std::string s)
            {
                auto strings = toArray<std::vector<std::string>>(s);
                std::vector<std::vector<char>> results;
                for (auto i : strings)
                {
                    std::vector<char> res;
                    for (auto j : i)
                    {
                        res.push_back(j.front());
                    }

                    results.push_back(res);
                }

                return results;
            }

            inline ListNode* toListNode(std::string s)
            {
                auto arr = toIntArray(s);
                std::shared_ptr<ListNode> root(new ListNode(0));
                auto head = root.get();
                for (auto i : arr)
                {
                    head->next = new ListNode(i);
                    head = head->next;
                }

                return root->next;
            }

            inline TreeNode* toTreeNode(std::string s)
            {
                int null = INT_MIN;
                s = replaceAllString(s, "null", std::to_string(null));
                auto arr = toIntArray(s);
                if (arr.size() == 0)
                {
                    return nullptr;
                }

                TreeNode* root = new TreeNode(arr.front());
                std::queue<TreeNode*> nodes({ root });
                int i = 1;
                int length = arr.size();
                while (i < length && nodes.empty() == false)
                {
                    int maxi = std::min(length, i + (int)nodes.size() * 2);
                    while (i < maxi)
                    {
                        TreeNode* parent = nodes.front();
                        TreeNode* child = arr[i] == null ? nullptr : new TreeNode(arr[i]);
                        if (i % 2 == 0)
                        {
                            parent->right = child;
                            nodes.pop();
                        }
                        else
                        {
                            parent->left = child;
                        }

                        if (child != nullptr)
                        {
                            nodes.push(child);
                        }

                        ++i;
                    }
                }

                return root;
            }
        }
    }
}