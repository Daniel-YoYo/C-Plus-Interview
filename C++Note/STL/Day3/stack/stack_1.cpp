#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <stack>

using namespace std;

int main()
{
    // ==> stack<int, deque<int> >
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    
    while( !s1.empty() )
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl << "********************" << endl;
    
    stack<int, vector<int> > s2;
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);
    s2.push(5);
    
    while( !s2.empty() )
    {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl << "********************" << endl;
    
    stack<int, list<int> > s3;
    s3.push(1);
    s3.push(2);
    s3.push(3);
    s3.push(4);
    s3.push(5);
    
    while( !s3.empty() )
    {
        cout << s3.top() << " ";
        s3.pop();
    }
    cout << endl << "********************" << endl;
    
    return 0;
}
