/*******************************************************************************
Title           : csv_row.cpp
Author          : Keisuke Suzuki
Created on      : 5/14/20
Modification    :
*******************************************************************************/

#include "csv_row.h"

string const &CSVRow::operator[](size_t index) const
{
    return m_data[index];
}

size_t CSVRow::size() const
{
    return m_data.size();
}

void CSVRow::readNextRow(istream &str)
{
    string cell;
    string line;
    getline(str, line);
    stringstream lineStream(line);
    
    m_data.clear();
    while(getline(lineStream, cell, ','))
    {
        m_data.push_back(cell);
    }
    // This checks for a trailing comma with no data after it.
    if(! lineStream && cell.empty())
    {
        // If there was a trailing comma then add an empty element.
        m_data.emplace_back("");
    }
}

vector<string> getNextLineAndSplitIntoTokens(istream &str)
{
    vector<string> result;
    string cell;
    string line;
    getline(str, line);
    stringstream lineStream(line);
    
    while(getline(lineStream, cell, ','))
    {
        result.push_back(cell);
    }
    // This checks for a trailing comma with no data after it.
    if(! lineStream && cell.empty())
    {
        // If there was a trailing comma then add an empty element.
        result.emplace_back("");
    }
    return result;
}

istream &operator>>( istream &str, CSVRow &data )
{
    data.readNextRow(str);
    return str;
}
