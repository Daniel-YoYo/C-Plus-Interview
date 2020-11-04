#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

template<class T>
void print( const string& str, deque<T>& dq)
{
    cout << str << endl;
    
    typedef typename deque<T>::iterator IT;    
    for( IT it = dq.begin(); it != dq.end(); ++it)
        cout << *it << " ";
    
    cout << endl << "***********************" << endl;
}

template<class T>
class Comparetor
{
  public:
    bool operator()( const T& a, const T& b )
    {
        return a > b;
    }  
    
};

int main()
{
    deque<int> dq1;
    for( int i = 0; i < 5; i++)
        dq1.push_front( 10 - i);
    print( "deque push_front : ", dq1 );    
    
    for( int i = 0; i < 5; i++)
        dq1.push_back( i );
    print( "deque push_back : ", dq1 );            
    
    dq1.pop_back();
    dq1.pop_front();
    print("deque pop_back/front : ", dq1);
    
    dq1.insert( dq1.begin(), 100);
    dq1.insert( dq1.end(), 100);
    print("deque insert begin/end : ", dq1);
    
    deque<int>::iterator fit = find(dq1.begin(), dq1.end(), 0);
    if( fit != dq1.end() )
        dq1.erase( fit );
    print("deque find 0 and erase : ", dq1);
    
    
    sort( dq1.begin(), dq1.end() );
    print( "deque sort : ", dq1);
    
    Comparetor<int> cmp;
    sort( dq1.begin(), dq1.end(), cmp);
    print( "deque sort : ", dq1);
    
    return 0;  
}
