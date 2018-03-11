// FILE: set.cpp
// CLASS IMPLEMENTED: set (see set.h for documentation
//
// INVARIANT for the set class:
//   1. The number of items in the set is in the member variable used
//   2. The actual items of the set are stored in a linked list and cannot hold duplicates
//      The the beginning of list is stored in the member variable head_ptr;


#include "set.h"
#include <cassert>
#include <iostream>

using namespace std;

set::set()
{
    head_ptr = nullptr;
    used = 0;
}

set::~set()
{
    list_clear(head_ptr);
}

set::set(const set &source)
{
    node *tail_ptr;

    list_copy(source.head_ptr, head_ptr, tail_ptr);
    used = source.used;
}

void set::insert(const set::value_type &entry)
{
    if (list_search(head_ptr, entry) != NULL)
        return;

    list_head_insert(head_ptr, entry);
    used++;
}

void set::remove(const set::value_type &entry)
{
    node* remove_ptr = list_search(head_ptr, entry);

    if (remove_ptr == NULL)
        return;
    remove_ptr->set_data(head_ptr->data());
    list_head_remove(head_ptr);
    --used;
}

set &set::operator=(const set &source)
{
    if (&source == this)
        return *this;

    list_head_remove(head_ptr);
    node *tail_ptr;
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    used = source.used;

    return *this;
}

bool set::contains(const set::value_type &entry) const
{
    return list_search(head_ptr, entry) != nullptr;
}

std::ostream &operator<<(std::ostream &output, const set &s)
{
    const node *cursor;

    for (cursor = s.head_ptr; cursor != NULL; cursor = cursor->link())
    {
        output << cursor->data() << " ";
    }

    return output;

}

set set_union(const set &s1, const set &s2)
{
    set result;
    node *cursor;
    for (cursor = s1.head_ptr; cursor != NULL; cursor = cursor->link())
        result.insert(cursor->data());
    for (cursor = s2.head_ptr; cursor != NULL; cursor = cursor->link())
        result.insert(cursor->data());
    return result;
}

set set_intersection(const set &s1, const set &s2)
{
    set result;
    node *cursor;
    for (cursor = s1.head_ptr; cursor != NULL; cursor = cursor->link())
        if (s2.contains(cursor->data()))
            result.insert(cursor->data());
    return result;
}

set set_difference(const set &s1, const set &s2)
{
    set result;
    node *cursor;
    for (cursor = s1.head_ptr; cursor != NULL; cursor = cursor->link())
        if (!s2.contains(cursor->data()))
            result.insert(cursor->data());
    return result;
}

bool is_subset(const set &s1, const set &s2)
{
    node *cursor;
    for (cursor = s1.head_ptr; cursor != NULL; cursor = cursor ->link())
        if (s2.contains(cursor->data()))
            return true;
    return false;
}

bool operator == (const set& s1, const set& s2)
{
    return is_subset(s1, s2) && is_subset(s2, s1);
}





