/*******************************************************************************
Title           : csv_row.h
Author          : Keisuke Suzuki
Created on      : 5/14/20
Modification    :
*******************************************************************************/
#ifndef NETWORK_CSV_ROW_H_
#define NETWORK_CSV_ROW_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class CSVRow
{
    public:
    string const &operator[]( size_t index ) const;
    
    [[nodiscard]] size_t size() const;
    
    void readNextRow( istream &str );
    
    private:
    vector<string> m_data;
};

vector<string> getNextLineAndSplitIntoTokens( istream &str );

istream &operator>>( istream &str, CSVRow &data );


#endif //NETWORK_CSV_ROW_H_
