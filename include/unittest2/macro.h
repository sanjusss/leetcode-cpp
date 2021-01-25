#pragma once
#include "resulttype.h"

/***
 * 定义单元测试main函数。
 * @param fun 需要测试的函数。
 * @param check
 * 用于检验测试结果的函数，传入参数为fun的返回值和cases文件中当前case的最后一行字符串，返回值为bool（检测结果）和string（错误信息）的组合（pair或tuple）。
 * @param index 仅在fun函数没有返回值的时生效，将使用fun的第index（从1开始）个参数作为运行结果参与测试。
 */
#define MAIN_DEFINE(fun, check, index)                          \
    int main(int /*argc*/, char* /*argv*/[]) {                  \
        CaseRunner<decltype(fun), index>(fun, check, __FILE__); \
        return 0;                                               \
    }

#define TEST(fun) MAIN_DEFINE(fun, &unittest::areEqual<ResultType<decltype(fun)>::type>, 0)
