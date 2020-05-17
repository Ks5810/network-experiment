/*******************************************************************************
Title           : graph.h
Author          : Keisuke Suzuki
Created on      : 5/14/20
Modification    :
*******************************************************************************/
#ifndef NETWORK_GRAPH_H_
#define NETWORK_GRAPH_H_

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <list>
#include <climits>

#include "utils.h"
#include "csv_row.h"

using namespace std;
using GraphType = unordered_map<string, list<pair<string, int>>>;

class Graph
{
    public:
    Graph();
    explicit Graph(ifstream &file);
    int getNumEdges();
    void clear();
    void bellmanFord(string &source) const;
    
    private:
    GraphType adj_list;
    int num_edges = 0;
};

#endif //NETWORK_GRAPH_H_
