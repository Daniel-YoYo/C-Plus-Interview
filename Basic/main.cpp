#include "test.h"

Test::Test() : num(0)
{
}

Test::~Test() {}

void Test::function()
{
    num += 1;
    message = "Hello world!";
    std::cout << num << std::endl;
    std::cout << message << std::endl;
}

int main()
{
    Test test;
    test.function();

    std::cin.get();
    return 0;
}