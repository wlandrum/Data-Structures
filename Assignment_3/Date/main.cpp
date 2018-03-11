#include <iostream>
#include <cassert>
#include "date.h"

using namespace std;
using namespace william_assignment_3_date;

int main()
{
    date d1 (1, 3, 2017);
    assert(d1.get_day() == 1);
    assert(d1.get_month() == 3);
    assert(d1.get_year() == 2017);
    d1.next_day();
    assert(d1.get_day() == 2);
    assert(d1.get_month() == 3);
    assert(d1.get_year() == 2017);

    date testLeap (28, 2, 2020); // Tests leap year
    testLeap.next_day();
    assert(testLeap.get_day() == 29);
    assert(testLeap.get_month() == 2);
    assert(testLeap.get_year() == 2020);

    date testDecem (31, 12, 2017); // Tests end of year
    testDecem.next_day();
    assert(testDecem.get_day() == 1);
    assert(testDecem.get_month() == 1);
    assert(testDecem.get_year() == 2018);
    
    cout << "all tests passed";

}