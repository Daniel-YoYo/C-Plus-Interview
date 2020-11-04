#include <iostream>
#include <queue>

using namespace std;

template<class T>
class Comparetor
{
    public:
        bool operator()( const T& a, const T& b)
        {
            return a > b;
        }

};

int main()
{
    priority_queue<int, vector<int>, Comparetor<int> > pq;
    pq.push( 9 );
    pq.push( 1 );
    pq.push( 3 );
    pq.push( 2 );
    pq.push( 5 );
    pq.push( 4 );

    while ( !pq.empty() )
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << endl;

    return 0;
    
}