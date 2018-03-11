// FILE: date.h
//
// CLASS PROVIDED: date (as part of namespace william_assignment_3_date)
//
// CONSTRUCTOR:
//   date (int d, int m, int y)
//     Postcondition: Default constructor is overloaded
//
// MODIFICATION MEMBER FUNCTION(S):
//   void next_day();
//     Precondition: day > 0 and month > 0 and year > 0
//     Postcondition: Handles if it is the end of the year or if it is a leap year and appropriate date is returned.
//
// GETTER MEMBER FUNCTIONS:
//   int get_day() const;
//    Postcondtion: day is returned
//
//   int get_month() const;
//    Postcondition: month is returned
//
//   int get_year() const;
//    Postcondition: year is returned
//
// FREE FUNCTIONS:
//   date num (const date& ob)
//     Postcondition: returns object passed as object date and displays the date in number format
//     (1/12/2017)
//
//   date word (const date& ob)
//     Postcondition: returns object passed as object date and displays the date in word format
//     (December 1, 2017)

#ifndef DATE_DATE_H
#define DATE_DATE_H

namespace william_assignment_3_date
{
    class date
    {
    public:
        //Constructor
        date(int d, int m, int y);

        // MODIFICAITON MEMBER FUNCTIONS
        void next_day();

        // GETTER MEMBER FUNCTIONS
        int get_day() const;
        int get_month() const;
        int get_year() const;

    private:
        int day;
        int month;
        int year;
    };

    // FREE FUNCTIONS
    date num (const date& ob);
    date word (const date& ob);

}


#endif //DATE_DATE_H
