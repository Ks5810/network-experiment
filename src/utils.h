//
// Created by keisuke on 5/15/20.
//

#ifndef NETWORK_UTILS_H_
#define NETWORK_UTILS_H_

namespace utils
{
    // Checks overflow
    int add( int lhs, int rhs );
    
    void printLogHeader(std::string &str, char separator, int width);
}

#endif //NETWORK_UTILS_H_
