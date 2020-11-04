#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>

using namespace std;

class Student
{
    string m_name;
    int m_age;
public:
    Student( const string& name = "", const int& age = 0 ):
        m_name( name), m_age( age)
    {
        cout << " Constructor : " << m_name << " " << m_age << endl;
    }
    
    Student( const Student& that ):m_name( that.m_name), m_age( that.m_age )
    {
        cout << " Copy Constructor : " << that.m_name << "( " << &that << " )====>" \
            << m_name << "( " << this << " )" << endl;
    }
    
    ~Student()
    {
        cout << " Destructor : " << m_name << "( " << this << " )" << endl;
    }
};

int main()
{
    vector<Student> s1;
    s1.reserve( 3 );
    s1.push_back( Student( "one", 1) );
    cout << "****************************" << endl;
    s1.push_back( Student( "two", 2) );
    cout << "****************************" << endl;
    s1.push_back( Student( "three", 3) );
    cout << "****************************" << endl;
      
    getchar();
    return 0;
}
