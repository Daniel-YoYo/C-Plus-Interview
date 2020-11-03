/*
 * @Author: your name
 * @Date: 2020-07-02 15:17:49
 * @LastEditTime: 2020-07-02 17:44:35
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/C++Note/C++Base(Tedu)/singleton.cpp
 */ 
/**     单例模式
1、定义
    一个类只能创建一个对象,并提供它的访问方法.

2、实现方法
    (1)禁止在类的外部创建对象: 私有化构造函数
    (2)在类的内部维护唯一对象: 静态成员变量
    (3)提供访问唯一对象的方法: 静态成员函数

3、使用场景
    (1)饿汉式
    无论用于不用,程序启动即创建
    优点：代码实现简单,线程安全,访问率高
    缺点：浪费内存空间(以空间换时间)
    适用场景:单例对象使用频繁,且占用内存小的场景(系统时间管理器)

    (2)懒汉式
    用时再创建,不用了再销毁
    优点：节省内存
    缺点：访问效率相对较低,代码实现相对困难,线程适用不安全(需要加线程同步机制)
    适用场景：单例对象适用频率不高,或所占对象较大的场景(进程管理器)
 */

#include <iostream>

using namespace std;

#define INIT_VALUE 0

// 饿汉式
class SingletonHungry
{
private:

    // 类的内部通过静态成员变量方式,维护唯一对象
    static SingletonHungry s_singletonHungry;

    int m_data;

private:

    // 私有化构造函数,禁止在类的外部创建对象
    SingletonHungry( const int& dataIn = 0 ):m_data( dataIn )
    {
        cout << "Constructor SingletonHungry" << endl;
    }
    
    // 必须私有化拷贝构造函数,只需要声明
    SingletonHungry( const SingletonHungry& that ); 

    ~SingletonHungry()
    {   
        cout << "Destructor SingletonHungry" << endl;
    }
    
public:

    // 提供访问唯一对象的方法
    static SingletonHungry& getIntance()
    {
        return s_singletonHungry;
    }

    int& getValue()
    {
        return m_data;
    }

    void setValue( const int& valueIn )
    {
        m_data = valueIn;
    }

};

// 定义和初始化
SingletonHungry SingletonHungry::s_singletonHungry( INIT_VALUE );

// 懒汉式
class SingletonLazy
{
private:

    int m_data;

    // 使用静态成员变量,维护类的内部唯一对象
    // 必须使用指针变量,初始化指针变量所占内存小到忽略不计,已达到用时创建,节省内存
    static SingletonLazy* sp_singletonLazy;

    // 引用计数,获取对象时自加,销毁对象时自减,当为0时才真正销毁,避免多次销毁风险
    static int useCount;

private:

    // 必须私有化构造函数,以禁止在类的外部创建对象
    SingletonLazy( const int& dataIn = 0 ):m_data( dataIn )    
    {
        cout << "Constructor SingletonLazy" << endl;
    }
    // 必须私有化拷贝构造函数,只需要声明
    SingletonLazy( const SingletonLazy& that );
    ~SingletonLazy()
    {
        cout << "Destructor SingletonLazy" << endl;
    }

public:

    // 提供访问唯一对象的方法
    static SingletonLazy& getInstance()
    {
        // 多线程编程时要加入同步机制,保护唯一静态对象和引用计数
        if( sp_singletonLazy == NULL )
        {
            cout << "Creator SingletonLazy" << endl;
            sp_singletonLazy = new SingletonLazy( INIT_VALUE );
        }

        ++useCount;

        return *sp_singletonLazy;
    }

    // 提供销毁对象方法
    void release()
    {
        // 当引用计数为零时,及最后只有一个使用时才真正销毁
        if( --useCount == 0 )
        {
            cout << "Release SingletonLazy" << endl;
            delete sp_singletonLazy;
            sp_singletonLazy = NULL;
        }
    }

    const int& getValue()
    {
        return m_data;
    }

    void setValue( const int& dataIn )
    {
        m_data = dataIn;
    }

};

// 定义和初始化
SingletonLazy* SingletonLazy::sp_singletonLazy = NULL;
int SingletonLazy::useCount = 0;
    
void hungry()
{   
    cout << "******************** Singleton Hungry ***********************" << endl;
        // 必须引用或指针
    SingletonHungry& sh1 = SingletonHungry::getIntance();
    SingletonHungry& sh2 = SingletonHungry::getIntance();

    sh1.setValue( 123 );
    cout << sh1.getValue() << "\t" << sh2.getValue() << endl;   // 123  123
    cout << &sh1 << "\t" << &sh2 << endl;                       // 地址相同
}

void lazy()
{    
    cout << "******************** Singleton Lazy ***********************" << endl;
    // 必须引用或指针
    SingletonLazy& sl1 = SingletonLazy::getInstance();
    SingletonLazy& sl2 = SingletonLazy::getInstance();

    cout << &sl1 << "\t" << &sl2 << endl;                       // 地址相同
    
    sl1.setValue( 123 );
    cout << sl1.getValue() << "\t" << sl2.getValue() << endl;   // 123  123
    // sl1销毁
    sl1.release();

    sl1.setValue( 100 );
    cout << sl1.getValue() << "\t" << sl2.getValue() << endl;   // 100  100
    // sl1销毁
    sl2.release();
}

int main( void )
{
    hungry();
    lazy();
    
    return 0;
}