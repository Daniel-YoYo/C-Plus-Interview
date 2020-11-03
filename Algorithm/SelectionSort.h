/*
 * @Author: your name
 * @Date: 2020-02-15 17:28:08
 * @LastEditTime: 2020-07-19 13:46:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/Algorithm/SelectionSort.h
 */ 
/*

（有序区，无序区）。在无序区里找一个最小的元素跟在有序区的后面。对数组：比较得多，换得少。

选择排序思路：
1. 在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
2. 从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾
3. 以此类推，直到所有元素均排序完毕

*/

#include <vector>
#include <assert.h>

using namespace std;

void selectionSort_Base( int* arr, int len )
{
	assert( arr );
	assert( len );

	int minIndex, cycles = 0, swapCount = 0;

	for (int i = 0; i < len - 1; i++)
	{
		minIndex = i;

		for (int j = i + 1; j < len; j++ )
		{	
			// 通过进行比较,记录最小值下标
			if ( arr[j] < arr[ minIndex ] )
			{
				minIndex = j;
			}
			++cycles;
		}
		
		if ( i != minIndex)
		{
			swap( arr[i], arr[ minIndex ] );
			++swapCount;
		}
	}
	
	cout << "Cycles : " << cycles << endl;
	cout << "SwapCount : " << swapCount << endl;	
}

// 选择排序
void SelectionSort(vector<int>& v) {
	int min, len = v.size();
	for (int i = 0; i < len - 1; ++i) {
		min = i;
		for (int j = i + 1; j < len; ++j) {
			if (v[j] < v[min]) {    // 标记最小的
				min = j;
			}
		}
		if (i != min)  // 交换到前面
			swap(v[i], v[min]);
	}
}

// 模板实现
template<typename T> 
void Selection_Sort(std::vector<T>& arr) {
	int len = arr.size();
	for (int i = 0; i < len - 1; i++) {
		int min = i;
		for (int j = i + 1; j < len; j++)
			if (arr[j] < arr[min])
				min = j;
		if(i != min)
			std::swap(arr[i], arr[min]);
	}
}