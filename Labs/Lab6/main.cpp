#include <iostream>
#include "node.h"

using namespace std;
using namespace main_savitch_5;


node* merge_lists(const node* head1, const node* head2);
// Postcondition: a new list is created, the contents of the passed lists are put into
// the new list, and the new list is returned, sorted, with no duplicates

void display (node* head);
// Postcondition: the list is displayed

int main()
{
    node *list1 = new node();
    node *list2 = new node();
    node *merged_list = nullptr;

    list_insert(list1, 10);
    list_insert(list1, 9);
    list_insert(list1, 8);
    list_insert(list1, 7);
    list_insert(list1, 6);
    list_insert(list1, 2);

    list_insert(list2, 6);
    list_insert(list2, 4);
    list_insert(list2, 3);
    list_insert(list2, 2);


    merged_list = merge_lists(list1, list2);

    display(merged_list);

}

node* merge_lists(const node* head1, const node* head2)
{
    node* newListHead = nullptr;

    // Checks for empty list and returns nothing
    if (head1 == nullptr && head2 == nullptr)
    {
        return nullptr;
    }
        // Checks if first list is empty and inserts seconds lists data into new list
    else if (head1 == nullptr)
    {
        newListHead = new node(head2->data(), nullptr);
    }
        // Checks if second list is empty and insert first lists data into new list
    else if (head2 == nullptr)
    {
        newListHead = new node(head1->data(), nullptr);
    }
    else
    {
        // Checks if data is in ascending order and puts the data in the new list.
        if (head1->data() < head2->data())
        {
            newListHead = new node(head1->data(), nullptr);
            head1 = head1->link();
        }
        else if (head1->data() > head2->data())
        {
            newListHead = new node(head2->data(), nullptr);
            head2 = head2->link();
        }

        else
        {
            newListHead = new node(head2->data(), nullptr);
            head2 = head2->link();
            head1 = head1->link();
        }
    }

    node* temp = newListHead;

    while (temp != NULL)
    {
        if (head1 == NULL)
        {
            while (head2 != NULL)
            {
                list_insert(temp, head2->data());
                temp = temp->link();
                head2 = head2->link();
            }
            return newListHead;
        }
        else if (head2 == NULL)
        {
            while (head1 != NULL)
            {
                list_insert(temp ,head1->data());
                temp = temp->link();
                head1 = head1->link();
            }
            return newListHead;

        }

        else
        {
            if (head1->data() < head2->data())
            {
                list_insert(temp, head1->data());
                temp = temp->link();
                head1 = head1->link();
            }

            else if(head1->data() > head2->data())
            {
                list_insert(temp, head2->data());
                temp = temp->link();
                head2 = head2->link();
            }
                // if both of the nodes have the same entry, then copy only one of them to the next node
            else
            {
                list_insert(temp, head2->data());
                temp = temp->link();
                head2 = head2->link();
                head1 = head1->link();
            }
        }

    }
}

void display (node* head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data() << "->";
        temp = temp->link();
    }
    cout << "NULL" << endl;
}



