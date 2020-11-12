#include "922.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto A = toIntArray(params[0]);

    Solution sln;
    auto actual = sln.sortArrayByParityII(A);
    AREEQUIVALENT(A, actual);

    for (int i = 0; i < actual.size(); ++i) {
        if (i % 2 != actual[i] % 2) {
            stringstream ss;
            ss << "element of index " << i << " (" << actual[i] <<") mod 2 != " << (i % 2);
            throw TestException(ss.str());
        }
    }
}