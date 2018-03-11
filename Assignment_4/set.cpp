// FILE: set.cpp
// CLASS IMPLEMENTED: set (see set.h for documentation)
// INVARIANT for the set class:
//    1. The number of items in the set is in the member variable used.
//    2. For an empty set, there can be no duplicate items.
//       For a non empty set, items are stored in data[0] to data[CAPACITY - 1].

#include "set.h"
#include <cassert>   // Provides assert function
using namespace std;

set::set()
{
    used = 0;
}

set::size_type set::size() const
{
    return used;
}

void set::insert(const value_type &entry)
{
    assert(size() < CAPACITY);

    if(!contains(entry))
    {
        data[used] = entry;
        used++;
    }
}

void set::remove(const value_type &entry)
{
    size_type x = find(x);

    if (x >= 0)
    {
        data[x] = data[used - 1];
        used--;
    }

}

set::size_type set::find(const value_type &entry) const
{
    size_type x = 0;

    while (x < used && data[x] != entry)
        x++;
    return x;
}

std::ostream &operator<<(std::ostream &output, const set &s)
{
    for (set::size_type i = 0; i <s.size(); i++)
        output << s.data[i] << " ";
    return output;
}

bool set::contains(const value_type &entry) const
{
    return find(entry) < used;
}

set set_union(const set &s1, const set &s2)
{
    set result;
    for (set::size_type i = 0; i < s1.size(); i++)
        result.insert(s1.data[i]);
    for (set::size_type i = 0; i < s1.size(); i++)
        result.insert(s2.data[i]);
    return result;
}

set set_intersection(const set &s1, const set &s2)
{
    set result;
    for (set::size_type i = 0; i < s1.size(); i++)
        if (s2.contains(s1.data[i]))
            result.insert(s1.data[i]);
    return result;
}

set set_difference(const set &s1, const set &s2)
{
    set result;
    for (set::size_type i = 0; i < s1.size(); i++)
        if (!s2.contains(s1.data[i]))
            result.insert(s1.data[i]);
    return result;
}

bool is_subset(const set &s1, const set &s2)
{

    for (set::size_type i = 0; i < s1.size(); i++)
        return s2.contains(s1.data[i]);
}

bool operator==(const set &s1, const set &s2)
{
    for (set::size_type i = 0; i < s1.size(); i++)
    {
        if(!s2.contains(s1.data[i]))
            return false;
    }

    return true;

}


