#include "deque.h"

using namespace std;

int main()
{

    deque<int> dq1;
    assert(dq1.empty());
    dq1.push_front(10);
    cout << dq1 << endl;
    assert(!dq1.empty());
    dq1.pop_front();
    assert(dq1.empty());
    dq1.push_back(2);
    assert(dq1.size() == 1);


    deque<int> dq2;
    dq2.push_front(3);
    dq2.push_front(4);
    dq2.push_front(5);
    dq2.push_front(6);
    dq2.push_front(7);
    assert(!dq2.empty());
    cout << dq2 << endl;
    assert(dq2.back() == 3);
    assert(dq2.front() == 7);
    dq2.pop_front();
    assert(dq2.front() == 6);
    dq2.pop_front();
    assert(dq2.front() == 5);
    dq2.pop_front();
    assert(dq2.front() == 4);
    dq2.pop_front();
    assert(dq2.front() == 3);
    dq2.pop_front();
    assert(dq2.empty());

    deque<int> dq3;
    dq3.push_back(8);
    dq3.push_back(9);
    dq3.push_back(10);
    dq3.push_back(11);
    dq3.push_back(12);
    cout << dq3 << endl;
    assert(!dq3.empty());
    assert(dq3.front() == 8);
    dq3.pop_back();
    dq3.pop_back();
    dq3.pop_back();
    dq3.pop_back();
    dq3.pop_back();
    assert(dq3.empty());

    deque<int> dq4;
    dq4.push_front(13);
    dq4.push_front(14);
    dq4.push_front(15);
    dq4.push_front(16);
    dq4.push_front(17);
    cout << dq4 << endl;
    deque<int> dq5;
    dq5.push_front(13);
    dq5.push_front(14);
    dq5.push_front(15);
    dq5.push_front(16);
    dq5.push_front(17);
    cout << dq5 << endl;
    assert(dq4 == dq5);


    cout << "all tests passed." << endl;
    return 0;

}

