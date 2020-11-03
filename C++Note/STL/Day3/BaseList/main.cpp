/*
 * @Author: your name
 * @Date: 2020-09-05 00:23:41
 * @LastEditTime: 2020-10-27 23:40:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/C++Note/STL/Day2/BaseList/main.cpp
 */
#include "list_iterator.h"
#include <iostream>
using namespace std;

void print( string str, MyList<int>& list )
{
    cout << str << endl;

    for ( MyList<int>::Iterator it = list.begin(); it != list.end(); ++it )
    {
        cout << *it << " ";
    }
    
    cout << endl << "*************************" << endl;
}

int main( void )
{
    MyList<int> list;
    list.push_back( 1 );
    list.push_back( 2 );
    list.push_back( 3 );
    list.push_back( 4 );
    list.push_back( 5 );
    list.push_back( 6 );
    list.push_back( 7 );
    list.push_back( 8 );
    list.push_back( 9 );
    list.push_back( 10 );
    print("List Member :", list );

    list.pop_back();
    print("pop_back :", list );

    list.push_front( -1 );
    print("push_front -1 :", list );

    list.pop_front();
    print("pop_front :", list );

    list.back() = 100;
    print("back :", list );

    list.front() = 100;
    print("front :", list );

    list.insert( list.begin(), 25 );
    print( "Insert Data from Head : ", list );
    list.erase( list.begin() );
    print( "Erase Data from Tail : ", list );

    MyList<int>::Iterator fit = find( list.begin(), list.end(), 6 );
    if( fit != list.end() )
    {
        // 成功找到
        list.erase( fit );  // 删除
    }
    print( "Find Data and Erase from List : ", list );

    return 0;
}