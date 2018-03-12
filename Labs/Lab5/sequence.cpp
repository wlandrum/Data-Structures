// FILE: sequence.cpp
// CLASS IMPLEMENTATION: sequence
//
// INVARIANT of sequence class:
//   1. The head pointer of the list is stored in the member variable head_ptr.
//   2. The tail pointer of the list is store in the member variable tail_ptr.
//   2. The cursor is used to store the current position in the list.
//   4. The precursor is used to hold the address of the previous node in the list and is stored in precursor.
//   5. The total number of items in the list is stored in the member variable many_nodes.

#include <cassert>
#include "sequence.h"
using namespace std;
using namespace main_savitch_5;

sequence::sequence()
{
    head_ptr = nullptr;
    tail_ptr = nullptr;
    cursor = nullptr;
    precursor = nullptr;
    many_nodes = 0;
}

sequence::~sequence()
{
    list_clear(head_ptr);
}

sequence::sequence(const sequence &source)
{
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    node* index_src;
    index_src = source.head_ptr;
    precursor = head_ptr;

    if (source.cursor == nullptr)
    {
        if (source.precursor == nullptr)
        {
            cursor = nullptr;
            precursor = nullptr;
        }
        else
        {
            precursor = tail_ptr;
            cursor = nullptr;
        }
    }
    else
    {
        if (source.precursor == nullptr)
        {
            cursor = head_ptr;
            precursor = nullptr;
        }
        else
        {
            while (index_src != source.precursor)
            {
                index_src = index_src->link();
                precursor = precursor->link();
            }
            cursor = precursor->link();
        }
    }
    many_nodes = source.many_nodes;
}

void sequence::start()
{
    cursor = head_ptr;
    precursor = nullptr;
}

void sequence::advance()
{
    if (is_item())
    {
        assert(is_item());
        precursor = cursor;
        cursor = cursor->link();
    }

    else
        start();

}

void sequence::insert(const sequence::value_type &entry)
{
    if (is_item())
    {
        if (precursor != nullptr)
        {
            list_insert(precursor, entry);
            cursor = precursor->link();
        }
        else
        {
            list_head_insert(head_ptr, entry);
            precursor = nullptr;
            cursor = head_ptr;
        }
    }
    else
    {
        if (many_nodes == 0)
        {
            list_head_insert(head_ptr, entry);
            precursor = nullptr;
            cursor = head_ptr;
            tail_ptr = head_ptr;
        }

        else
        {
            list_head_insert(head_ptr, entry);
            precursor = nullptr;
            cursor = head_ptr;
        }

    }
    many_nodes++;

}

void sequence::attach(const sequence::value_type &entry)
{
    if (is_item())
    {
        if (cursor == tail_ptr)
        {
            list_insert(cursor, entry);
            precursor = cursor;
            cursor = cursor->link();
            tail_ptr = tail_ptr->link();
        }

        else
        {
            list_insert(cursor, entry);
            precursor = cursor;
            cursor = cursor->link();
        }
    }

    if (!is_item())
    {

        if ((head_ptr == nullptr) && (tail_ptr == nullptr))
        {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
            precursor = nullptr;
            tail_ptr = head_ptr;
        }

        else
        {
            precursor = list_locate(head_ptr, list_length(head_ptr));
            list_insert(precursor, entry);
            cursor = precursor->link();
            tail_ptr = tail_ptr->link();
        }
    }

    many_nodes++;
}

sequence& sequence::operator=(const sequence &source)
{
    many_nodes = source.many_nodes;
    list_copy(source.head_ptr, head_ptr, tail_ptr);

    node* index_src;
    index_src = source.head_ptr;
    precursor = head_ptr;

    if (source.head_ptr == head_ptr)
        return *this;

    if (source.cursor == nullptr)
    {
        if (source.precursor == nullptr)
        {
            cursor = nullptr;
            precursor = nullptr;
        }
        else
        {
            precursor = tail_ptr;
            cursor = nullptr;
        }
    }
    else
    {
        if (source.precursor == nullptr)
        {
            cursor = head_ptr;
            precursor = nullptr;
        }
        else
        {
            while (index_src != source.precursor)
            {
                index_src = index_src->link();
                precursor = precursor->link();
            }
            cursor = precursor->link();
        }
    }
    return *this;
}


void sequence::remove_current()
{
    assert(is_item());

    if (cursor == head_ptr)
    {
        if (many_nodes > 1)
        {
            list_head_remove(head_ptr);
            cursor = head_ptr;
            precursor = nullptr;
        }
        else
        {
            list_head_remove(head_ptr);
            cursor = precursor = head_ptr = tail_ptr = nullptr;
        }
    }
    else
    {
        cursor = cursor->link();
        list_remove(precursor);
    }
    many_nodes--;

}

sequence::value_type sequence::current() const
{
    assert(is_item());

    return cursor->data();
}






