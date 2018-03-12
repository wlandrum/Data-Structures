// FILE: sequence.cpp
// CLASS PROVIDED: sequence (provided by sequence.h)
// INVARIANT for the sequence class:
//    1. The number of items in the sequence is stored in the member variable used.
//    2. For an empty sequence, we do not care what is store in any of data; for
//       a non-empty sequence, the items are stored in their sequence order from
//       data[0] to data[used - 1], and we do not care what is store in the rest of
//       the data.
//    3. If there is a current item, then it lies in data[current_index]; if there is no current
//       item, then current_index = used.

#include "sequence.h"
#include <cassert>
#include <iostream>
using namespace std;
using namespace sequence_william_03;

sequence::sequence()
{
    current_index = 0;
    used = 0;

}

void sequence::start()
{
    current_index = 0;
}

void sequence::advance()
{
    assert(is_item());

    current_index++;

}

void sequence::insert(const value_type &entry)
{
    size_type i;

    assert(size() < CAPACITY);

    if(!is_item())
        current_index = 0;
    for (i = used; i > current_index ; --i)
        data[i] = data[i - 1];
    data[current_index] = entry;
    ++used;
}

void sequence::attach(const value_type &entry)
{
    size_type i;

    assert(size() < CAPACITY);

    if (!is_item())
        current_index = used - 1;

    for (i = used; i > current_index ; --i)
        data[i] = data[i - 1];

    data[current_index] = entry;
    ++current_index;
    ++used;
}

void sequence::remove_current()
{
    size_type i;

    assert(is_item());

    for (i = current_index; i < used - 1; ++i)
    {
        data[i]= data[i+1];
    }

    --used;
}

sequence::size_type sequence::size() const
{
    return used;
}

bool sequence::is_item() const
{
    return current_index < used;
}

sequence::value_type sequence::current() const
{
    return data[current_index];
}

void sequence::print_menu()
// Library facilities used: iostream
{
    cout << endl; // Print blank line fore menu
    cout << "The following choices are available " << endl;
    cout << " !   Activate the start() function" << endl;
    cout << " +   Activate the advance() function" << endl;
    cout << " ?   Print the result from the is_item() function" << endl;
    cout << " C   Print the result from the current() function" << endl;
    cout << " P   Print a copy of the entire seqence" << endl;
    cout << " S   Print the result from the size() function" << endl;
    cout << " I   Insert a new number with the insert(...) function" << endl;
    cout << " A   Attach a new number with the attach(...) function" << endl;
    cout << " R   Activate the remove_current() function" << endl;
    cout << " Q   Quit this test program" << endl;

}

char sequence::get_user_command()
// Library facilites used: iostream
{
    char command;

    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character

    return command;
}

void sequence::show_sequence(sequence display)
// Library facilities used: iostream
{
    for (display.start(); display.is_item(); display.advance())
        cout << display.current() << endl;
}

double sequence::get_number()
// Library facilites used: iostream
{
    double result;

    cout << "Please enter a real number for the sequence: ";
    cin >> result;
    cout << result << " has been read." << endl;
    return result;

}

