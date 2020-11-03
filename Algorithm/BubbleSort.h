/*
 * @Author: your name
 * @Date: 2020-02-15 17:28:08
 * @LastEditTime: 2020-07-19 13:25:09
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/Algorithm/BubbleSort.h
 */ 
/*

（无序区，有序区）。从无序区通过交换找出最大元素放到有序区前端。

选择排序思路：
1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
3. 针对所有的元素重复以上的步骤，除了最后一个。
4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

*/
#include <assert.h>
#include <vector>

using namespace std;

// 基础冒泡排序
void bubbleSort_Base( int arr[], int len )
{
	assert( arr );
	assert( len );

	int cycles = 0;
	int swapCount = 0;
	// 扫描轮次,最后一项不用扫描
	for (int i = 0; i < len - 1 ; i++)
	{
		// 每轮扫描次数,最后一项不用扫描
		for ( int j = 0; j < len - i - 1; j++)
		{
			// 比较数值
			// 当前项大于后一项就互换,从小到大排序
			// 当前项小于后一项就互换,从大到小排序
			if( arr[j] > arr[ j + 1] )
			{
				std::swap( arr[j], arr[ j + 1]);
				++swapCount;
			}

			++cycles;
		}
	}

	cout << "Cycles : " << cycles << endl;
	cout << "SwapCount : " << swapCount << endl;
}

// 冒泡排序
void BubbleSort(vector<int>& v) {
	int len = v.size();
	for (int i = 0; i < len - 1; ++i)
		for (int j = 0; j < len - 1 - i; ++j)
			if (v[j] > v[j + 1]) 
				swap(v[j], v[j + 1]);
}

// 模板实现冒泡排序
template<typename T> //整數或浮點數皆可使用,若要使用物件(class)時必須設定大於(>)的運算子功能
void bubble_sort(T arr[], int len) {
	for (int i = 0; i < len - 1; i++)
		for (int j = 0; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

// 冒泡排序（改进版）
void BubbleSort_orderly(vector<int>& v) {
	int len = v.size();
	bool orderly = false;
	for (int i = 0; i < len - 1 && !orderly; ++i) {
		orderly = true;
		for (int j = 0; j < len - 1 - i; ++j) {
			if (v[j] > v[j + 1]) {  // 从小到大
				orderly = false;	// 发生交换则仍非有序
				swap(v[j], v[j + 1]);
			}
		}
	}
}

