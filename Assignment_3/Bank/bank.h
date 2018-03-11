// FILE: bank.h
// CLASS PROVIDED: bank (as part of namespace william_assignment_2
//
// CLASS DEFINITIONS:
//
//   CONSTRUCTOR:
//     bank()
//       Postcondition: default values set
//
//   CONSTANT MEMBER FUNCTIONS:
//     double get_balance const
//       Postcondition: returns balance
//
//     double get_interest const
//       Postcondition: returns interest
//
//   MODIFICATION MEMBER FUNCTIONS
//     double change_balance (value_type new_bal)
//       Precondition: new_bal >= 0
//       Postcondition: new_bal is added to current balance and balance is returned
//
//     double change_interest (value_type new_int)
//       Precondition: new_int >= 0
//       Postcondition: new_int is added to current interest and interest is returned
//
//     void deposit (value_type value)
//       Precondition: value >= 0
//       Postcondition: value is added to current balance
//
//     void withdraw (value_type value)
//       Precondition: value > balance
//       Postcondition: value is subtracted from balance
//
//     void add_interest (value_type value)
//       Precondition: value >= 0;
//       Postcondition: value is added to interest
//
//     double time_taken (value_type value)
//       Precondition: years >= 0
//       Postcondition: the time years is passed as a value and the time it would take to get
//       the desired balance is returned.



#ifndef BANK_BANK_H
#define BANK_BANK_H

namespace william_assignment_2
{

    class bank
    {
    public:
        // TYPEDEFS
        typedef double value_type;
        // CONSTRUCTOR
        bank();

        //CONSTANT MEMBER FUNCTIONS
        value_type get_balance() const;
        value_type get_interest() const;

        // MODIFICATION MEMBER FUNCTIONS
        value_type change_balance (value_type new_bal);
        value_type change_interest (value_type new_int);
        void deposit (value_type value);
        void withdraw (value_type value);
        void add_interest (value_type value);
        value_type time_taken (value_type value);


    private:
        value_type balance, interest;
    };
}


#endif //BANK_BANK_H
