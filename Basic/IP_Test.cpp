/*
 * @Author: your name
 * @Date: 2020-08-17 09:22:20
 * @LastEditTime: 2020-08-17 09:30:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/Basic/IP_Test.cpp
 */
// 大小端测试
#include <iostream>

using namespace std;

int main( void )
{

    union {
        unsigned int un;
        unsigned char uc[4];

    };

    un = 0x12345678;

    for (int i = 0; i < 4; i++)
    {
        printf("%#x\t%p\n", uc[i], &uc[i]);
    }
    
    

    if ( uc[3] == 78 )
    {
        cout << "Big" << endl;
    }
    else
    {
        cout << "Small" << endl;
    }
    
    return 0;
}
