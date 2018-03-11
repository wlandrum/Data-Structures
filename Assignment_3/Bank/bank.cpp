// FILE: bank.cpp
//
// CLASS PROVIDED: bank (as part of namespace william_assignment_2;

#include <cassert> // Provides assert
#include "bank.h"
#include <iostream>

using namespace std;
using namespace william_assignment_2;

bank::bank()
{
    balance = 0;
    interest = 0;
}

bank::value_type bank::get_balance() const
{
    return balance;
}

bank::value_type bank::get_interest() const
{
    return interest;
}

bank::value_type bank::change_balance(value_type new_bal)
{
    assert(new_bal >= 0);
    balance += new_bal;
    return balance;
}

bank::value_type bank::change_interest(value_type new_int)
{
    assert(new_int >= 0);
    interest += new_int;
    return interest;
}

void bank::deposit(value_type value)
{
    assert(value >= 0);
    balance += value;
}

void bank::withdraw(value_type value)
{
    if (value > balance)
        cout << "Do you want your account to go into the negative? Because that is how your account goes into the negative!";
    else
        balance -= value;
}

void bank::add_interest(value_type value)
{
    assert(value >= 0);
    balance += (balance * interest * value) / 100;
}

bank::value_type bank::time_taken(value_type value)
{
    assert(value >= 0);
    value = value - balance;
    return (value * 100) / (balance * interest);
}
