/*
 * @Author: your name
 * @Date: 2020-02-15 17:28:08
 * @LastEditTime: 2020-07-19 15:13:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/Algorithm/BinarySearch.h
 */ 
// 二分查找（折半查找）：对于已排序，若无序，需要先排序
#include <vector>
#include <assert.h>

using namespace std;

int binarySearch_Base( const int (&arr)[], const int& len, const int& value )
{
	assert( arr );
	assert( len );

	int left = 0, right = len - 1, midIndex = 0;
	while ( left <= right )
	{
		midIndex = left + ( right - left )/2;
		if( arr[ midIndex ] == value )
		{
			return midIndex;
		}
		else if ( value > arr[ midIndex ] )
		{
			left = midIndex + 1;
		}
		else
		{
			right = midIndex - 1;
		}
		
	}
	
	// 未找到
	return -1;
}

int binarySearch_Recursion( const int (&arr)[], const int& value, int left, int right )
{
	if ( left > right )
	{
		return -1;
	}
	
	int midIndex = left + ( right - left )/2;
	if( arr[ midIndex ] == value )
	{
		return midIndex;
	}
	else if ( value > arr[ midIndex ] )
	{
		return binarySearch_Recursion( arr, value, midIndex + 1, right );
	}
	else
	{
		return binarySearch_Recursion( arr, value, left, midIndex - 1 );
	}
}

// 非递归
int BinarySearch(vector<int> v, int value , int low, int high) {
	if (v.size() <= 0) {
		return -1;
	}
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (v[mid] == value) {
			return mid;
		}
		else if (v[mid] > value) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return -1;
}

// 递归
int BinarySearch2(vector<int> v, int value, int low, int high)
{
	if (low > high)
		return -1;
	int mid = low + (high - low) / 2;
	if (v[mid] == value)
		return mid;
	else if (v[mid] > value)
		return BinarySearch2(v, value, low, mid - 1);
	else
		return BinarySearch2(v, value, mid + 1, high);
}
