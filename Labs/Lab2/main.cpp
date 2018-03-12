#include <iostream>
#include "complex.h"
#include <cassert>

using namespace std;
using namespace william_lab_2;

int main()
{
    complex c(8, 7);
    assert(c.get_real() == 8);
    assert(c.get_complex() == 7);

    complex c1(8, 7);
    complex c2(4, 3);
    complex c3 = c1 + c2;


    complex c4 = c1 - c2;
    assert(c4.get_real() == 4);
    assert(c4.get_complex() == 4);

    complex c5 = c1 * c2;
    assert(c5.get_real() == 672);
    assert(c5.get_complex() == 0);


    complex c6 = c1 / c2;
    assert(c6.get_real() > 0);
    assert(c6.get_complex() == 0);

    cout << "all tests passed!";
}
