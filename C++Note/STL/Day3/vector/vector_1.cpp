#include<iostream>
#include<vector>
using namespace std;

void print( const vector<int>& v )
{
    cout << "Capacity : " << v.capacity() << endl; 
    for( int i = 0; i < v.capacity(); i++ )
        cout << v[i] << " ";
    cout << endl;
    
    cout << "Size : " << v.size() << endl;
    for( int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
        
    cout << endl << "********************" << endl; 
}

int main()
{
    vector<int> v1; // cap : 0, size : 0
    print( v1);
    
    
    vector<int> v2(5);  // cap : 5; size: 5; data:0;
    print( v2);
    
    vector<int> v3(5, 10);  // cap:5, size:5; data:10
    print(v3);
    
    v3.push_back( 100 );    // push_back new data 100
    print(v3);              // cap : 10;size:6;data:10,10,10,10,10,100...
    v3.pop_back();
    print( v3 );            // 
    
      
    return 0;
}
