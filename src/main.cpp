/*******************************************************************************
Title           : main.cpp
Author          : Keisuke Suzuki
Created on      : 5/14/20
Modification    :
*******************************************************************************/
#include "iostream"

#include "graph.h"
#include "csv_row.h"

using namespace std;

int main( int argc, char *argv[] )
{
    int return_value = 0;
    if(argc > 3)
    {
        cout << "Usage:\t" << argv[0] << " <filename>\n";
    }
    else
    {
        ifstream file1(argv[1]);
        string source = argv[2];
        Graph graph1(file1);
    
        // Run bellman Ford
        return_value = graph1.bellmanFord(source);
        
        file1.close();
    }
    
    return return_value;
}