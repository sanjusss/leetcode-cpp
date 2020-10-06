/*
 * @Author: sanjusss
 * @Date: 2020-10-06 07:22:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-06 07:28:44
 * @FilePath: \0\800\830\test834.cpp
 */
#include "834.hpp"
#include "unittest.h"

/**
 *  @brief 
 *  用于测试每套测试用例的函数。不能改写此声明。
 * 
 *  @param params 测试用的参数。依次为被测函数调用的参数，预估值。
 *  @param index 测试用例的索引。
 */
DEFINE_TESTS(params, index) {
    int N = stoi(params[0]);
    auto edges = toInt2DArray(params[1]);
    auto expected = toIntArray(params[2]);

    Solution sln;
    auto actual = sln.sumOfDistancesInTree(N, edges);
    testCheckEqual(expected, actual);
}