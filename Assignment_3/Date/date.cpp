//
// Created by william on 1/30/18.
//

#include <iostream>
#include <cassert>
#include <cstring>
#include "date.h"

using namespace william_assignment_3_date;
using namespace std;

date::date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

int date::get_day() const
{
    return day;
}

int date::get_month() const
{
    return month;
}

int date::get_year() const
{
    return year;
}

void date::next_day()
{
    assert(day > 0 && month > 0 && year > 0);
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)
    {
        if (day < 31)
            day++;
        else
        {
            day = 1;
            month++;
        }
    }

    else if (month == 12)
    {
        if (day < 31)
            day++;
        else
        {
            day = 1;
            month = 1;
            year++;
        }
    }

    else if (month == 2)
    {
        if((year % 4 != 0 && day < 28) || (year % 4 == 0 && day < 29))
            day++;
        else
        {
            day = 1;
            month++;
        }

    }

}

date william_assignment_3_date::num(const date& ob)
{
    cout << "Date in number format...\n" << ob.get_day() << "/" << ob.get_month() << "/" << ob.get_year() << endl;
    return date(ob);
}

date william_assignment_3_date::word(const date &ob)
{
    string word[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    cout << "Date in word format..." << word[ob.get_month() - 1] << " " << ob.get_day() << ", " << ob.get_year() << endl;
}




