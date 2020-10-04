/***
 * 测试用例示例文件。
 * 需要先安装boost库、gcc、gdb
 * 对于测试用例"testxxx.cpp"，打开文件后按F5即可运行测试。
 */
#include "1.hpp"
#include "unittest.h"

/**
 *  @brief 
 *  用于测试每套测试用例的函数。不能改写此声明。
 * 
 *  @param params 测试用的参数。依次为被测函数调用的参数，预估值，测试用例的索引。
 */
void test_function(const vector<string>& params, int index) {
    /**
     * 应把string转为实际参数的类型。
     * include/stringconvert.hpp中有对应的实现。
     */
    auto nums = toIntArray(params[0]);
    auto target = stoi(params[1]);
    auto expected = toIntArray(params[2]);
    Solution sln;
    auto actual = sln.twoSum(nums, target);
    sort(actual.begin(), actual.end());
    sort(expected.begin(), expected.end());
    testCheckEqual(expected, actual);
}

/**
 * 初始化所有测试用例，必须放在最后。
 * 每个待测文件需要有一个同名的cases文件。
 * 例如需要测试"test771.cpp"，需要在相同目录下准备一个"test771.cases"文件。
 * 
 * cases文件第一行格式为"a,b"，a表示test_function中params的大小（即被测函数参数数量+预估值数量），b表示是否删除下面每行首尾的双引号。
 * 第二行开始是测试用例的内容。每个参数/预估值为一行。
 */
DEFINE_TESTS_SUITE