// FILE: set.h
// Class: set (Container class that hold a collection of items with NO duplicates)
//
// VALUE SEMANTICS for the set class:
//     Assignments and the copy constructor may be used with set objects.
//
// DYNAMIC MEMORY USAGE by the set:
//     If there is not sufficient dynamic memory, then the following functions
//        throw bad_alloc: The constructors, reserve, insert, set_union, set_difference
//           and the assignment operator
//--------------------------------------------------------------------------------------
//
// CONSTRUCTORS and DESTRUCTOR:
//
// set() O(1)
//    Postcondition: emtpy set has been created
//
// ~set() O(1)
//    Postcondition: set has been destroyed with all resources being deallocated
//
// set(const set& source) 0(n)
//    Postcondition: copy of s has been created
//
// MODIFICATION MEMBER FUNCTIONS:
//
// void insert(const value_type& entry) O(n)
//   postcondition: value is entered into set and if the array is full, calls reserve function
//   to allocate more space.
//
// bool remove(const value_type& entry) O(1)
//   postcondition: value is removed from set
//
// void operator = (const set& source) O(1)
//   postcondition: current object has been assigned s.
//   returned: copy of s
//
// CONSTANT MEMBER FUNCTIONS
//
// size_type size() const { return used; } O(1)
//   postcondition: returns the amount of space used in array
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
// PRIVATE MEMBER FUNCTIONS:
//
// void resize (size_type new_capacity) O(1)
//   Postcondition: capacity of set has been modified to new_capacity
//
// size_type find (const value_type& entry) const O(n)
//   Postcondition: returned location of entry in the set if entry is in the set - used otherwise

#ifndef ASSIGNMENT_4_DYNAMIC_SET_SET_H
#define ASSIGNMENT_4_DYNAMIC_SET_SET_H

#include <iostream>
#include <cstddef>

class set
{
public:

    // TYPEDEFS and MEMBER CONSTANTS
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type DEFAULT_CAPACITY = 30;

    // CONSTRUCTOR, DESTRUCTOR, and COPY CONSTRUCTOR
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
    void resize (size_type new_capacity);
    size_type find (const value_type& entry) const;
    value_type *data;  // Pointer
    size_type used;    // Used in array
    size_type capacity;// Keeps track of capacity

};




#endif //ASSIGNMENT_4_DYNAMIC_SET_SET_H
