/*
 * @Author: your name
 * @Date: 2020-07-19 15:58:45
 * @LastEditTime: 2020-07-19 16:57:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/Algorithm/Permutations.cpp
 */ 
/**         Permutations 排列组合
 *  笔试题: 
 *      给定一组字符串,例如"abc",计算出所有的排列组合
 *  输出:   
 *      abc  acb
 *      bac  bca
 *      cba  cab
 */
#include <iostream>
#include <assert.h>

using namespace std;

#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));} 

int len = 0;

void permutations_Str( char* str, int beginIndex, int endIndex )
{
    assert( str );
    assert( endIndex );

    // 排列完成
    if( beginIndex == endIndex )
    {
        for (int i = 0; i <=endIndex; i++)
        {
            cout << str[i];
        }

        if ( endIndex < len )
        {
            for (int i = endIndex+1; i < len; i++)
            {
                cout << str[i];
            }
        }
        cout << endl;        
    }

    for (int i = beginIndex; i <= endIndex; i++)
    {
        // 
        swap( str[beginIndex], str[i] );
        permutations_Str( str, beginIndex+1, endIndex);
        swap( str[beginIndex], str[i] );
    }
}


int main( void )
{

    char arr[] = "abcde";

    GET_ARRAY_LEN( arr, len );

    permutations_Str( arr, 0, 2 );

    return 0;
}


