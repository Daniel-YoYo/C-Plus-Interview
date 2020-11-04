#ifndef BASELIST_H
#define BASELIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template<class T>
class MyList
{ 

public:

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

    /************** 普通迭代器类 *******************/
    class Iterator
    {
        public:
            Iterator( Node* begin = NULL, Node* end = NULL, Node* current = NULL ):
                it_begin( begin ), it_end( end ), it_current( current ){}

            // 解引用操作
            T& operator*()
            {
                if ( it_current == NULL )
                    throw underflow_error( "operator*" );
                
                return it_current->data;
            }

            // 后++操作
            Iterator& operator++()
            {
                if ( it_current == NULL )
                    it_current = it_begin;
                else
                    it_current = it_current->next;
                  
                return *this;
            }

            // 后--操作
            Iterator& operator--()
            {
                if ( it_current == NULL )
                    it_current = it_end;
                else
                    it_current = it_current->prev;
                
                return *this;
            }

            // ==比较操作
            bool operator==( const Iterator& that )
            {
                return this->it_current == that.it_current;
            }

            // !=比较操作
            bool operator!=( const Iterator& that )
            {
                return !operator==( that );
            } 

        private:
            Node* it_begin;
            Node* it_current;
            Node* it_end;

            // 声明为友元类后,可访问类中私有成员
            friend class MyList;
    };

    /**************** 常迭代器类 *********************/
    class const_Iterator
    {   
        Iterator it;

    public:
        const_Iterator( const Iterator& itIn ):it( itIn ){}

        const T& operator*()
        {
            return *it;
        }

        const_Iterator& operator++()
        {
            ++it;
            return *this;
        }

        bool operator==( const const_Iterator& that ) const
        {
            return it == that.it;
        }

        bool operator!=( const const_Iterator& that ) const
        {
            return !( *this == that );
        }
    };

public:

    /**************** 常迭代器 *********************/
    // 获取起始迭代器
    const_Iterator begin() const
    {
        return Iterator( head, tail, head );
    }

    // 获取终止迭代器
    const_Iterator end() const
    {
        return Iterator( head, tail, NULL );
    }

    /************** 普通迭代器 *******************/
    // 获取起始迭代器
    Iterator begin()
    {
        return Iterator( head, tail, head );
    }

    // 获取终止迭代器
    Iterator end()
    {
        return Iterator( head, tail, NULL );
    }

    // 在迭代器指向的位置添加节点,让迭代器的当前节点指向新添加的节点
    Iterator insert( Iterator localIt, const T& data )
    {
        // 如果当前迭代器为终止迭代器
        if ( localIt == end() )
        {   
            // 直接在尾部添加节点
            push_back( data );
            return Iterator( head, tail, tail );
        }
        else
        {
            // 新节点
            Node* pnode = new Node( data, localIt.it_current->prev, localIt.it_current );

            // 判断新节点的前节点是否有效
            if ( pnode->prev )
                pnode->prev->next = pnode;  // 让前节点的下一个节点指针指新节点
            else
                head = pnode;   // 无前节点,新节点就是头节点

            pnode->next->prev = pnode;  // 让新节点的下个节点的前指针指向新节点

            return Iterator( head, tail, pnode );
        }
    }

    // 删除迭代器指定的节点
    Iterator erase( Iterator localIt )
    {
        if ( localIt == end() )
            throw underflow_error( "erase end Iterator" );
        
        Node* pdel = localIt.it_current;
        Node* pnext = localIt.it_current->next;

        //　判断需要删除的节点是否有前节点
        if ( pdel->prev )
            pdel->prev->next = pdel->next;  // 有前节点,让前节点的next节点指针指向删除节点的下一个节点
        else
            head = pdel->next;  // 无前节点,设置头结点

        // 判断需要删除的节点是否有后节点
        if ( pdel->next )
            pdel->next->prev = pdel->prev;
        else
            tail = pdel->prev;
        
        // 删除节点
        delete( pdel );
        pdel = NULL;

        // 返回新的迭代器
        return Iterator( head, tail, pnext );
    }

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
    // friend ostream& operator <<(ostream& os, const MyList<T>& list)
    // {
    //     for (Node* pnode = list.head; pnode; pnode = pnode->next )
    //     {
    //         os << pnode->data << " ";
    //     }
    //     return os;
    // }

    //　 往尾部添加节点
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

// 全局查找函数
template <class Iterator, class T>
Iterator find( Iterator begin, Iterator end, const T& data )
{
    for (Iterator it = begin; it != end; ++it)
    {
        if ( *it == data )
            return it;
    }

    return end;    
}

// 迭代器使用快排对链表进行排序
/*************　四步骤  **************
 * 1 p和谁相同谁不动
 * 2 p和谁交换数据,最终p和谁相同
 * 3 当p, i, j都相同,指向的那个数据位置确定
 * 4 递归
 * **********************************/

// 使用操作符'<'实现
template<class Iterator>
void sort( Iterator begin, Iterator end )
{
    Iterator p = begin;
    Iterator last = end;
    --last;

    for ( Iterator i = begin, j = last; i != j;)
    {
        while ( i != p && *i < *p )
            ++i;

        if ( i != p )
        {
            swap( *i, *p );
            p = i;
        }
        
        while ( j != p && *p < *j )
            --j;
        if ( j !=p )
        {
            swap( *p, *j );
            p = j;
        }   
    }

    // 
    Iterator it = begin;
    ++it;
    if ( p != begin && p != it )
        sort( begin, p );

    it = p;
    ++it;

    if ( it != end && it != last )
        sort( it, end );
}

template<class T>
class Comparator
{
    bool isPositive;
    public:

        Comparator( bool isPositiveIn = true ):isPositive( isPositiveIn ){}

        bool operator()( const T& a, const T& b  )
        {   
            if( isPositive )
                return a < b;
            else
                return a > b;
        }
};

// class Comparator 比较器
template<class Iterator, class Comparator>
void sort( Iterator begin, Iterator end, Comparator cmp )
{
    Iterator p = begin;
    Iterator last = end;
    --last;

    for ( Iterator i = begin, j = last; i != j;)
    {
        while ( i != p && cmp(*i, *p) )
            ++i;

        if ( i != p )
        {
            swap( *i, *p );
            p = i;
        }
        
        while ( j != p && cmp( *p, *j) )
            --j;
        if ( j !=p )
        {
            swap( *p, *j );
            p = j;
        }   
    }

    // 
    Iterator it = begin;
    ++it;
    if ( p != begin && p != it )
        sort( begin, p );

    it = p;
    ++it;

    if ( it != end && it != last )
        sort( it, end );

}

#endif