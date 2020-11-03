/*
 * @Author: your name
 * @Date: 2020-07-19 12:49:51
 * @LastEditTime: 2020-07-20 11:33:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/Algorithm/main.cpp
 */ 

#include <iostream>
#include "BubbleSort.h"     // 冒泡排序
#include "SelectionSort.h"  // 选择排序
#include "BinarySearch.h"   // 二分查找
#include "InsertSort.h"     // 插入排序

using namespace std;

#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));} 

int main( void )
{
    // 共13项
    int arr[] = { 32, 30, 1, 15, 10, 28, 6, 12, 18, 2, 9, 7, 10 };
    double dArr[] = { 32.1, 30.3, 1.5, 15.0, 10.32, 28.91, 6.7, 12.19, 18.2, 2.48, 9.31, 7.77, 10.0 };
    int len = 0;

    vector< int > dataVec { 32, 30, 1, 15, 10, 28, 6, 12, 18, 2, 9, 7, 10 };

    // 获取数组长度,只能在同一代码段使用
    GET_ARRAY_LEN( dArr, len );
    
    // bubbleSort_Base( arr, len );       // 基础冒泡排序
    // BubbleSort( dataVec );             // 容器冒泡排序

    //selectionSort_Base( arr, len );     // 选择排序

    insertionSort( dArr );                 // 插入排序

    for (int i = 0; i < len; i++)
    {
        cout << dArr[i] << " ";
    }
    cout << endl;

    //int value = 30;
    // 二分查找时,数据必须为已排序的(非递归)
    //int res = binarySearch_Base( arr, len , value );

    // 二分查找时,数据必须为已排序的(递归)
    // int res = binarySearch_Recursion( arr, value, 0, len );
    // if ( res < 0 )
    // {
    //     cout << "No find" << endl;
    // }
    // else
    // {
    //     cout << "Value :" << value << " Index " << res << endl;
    // }
    
    return 0;
}