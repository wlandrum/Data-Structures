#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <iostream>
#include <cstdlib>
#include <list>
#include <cassert>

template <typename T>
class deque
{
public:

    deque();
    //postcondition: empty deque has been created

    T& front();
    // precondition: deque is not empty
    // postcondition: reference to element at front of deque
    //                has been returned

    T front() const;
    // precondition: deque is not empty
    // postcondition: copy of element at front of deque
    //                has been returned

    T& back();
    // precondition: deque is not empty
    // returned: reference to element at front of deque

    T back() const;
    // precondition: deque is not empty
    // returned: copy of element at back of deque

    void push_front (const T& entry);
    // postcondition: entry has been inserted at the front
    //                of the deque

    void push_back (const T& entry);
    // postcondition: entry has been inserted at the back
    //                of the deque

    void pop_front();
    // precondition: deque is not empty
    // postcondition: element at front of deque has been removed

    void pop_back();
    // precondition: deque is not empty
    // postcondition: element at back of deque has been removed

    size_t size() const { return (l.size()); };
    // postcondition: number of elements in deque has been returned

    bool empty() const { l.empty(); };
    // returned: whether deque is empty

    template <typename U>
    friend bool operator == (const deque<U>& dq1, const deque<U>& dq2);
    // returned: whether 2 deques are equal - equal is defined
    //           as the deques have the same number of elements &
    //           corresponding elements are equal

    template <typename U>
    friend std::ostream& operator<< (std::ostream& out, const deque<U>& dq);
    // postcondition: dq has been display from front to rear on out

private:
    std::list<T> l;
};


#include "deque.template"
#endif

