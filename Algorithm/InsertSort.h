/*
 * @Author: your name
 * @Date: 2020-02-15 17:28:08
 * @LastEditTime: 2020-07-20 16:44:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/Algorithm/InsertSort.h
 */ 
/*

（有序区，无序区）。把无序区的第一个元素插入到有序区的合适的位置。对数组：比较得少，换得多。

插入排序思路：
1. 从第一个元素开始，该元素可以认为已经被排序
2. 取出下一个元素，在已经排序的元素序列中从后向前扫描
3. 如果该元素（已排序）大于新元素，将该元素移到下一位置
4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
5. 将新元素插入到该位置后
6. 重复步骤2~5

*/
#include <vector>

// 插入排序
void InsertSort(vector<int>& v)
{
    int len = v.size();
	for (int i = 1; i < len; ++i) {
		int temp = v[i];
        for(int j = i - 1; j >= 0; --j)
        {
            if(v[j] > temp)
            {
                v[j + 1] = v[j];
                v[j] = temp;
            }
            else
                break;
        }
	}
}

// 插入排序,函数模板形式
// T是类型参数，N是非类型参数
// 数组引用做函数形参时：(1)需要给形参指定长度,(2)或者增加非类型参数N
template < typename T, size_t N>
void insertionSort( T (&arr)[ N ] )
{
    int inIndex, outIndex;
    int len = sizeof( arr )/ sizeof( arr[0] );

    // 从第一项元素开始,因为当只有一项元素时,其顺序大小时确定的
    for ( outIndex = 1; outIndex < len; outIndex++)
    {
        // 临时变量
        T tmp = arr[ outIndex ];
        inIndex = outIndex;

        // 循环比较
        // 当inIndex = 1, 第0项大于或等于第1项,互换位置,将小的第0赋值到0项
        while ( ( inIndex > 0 ) && ( arr[ inIndex - 1 ] >= tmp ) )
        {
            // 内层循环,当比较为真时,前一项较大的元素覆盖当前项较小的元素
            arr[ inIndex ] = arr[ inIndex - 1 ];
            // 当前项索引自减,继续和前一项进行比较
            --inIndex;
        }
        // 最后找到当前临时变量所在的数组索引,并赋值
        arr[ inIndex ] = tmp;
    }
}