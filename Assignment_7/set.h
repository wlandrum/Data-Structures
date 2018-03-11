// set() O(1)
//    Postcondition: empty set has been created
//
// ~set() O(1)
//    Postcondition: set has been deallocated
//
// set (const set<T>& source) O(n)
//    Postcondtion: an object gets initialized with the source
//
// set<T>& operator = (const set& source) O(n)
//    Postcondition: an initialized object gets set equal to a copy of the source
//
// void insert (const T& entry) O(1)
//    Postcondtion: entry is in the set
//
// void remove (const T& entry) O(1)
//    Postcondition: entry is not in the set
//
// size_t size() const; O(1)
//    Postcondition: number of elements in the set has been returned
//
// bool contains (const T& entry) const; O(n)
//    Postcondtion: whether entry is in the set has been returned
//
// template <typename U> O(n)
// friend set<U> set_union (const set<U>& s1, const set<U>& s2)
//    Postcondtion: union of s1 & s2 has been returned
//
// template <typename U> O(n)
// friend set<U> set_intersection (const set<U>& s1, const set<U>& s2)
//    Postcondtion: intersection of s1 & s2 has been returned
//
// template <typename U> O(n)
// friend set<U> set_difference (const set<U>& s1, const set<U>& s2)
//    Postcondtion: difference of s1 & s2 has been returned
//
// template <typename U> O(n)
// friend bool is_subset (const set<U>& s1, const set<U>& s2)
//    Postcondtion: returned whether s1 is a subset of s2
//
// template <typename U> O(n)
// friend bool operator == (const set<U>& s1, const set<U>& s2)
//    Postcondtion: returned whether s1 & s2 are equal
//
// template <typename U> O(n)
// friend set::ostream& operator << (std::ostream& output, const set<U>& s)
//    Postcondition: s has been displayed on output

#ifndef TEMPLATE_SET_SET_H
#define TEMPLATE_SET_SET_H

#include <cstdlib>
#include <iostream>
#include "node2.h"


namespace main_savitch_6B {

    template<typename T>
    class set {
    public:

        // CONSTRUCTORS and DECONSTRUCTOR and OPERATOR
        set();
        ~set();
        set(const set<T> &source);
        set<T> &operator=(const set &source);
        // MODIFICATION MEMNBER FUNCTIONS
        void insert(const T &entry);
        void remove(const T &entry);
        // CONSTANT MEMBER FUNCTIONS
        size_t size() const { return used; };
        bool contains(const T &entry) const;
        // FRIEND FUNCTIONS

        template<typename U>
        friend set<U> set_union(const set<U> &s1, const set<U> &s2);

        template<typename U>
        friend set<U> set_intersection(const set<U> &s1, const set<U> &s2);

        template<typename U>
        friend set<U> set_difference(const set<U> &s1, const set<U> &s2);

        template<typename U>
        friend bool is_subset(const set<U> &s1, const set<U> &s2);

        template<typename U>
        friend bool operator==(const set<U> &s1, const set<U> &s2);

        template<typename U>
        friend std::ostream &operator<<(std::ostream &output, const set<U> &s);

    private:
        node<T> *head_ptr;
        size_t used;

    };

}

#include "set.template"
#endif //TEMPLATE_SET_SET_H
