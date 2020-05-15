/*******************************************************************************
Title           : utils.cpp
Author          : Keisuke Suzuki
Created on      : 5/14/20
Modification    :
*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <climits>
#include <string>

#include "utils.h"

int utils::add( int lhs, int rhs )
{
    if(lhs > INT_MAX - rhs)
        return INT_MAX;
    else
        return lhs + rhs;
}

void utils::printLogHeader( std::string &str, char separator, int width )
{
    std::cout << "in printLogHeader()\n";
}
