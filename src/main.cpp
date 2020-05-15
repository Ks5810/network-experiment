/*******************************************************************************
Title           : main.cpp
Author          : Keisuke Suzuki
Created on      : 5/14/20
Modification    :
*******************************************************************************/
#include <iomanip>
#include "iostream"

#include "graph.h"
#include "csv_row.h"

using namespace std;

int main( int argc, char *argv[] )
{
    if(argc != 2)
    {
        cout << "Usage:\t" << argv[0] << " <filename>\n";
    }
    else
    {
        ifstream file1(argv[1]);
        Graph graph1(file1);
        
        // Run bellman Ford
        string source = "b-ford";
        graph1.bellmanFord(source);
        
        file1.close();
        
        
    }
    
    return 0;
}