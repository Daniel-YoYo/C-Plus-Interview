/*
 * @Author: your name
 * @Date: 2020-08-02 10:31:06
 * @LastEditTime: 2020-08-02 14:20:26
 * @Description: 
 *  设计一个类模板的顺序队列
 *  主要操作：Push/Pop/Front/Rear/IsEmpty
 *  应用场景: 线程池的工作队列
 */ 

#include <iostream>
using namespace std;


template <class T>
class SeqQueue
{

public:
    SeqQueue( const int& queueCapIn = 10 );
    ~SeqQueue();

    // 判断是否为空
    inline bool isEmpty();
    // 获取队首数据
    T& front();
    // 获取队尾数据
    T& rear();
    // 入队
    void push( const T& itemIn );
    // 出队
    void pop();

    // 队列大小
    const int& size();
    
private:
    T* queuePtr;    // 顺序队列数组指针
    int frontIndex; // 队首下标
    int rearIndex;  // 队尾下标
    int capacity;   // 队列大小

};

template <class T>
SeqQueue<T>::SeqQueue( const int& queueCapIn ):capacity( queueCapIn ), frontIndex( 0 ), rearIndex( 0 )
{
    if ( queueCapIn < 1 )
        throw "SeqQueue must > 0!";
    
    queuePtr = new T[ capacity ];
}

template <class T>
SeqQueue<T>::~SeqQueue()
{
    delete[] queuePtr;
}

// 判断是否为空
template <class T>
inline bool SeqQueue<T>::isEmpty()
{
    return ( frontIndex == rearIndex ) ? true : false;
}

// 获取队首数据
template <class T>
T& SeqQueue<T>::front()
{   
    // 判断是否为空
    if( isEmpty() )
        throw "SeqQueue is Empty!";
        
    // 判断是否发生回环,并返回数据项,队首默认为空
    return queuePtr[ (frontIndex + 1) % capacity ];
}

// 获取队尾数据
template <class T>
T& SeqQueue<T>::rear()
{
    // 判断是否为空
    if( isEmpty() )
        throw "SeqQueue is Empty!";
        
    // 获取队尾数据
    return queuePtr[ rearIndex ];
}

// 入队
template <class T>
void SeqQueue<T>::push( const T& itemIn )
{
    // 如果队列满了
    if( ( rearIndex + 1)%capacity == frontIndex )
    {
        // 容量加倍
        T* newQueuePtr = new T[ capacity * 2 ];
        int startIndex = ( frontIndex + 1 )%capacity;

        // 分两种情况
        // 2:表示当队列满了时,队首下标只有大于>=2时才会发生回环
        if( startIndex < 2 )    // 未发生回环   |F|S|2|2|2|2|2|R| 
        {
            cout << "Unloopback" << endl;
            std::copy( queuePtr+startIndex, queuePtr+startIndex+capacity-1, newQueuePtr );
        }
        else                    // 发生了回环  |R|F|S|2|2|2|2|2|
        {
            cout << "Loopback" << endl;
            std::copy( queuePtr+startIndex, queuePtr+capacity, newQueuePtr);
            std::copy( queuePtr, queuePtr + rearIndex + 1, newQueuePtr+capacity-startIndex );
        }

        // 容量加倍后设置队首下标
        frontIndex = capacity*2 - 1;
        rearIndex = capacity - 2;
        capacity *= 2;

        delete[] queuePtr;
        queuePtr = newQueuePtr;
    }

    // 此写法可以适用回环情况下的确认队尾下标
    rearIndex = (rearIndex + 1)%capacity;
    queuePtr[ rearIndex ] = itemIn;

}

// 出队
template <class T>
void SeqQueue<T>::pop()
{
    // 判断是否为空
    if( isEmpty() )
        throw "SeqQueue is Empty!";

    // 从队首删除数据,次写法可以适用回环情况下的确认队首下标
    frontIndex = ( frontIndex + 1) % capacity;
    queuePtr[ frontIndex ].~T();
}

template <class T>
const int& SeqQueue<T>::size()
{
    return capacity;
}

int main( void )
{
    SeqQueue<int> seqQueue;

    seqQueue.push( 100 );
    seqQueue.push( 101 );
    seqQueue.push( 102 );
    seqQueue.push( 103 );
    seqQueue.push( 104 );
    seqQueue.push( 105 );
    cout << "SeqQueue Size " << seqQueue.size() << endl;
    
    seqQueue.push( 110 );
    seqQueue.push( 111 );
    seqQueue.push( 112 );
    seqQueue.push( 113 );
    seqQueue.push( 114 );
    seqQueue.push( 115 );
    cout << "SeqQueue Size " << seqQueue.size() << endl;

    seqQueue.push( 120 );
    seqQueue.push( 121 );
    seqQueue.push( 122 );
    seqQueue.push( 123 );
    seqQueue.push( 124 );
    seqQueue.push( 125 );
    cout << "SeqQueue Size " << seqQueue.size() << endl;
    
    cout << seqQueue.front() << "\t" << seqQueue.rear() << endl;
    seqQueue.pop();
    cout << seqQueue.front() << "\t" << seqQueue.rear() << endl;
    seqQueue.pop();
    cout << seqQueue.front() << "\t" << seqQueue.rear() << endl;
    seqQueue.pop();
    cout << seqQueue.front() << "\t" << seqQueue.rear() << endl;
    seqQueue.pop();
    cout << seqQueue.front() << "\t" << seqQueue.rear() << endl;
    seqQueue.pop();
    cout << seqQueue.front() << "\t" << seqQueue.rear() << endl;
    
    return 0;
}