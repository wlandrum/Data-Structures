// FILE: set.cpp
// CLASS IMPLEMENTED: set (see set.h for documentation
//
// INVARIANT for the sequence class:
//   1. The number of items in the set is in the member variable used
//   2. The actual items of the sequence are stored in a partially filled array and cannot hold duplicates
//      The array is a dynamic array, pointed to by the member variable data.
//   3. The size of the dynamic array is in the member variable capacity.

#include <algorithm>
#include "set.h"

set::set()
{
    data = new value_type[DEFAULT_CAPACITY];
    capacity = DEFAULT_CAPACITY;
    used = 0;
}

set::~set()
{
    delete [] data;
}

set::set(const set &source)
{
    data = new value_type[source.capacity];
    capacity = source.capacity;
    used = source.used;

    for (size_type i = 0; i < used; i++)
        data[i] = source.data[i];
}

void set::insert(const value_type &entry)
{
    if (contains(entry))
        return;

    if (used == capacity)
        resize(used + 1);

    data[used] = entry;
    used++;

}

set::size_type set::find(const value_type &entry) const
{
    size_type x = 0;
    while (x < used && data[x] != entry)
        x++;
    return x;
}

bool set::contains(const value_type &entry) const
{
    return find(entry) < used;
}

void set::resize(set::size_type new_capacity)
{
    value_type *new_array;

    if (new_capacity == capacity)
        return;

    if (new_capacity < used)
        new_capacity = used;

    new_array = new value_type[new_capacity];
    std::copy(data, data + used, new_array);
    delete [] data;
    data = new_array;
    capacity = new_capacity;

}

void set::remove(const value_type &entry)
{
    find(entry);
    if (entry >= 0)
    {
        data[entry] = data[used - 1];
        used--;
    }

}

std::ostream &operator<<(std::ostream &output, const set &s)
{
    for (set::size_type i = 0; i < s.size(); i++)
        output << s.data[i] << " ";
    return output;
}

set& set::operator=(const set &source)
{
    value_type *new_data;

    if (this == &source)
        return *this;

    if (capacity != source.capacity)
    {
        new_data = new value_type[source.capacity];
        delete [] data;
        data = new_data;
        capacity = source.capacity;
    }

    used = source.used;
    std::copy(source.data, source.data + used, data);

}

set set_union(const set &s1, const set &s2)
{
    set result;
    for(set::size_type i = 0; i < s1.size(); i++)
        result.insert(s1.data[i]);
    for(set::size_type i = 0; i < s1.size(); i++)
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
   if (is_subset(s1, s2))
       return true;
    return is_subset(s2, s1);
}














