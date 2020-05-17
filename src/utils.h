//
// Created by keisuke on 5/15/20.
//

#ifndef NETWORK_UTILS_H_
#define NETWORK_UTILS_H_

using namespace std;

namespace utils
{
    // Checks overflow
    int add( int lhs, int rhs );
    
    void printWithSpaceBetween(const std::string &lhs, int rhs, int=54);
    
    void printCentered(std::string str = "", int=54);
}

#endif //NETWORK_UTILS_H_
