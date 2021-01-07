#include "547_20210107.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto isConnected = toInt2DArray(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.findCircleNum(isConnected);

    AREEQUAL(expected, actual);
}