// set() O(1)
//    Postcondition: emtpy set has been created
//
// ~set() O(1)
//    Postcondition: set has been destroyed with all resources being deallocated
//
// set(const set& source) O(n)
//    Postcondition: copy of s has been created
//
// MODIFICATION MEMBER FUNCTIONS:
//
// void insert(const value_type& entry) O(1)
//   postcondition: value is entered into set.
//
// bool remove(const value_type& entry) O(1)
//   postcondition: value is removed from set
//
// void operator = (const set& source) O(n)
//   postcondition: current object has been assigned s.
//   returned: copy of s
//
// CONSTANT MEMBER FUNCTIONS
//
// size_type size() const { return used; } O(1)
//   postcondition: number of elements in the set has been returned
//
// bool contains (const value_type& entry) const; O(n)
//   postcondition: reads if value is in container and returns true or false
//
// FRIEND FUNCTIONS
//
// friend set set_union (const set& s1, const s2) O(n)
//   postcondition: combines two sets
//
// friend set set_intersection (const set& s1, const set& s2) O(n)
//   postcondition: finds the common values of each set object and combines them into another set object
//
// friend set set_difference (const set& s1, const set& s2) O(n)
//   postcondition: outputs difference of two sets into another set
//
// friend bool is_subset (const set& s1, const set& s2) O(n)
//   postcondition: reads values in set object and outputs if one set object is a subset of another
//
// friend bool operator == (const set& s1, const set& s2) O(n)
//   postcondition: returns if the values of one set container are in another set container
//
// friend std::ostream& operator << (std::ostream& output, const set& s) O(n)
//   postcondition: overloads the << operator to allow the output of a set container
//
#ifndef LINKED_LIST_SET_SET_H
#define LINKED_LIST_SET_SET_H

#include "node.h"
#include <iostream>


class set
{
public:
    // TYPEDEFS and MEMBER CONSTANTS
    typedef node::value_type value_type;
    typedef std::size_t size_type;
    // CONSTRUCTORS and DESTRUCTOR
    set();
    ~set();
    set(const set& source);
    // MODIFICATION MEMBER FUNCTIONS
    void insert (const value_type& entry);
    void remove (const value_type& entry);
    set& operator = (const set& source);
    // CONSTANT MEMBER FUNCTIONS
    size_type size() const { return used; };
    bool contains (const value_type& entry) const;
    // FRIEND FUNCTIONS
    friend set set_union (const set& s1, const set& s2);
    friend set set_intersection (const set& s1, const set& s2);
    friend set set_difference (const set& s1, const set& s2);
    friend bool is_subset (const set& s1, const set& s2);
    friend bool operator == (const set& s1, const set& s2);
    friend std::ostream& operator << (std::ostream& output, const set& s);

private:
    node *head_ptr;
    size_type used;
};


#endif //LINKED_LIST_SET_SET_H