#include "static.h"

void Static::getInfo()
{
    std::cout << "Static Function" << std::endl;
}

Static::Static()
{
    age = 0;
}

void Static::setInfo( int ageIn, string nameIn )
{
    age = ageIn;
    name = nameIn;

    std::cout << "Name:" << name << std::endl;
    std::cout << " Age:" << age << std::endl;
}