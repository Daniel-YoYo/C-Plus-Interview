/*
 * @Author: your name
 * @Date: 2020-07-13 10:22:54
 * @LastEditTime: 2020-07-13 10:25:33
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/C++Note/C++Base(Tedu)/exception.cpp
 */ 
#include <iostream>
#include <exception>

using namespace std;

class ExTest
{
private:

public:

    ~ExTest()
    {
        throw -1;
    }
};

int main( void )
{

    try
    {
        ExTest t;
    }
    catch( int ex )
    {
        std::cerr << " 捕获到异常:" << ex << '\n';
    }
    

    return 0;
}
