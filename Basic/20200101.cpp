#include <iostream>
using namespace std;

template <class T>
T add(T a, T b, T c)
{
    return a + b + c;
}

int main()
{

    float a = 0.0, b = 0.0, c = 0.0;
    cout << "Hello 2020!" << endl;
    cin >> a >> b >> c;
    cout << add(a, b, c ) << endl;
    
    return 0;
}