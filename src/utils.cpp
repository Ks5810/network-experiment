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
#include <vector>

#include "utils.h"

int utils::add(int lhs, int rhs)
{
    if(lhs > INT_MAX - rhs)
        return INT_MAX;
    else
        return lhs + rhs;
}

void utils::printWithSpaceBetween(const string &lhs, int rhs, int width)
{
    width = width / 2 - 1;
    cout << left << setfill(' ') << setw(width) << lhs
         << right << setw(width) << rhs << "\n";
}

void utils::printCentered(string str, int width)
{
    int lhs = 2*width/3, rhs = width/3;
    
    if(width%3 == 1) {
        lhs = width%2 == 0 ? lhs-4 : lhs-3;
        rhs+=4;
        
    } else if(width%3 == 2)
    {
        lhs-=4;
        rhs = width%2 == 0 ? rhs+4 : rhs+1;
    } else
    {
        lhs = width%2 == 0 ? lhs-4 : lhs-3;
        rhs = width%2 == 0 ? rhs+3 : rhs+1;
    }
    
    string tmp { str.empty() ? str : " "s.append(str.append(" ")) };
    
    cout << internal << setfill('-') << setw(lhs) << tmp
         << setw(rhs) << "\n";
}