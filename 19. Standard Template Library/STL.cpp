#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

int main(void)
{
    /*********** VECTOR ***********/
    vector<int> v;
    cout << "Vector size = " << v.size() << endl;
    v.push_back(4);
    v.push_back(6);
    v.push_back(4);
    v.push_back(6);
    cout << "Extended vector size = " << v.size() << endl;

    while(!v.empty()) {
        cout << v.back() << " ";
        v.pop_back();
    }
    cout << endl << endl;


    /*********** LIST ***********/
    list<int> li;
    for(int i = 0; i < 5; i++)
        li.push_back(i);
    list<int>::const_iterator pos;
    for(pos = li.begin(); pos != li.end(); pos++)
        cout << *pos << " ";
    cout << endl << endl;


    /*********** QUEUE ***********/
    queue<int> q;
    q.push(6);
    q.push(7);
    q.push(3);
    q.push(2);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl << endl;


    /*********** STACK ***********/
    stack<char> s;
    s.push('s');
    s.push('i');
    s.push('m');
    s.push('p');
    s.push('l');
    s.push('e');

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl << endl;

    return 0;
}
