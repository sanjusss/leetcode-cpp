/*
 * @Author: sanjusss
 * @Date: 2020-10-09 07:50:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-09 07:59:21
 * @FilePath: \0\100\140\test141.cpp
 */
#include "141_20201009.hpp"
/***
 * 测试用例示例文件。
 * 目前只支持gcc和mingw。
 * 
 * 每个待测文件需要有一个同名的cases文件。
 * 例如需要测试"test771.cpp"，需要在相同目录下准备一个"test771.cases"文件。
 * cases文件第一行格式为"a,b"，a表示test_function中params的大小（即被测函数参数数量+预估值数量），b表示是否删除下面每行首尾的双引号。
 * 第二行开始是测试用例的内容。每个参数/预估值为一行。
 */

#include "unittest.h"

/**
 *  @brief 
 *  用于测试每套测试用例的函数。不能改写此声明。
 * 
 *  @param params 测试用的参数。依次为被测函数调用的参数，预估值。
 *  @param index 测试用例的索引。
 */
DEFINE_TESTS(params, index) {
    /**
     * 应把string转为实际参数的类型。
     * include/inputfromstring.hpp中有对应的实现。
     * 可以用testCheckEqual检查值是否为预计值。
     */
    vector<ListNode*> nodes;
    auto head = toListNode(params[0], &nodes);
    int pos = stoi(params[1]);
    if (pos >= 0) {
        nodes.back()->next = nodes[pos];
    }

    bool expected = params[2] == "true";

    Solution sln;
    bool actual = sln.hasCycle(head);
    testCheckEqual(expected, actual);
}