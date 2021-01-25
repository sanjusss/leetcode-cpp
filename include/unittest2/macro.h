#pragma once
#include <type_traits>

#define MAIN_DEFINE(fun, check, index)                                           \
    int main(int /*argc*/, char* /*argv*/[]) {                                         \
        CaseRunner<decltype(fun), index>(fun, check, __FILE__); \
        return 0;                                                                      \
    }

#define TEST(fun) \
    MAIN_DEFINE(fun, &unittest::areEqual<int>, -1)
