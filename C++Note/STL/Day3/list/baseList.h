#ifndef BASELIST_H
#define BASELIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template<class T>
class MyList
{   
    // 节点类
    class Node
    {
        public:
            Node( const T& dataIn, Node* prevIn = NULL, Node* nextIn = NULL ):
                data( dataIn), prev( prevIn ), next( nextIn ){}

            Node* prev;
            Node* next;
            T data;
    };

private:

    Node* head;     // 头结点
    Node* tail;     // 尾节点

public:
    // 无参构造函数
    MyList():head( NULL ), tail( NULL ){}

    // 拷贝构造函数
    MyList( const MyList& that ):head( NULL ), tail( NULL )
    {        
        for (Node* pnode = that.head; pnode; pnode = pnode->next )
        {
            push_back( pnode->data );
        }
    }

    // 析构函数
    ~MyList()
    {
        clear();
    }

public:
    // 重载输出流操作符
    friend ostream& operator <<(ostream& os, const MyList<T>& list)
    {
        for (Node* pnode = list.head; pnode; pnode = pnode->next )
        {
            os << pnode->data << " ";
        }
        return os;
    }

    // 往尾部添加节点
    void push_back( const T& dataIn )
    {
        tail = new Node( dataIn, tail, NULL );

        // 判断是否有前节点
        if ( tail->prev == NULL )
            head = tail;
        else
            tail->prev->next = tail;
    }

    // 从尾部删除节点
    void pop_back()
    {
        if ( isEmpty() )
            return;

        Node* pnode = tail->prev;
        delete tail;

        // 判断是否有前节点
        if ( pnode  == NULL )
            head = NULL;
        else
            pnode->next = NULL;

        tail = pnode;   
    }

    // 往头部添加节点
    void push_front( const T& dataIn )
    {
        head = new Node( dataIn, NULL, head );

        if( head->next == NULL )
            tail = head;
        else
            head->next->prev = head;   
    }
    
    // 从头部删除节点
    void pop_front()
    {
        if( isEmpty() )
            return;

        Node* pnode = head->next;
        delete head;

        if ( pnode == NULL )
            tail = NULL;
        else
            pnode->prev = NULL;
        
        head = pnode;
    }

    // 获取头节点数据
    const T& front() const
    {
        // 去常属性调用
        return const_cast<MyList*>( this )->front();
    }

    T& front()
    {
        if ( isEmpty() )
            throw underflow_error( " front() ");
        
        return head->data;
    }

    // 获取尾节点数据
    const T& back() const
    {
        // 去常属性调用
        return const_cast<MyList*>( this )->back();
    }

    T& back()
    {
        if ( isEmpty() )
            throw underflow_error( " back()");
        
        return tail->data;
    }

    // 判断链表是否为空
    bool isEmpty()
    {
        return head == NULL && tail == NULL;
    }

    // 清空链表
    void clear()
    {
        while ( !isEmpty() )
            pop_front();    
    }

    // 获取链表大小
    size_t size()
    {
        size_t size = 0;
        for ( Node* pnode = head; pnode; pnode = pnode->next )
            size++;
         
        return size;
    }
};

#endif