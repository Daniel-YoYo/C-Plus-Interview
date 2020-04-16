#ifndef _STATIC_H
#define _STATIC_H

#include <cstring>
#include <iostream>

using namespace std;

static int num = 15;

class Static
{
    static int age;
    std::string name;

public:

    static void getInfo();

    Static();

    void setInfo( int ageIn, string nameIn );

};

#endif