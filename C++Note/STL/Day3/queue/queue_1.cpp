#include <iostream>
#include <deque>
#include <list>
#include <queue>

using namespace std;

int main()
{
    // ==> queue<int, deque<int> >
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    
    while( !q1.empty() )
    {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl << "********************" << endl;
    
    queue<int, list<int> > q2;
    q2.push(1);
    q2.push(2);
    q2.push(3);
    q2.push(4);
    q2.push(5);
    
    while( !q2.empty() )
    {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl << "********************" << endl;
    
    return 0;
}
