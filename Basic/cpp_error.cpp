// C++　异常( Exception )
// 结合Ｃ语言的两种传统错误处理的优点、同时避免了Ｃ语言错误处理的缺点.
// 在形式上实现一步到位的错误处理, 同时保证所有的局部对象可以得到正确的析构.
#include <iostream>
#include <cstdio>

using namespace std;

class Error
{

public:
    Error(const string &errorStrIn, const int &errorNumIn)
    {
        errorStr = errorStrIn;
        errorNum = errorNumIn;
        cout << "Error : Constructor" << endl;
    }

    ~Error()
    {
        cout << "Error : Destructor" << endl;
    }

    string getErrrorStr()
    {
        return errorStr;
    }

    int getErrorNum()
    {
        return errorNum;
    }

    string errorStr;
    int errorNum = 0;
};

class A
{

public:
    A(void)
    {
        cout << "A : Constructor" << endl;
    }

    ~A()
    {
        cout << "A : Destructor" << endl;
    }
};

int func3(void)
{
    FILE *fp = fopen("none.txt", "r");
    if (fp == NULL)
    {
        // 抛出异常,当前栈区对象被正常析构
        throw Error("Func3 Open File Failed!", __LINE__ );
        // 如果抛出异常,后面的代码都不执行
        cout << "C++ Exception Test!" << endl;
    }

    fclose(fp);
    return 0;
}

int func2(void)
{
    A a;
    func3();
    // 如果抛出异常,后面的代码都不执行
    cout << "func2 Exception Test!" << endl;

    return 0;
}

int func1(void)
{
    A *a = new A;
    func2();
    // 如果抛出异常,后面的代码都不执行
    cout << "func1 Exception Test!" << endl;
    return 0;
}

int main(void)
{
    try
    {
        // 检测异常
        func1();
    }

    // 捕获异常
    catch (const Error &error)
    {
        // 异常处理部分
        cout << __FILE__ << ". Line:" << error.errorNum << " : " << error.errorStr << endl;
        return -1;
    }

    return 0;
}