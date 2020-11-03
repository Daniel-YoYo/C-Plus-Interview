/*
 * @Author: Daniel_YoYo
 * @Date: 2020-08-01 17:17:19
 * @LastEditTime: 2020-08-02 12:06:07
 * @LastEditors: Please set LastEditors
 * @Description: 
 * 设计一个类模板的顺序栈
 * 功能：有初始化、销毁、判断空、清空、入栈、出栈、取元素的操作。
 * @FilePath: /C++/DataStructure/SeqStack.h
 */ 

#include <iostream>
using namespace std;

template <class T>
class SeqStack
{
    
public:
    SeqStack( const int& sizeIn = 10 );
    ~SeqStack();

    // 入栈
    void push( const T& itemIn );
    // 栈顶
    inline T& top();
    // 出栈
    void pop();
    // 判断栈是否为空
    inline bool isEmpty();
    // 获取栈中数据项大小
    inline const int& size();

private:

    // 改变大小
    void changeSize( const int& desSize );

private:

    T* tptr;            // 动态内存数组指针
    int topIndex;       // 记录栈顶位置
    int capacity;           // 记录栈中数据项大小

};

template <class T>
SeqStack<T>::SeqStack( const int& sizeIn ):capacity( sizeIn )
{
    if ( capacity < 0 )
        throw "SqeStack size must >= 0!";

    tptr = new T[ capacity ];
    topIndex = -1;
}

template <class T>
SeqStack<T>::~SeqStack()
{
    delete[] tptr;
}

// 入栈
template <class T>
void SeqStack<T>::push( const T& itemIn )
{   
    if( topIndex == ( capacity-1) )
    {
        changeSize( capacity*2 );
        capacity*=2;
    }

    tptr[ ++topIndex ] = itemIn;
}

// 栈顶
template <class T>
inline T& SeqStack<T>::top()
{
    if( isEmpty() )
        throw "SeqStack is Empty!";
    return tptr[ topIndex ];
}

// 出栈
template <class T>
void SeqStack<T>::pop()
{
    if( isEmpty() )
        throw "SeqStack is Empty!";
    // 重点：当栈中保存的是类类型数据,需要调用类的析构函数
    tptr[ topIndex-- ].~T();
}

// 判断栈是否为空
template <class T>
inline bool SeqStack<T>::isEmpty()
{
    return topIndex == -1;
}

// 获取栈中数据项大小
template <class T>
inline const int& SeqStack<T>::size()
{
    return capacity;
}

template <class T>
void SeqStack<T>::changeSize( const int& desSize )
{
    if ( desSize < 0 )
        throw "DesSize must >= 0!";
    
    T* tmp = new T[ desSize ];
    int number = min( capacity, desSize );

    // copy只负责复制,不负责申请空间,所以复制前必须有足够的空间
    copy( tptr, tptr+number, tmp );
    delete[] tptr;
    tptr = tmp;
}

int main( void )
{
    SeqStack<int> seqStack;

    seqStack.push( 100 );
    seqStack.push( 101 );
    seqStack.push( 102 );
    seqStack.push( 103 );
    seqStack.push( 104 );
    seqStack.push( 105 );

    seqStack.push( 110 );
    seqStack.push( 111 );
    seqStack.push( 112 );
    seqStack.push( 113 );
    seqStack.push( 114 );
    seqStack.push( 115 );

    seqStack.push( 120 );
    seqStack.push( 121 );
    seqStack.push( 122 );
    seqStack.push( 123 );
    seqStack.push( 124 );
    seqStack.push( 125 );

    cout << seqStack.top() << endl;     // 105
    seqStack.pop();
    cout << seqStack.top() << endl;     // 104
    seqStack.pop();
    cout << seqStack.top() << endl;     // 103
    seqStack.pop();
    cout << seqStack.top() << endl;     // 102
    seqStack.pop();
    cout << seqStack.top() << endl;     // 101
    seqStack.pop();
    cout << seqStack.top() << endl;     // 100
    
    return 0;
}