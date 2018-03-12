#include <iostream>
#include <cstdlib>
#include <list>
#include <cassert>

using namespace std;

list<int>* create_list1();
// returned a list of integers sorted in strictly increasing order

list<int>* create_list2();
// returned a list of integers sorted in strictly increasing order

template <typename T>
list<T>* merge_sorted_lists (const list<T>& l1, const list<T>& l2);
// preconditions: l1 & l2 are sorted in strictly increasing order
// returned: list of all elements from l1 & l2 with duplicates removed
//           and sorted in strictly increasing order

template <typename T>
void display_list (const list<T> l);
// postcondition: elements from l3 have been displayed on standard
//                output

template <typename T>
bool is_sorted (const list<T>& l);
// returned whether elements in l are sorted in increasing order

int main(int argc, char **argv)
{
    list<int>* l1 = create_list1();
    list<int>* l2 = create_list2();
    list<int>* l3 = merge_sorted_lists ( *l1, *l2 );
    display_list ( *l3 );
    return EXIT_SUCCESS;
}

list<int>* create_list1()
{
    list<int>* l = new list<int>;
    l ->push_back(12);
    l ->push_back(50);
    l ->push_back(7);
    l ->push_back(2);
    l ->push_back(13);
    l->sort();

    return l;
}

list<int>* create_list2()
{
    list<int> *l = new list<int>;
    l ->push_back(1);
    l ->push_back(42);
    l ->push_back(32);
    l ->push_back(13);
    l ->push_back(75);
    l->sort();

    return l;
}

template<typename T>
list<T> *merge_sorted_lists(const list<T> &l1, const list<T> &l2)
{
    assert (is_sorted(l1));
    assert (is_sorted(l2));

    list<int> *l = new list<int>;
    typename list<T>::const_iterator itr1 = l1.begin();
    typename list<T>::const_iterator itr2 = l2.begin();

    while (itr1 != l1.end())
    {
        l->push_back(*itr1);
        ++itr1;
    }

    while (itr2 != l2.end())
    {
        l->push_back(*itr2);
        ++itr2;
    }

    l->sort();
    l->unique();

    return l;
}

template<typename T>
bool is_sorted(const list<T> &l)
{

    typename list<T>::const_iterator itr = l.begin();

    while (itr != l.end())
    {
        int temp = *itr;
        ++itr;
        if (temp < *itr)
            return true;
    }

    return false;
}

template<typename T>
void display_list(const list<T> l)
{
    list<int>::const_iterator itr;

    for (itr = l.begin(); itr != l.end(); ++itr)
    {
        cout << " " << *itr;
    }
}
