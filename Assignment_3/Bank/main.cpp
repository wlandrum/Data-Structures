#include <iostream>
#include "bank.h"
#include "util.h"
#include <cassert> // Provides assert

using namespace william_assignment_2;
using namespace std;

int main()
{
    bank account1;

    account1.change_balance(500);
    assert(account1.get_balance() == 500);

    account1.change_interest(1.25);
    assert(account1.get_interest() == 1.25);

    account1.withdraw(100);
    assert(account1.get_balance() == 400);

    account1.deposit(100);
    assert(account1.get_balance() == 500);

    account1.add_interest(6.75);
    assert(double_equal(account1.get_balance(), 542.188));

    account1.time_taken(600);
    assert(double_equal(account1.time_taken(600), 8.53026));

    cout << "all tests passed!";
}