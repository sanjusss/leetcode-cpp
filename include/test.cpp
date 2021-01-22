#include <iostream>
#include <typeinfo>
#include <vector>
#include "unittest2/fromstring.hpp"

using namespace std;

template<class T>
void print(int i) {
    cout << i << "    " << typeid(T).name() << endl;
}

template <class T>
class Printer;

template <class Res, class... Args>
class Printer<Res(Args...)> {
public:
    void print() {
        cout << sizeof...(Args) << endl;
        int i = 0;
        ::print<Res>(i);
        (::print<Args>(++i), ...);
    }
};

int main(int, char**) {
    // Printer<decltype(main)> p;
    // p.print();
    FromString<Printer<decltype(main)>*>::convert(string());
    return 0;
}