/*******************************************************************************
Title           : bellman_ford.cpp
Author          : Keisuke Suzuki
Created on      : 5/14/20
Modification    :
*******************************************************************************/
#include <iomanip>
#include "graph.h"

Graph::Graph() : adj_list(GraphType()){ }

Graph::Graph(ifstream &file) : adj_list(GraphType())
{
    CSVRow row;
    string v1, v2;
    int v3 = 0;
    while(file >> row)
    {
        v1 = row[0];
        v2 = row[1];
        v3 = row[2].empty() ? 0 : stoi(row[2]);
        adj_list[v1].push_back(make_pair(v2, v3));
    }
}

void Graph::clear()
{
    adj_list.clear();
}

void Graph::bellmanFord(string &source) const
{
    int V = adj_list.size();
    unordered_map<string, int> distances;
    
    // Initialize distances to INT_MAX
    for(const auto &v : adj_list)
    {
        distances[v.first] = INT_MAX;
    }
    
    // Initialize distance at source to 0
    distances[source] = 0;

    // Iterate through all edges and vertices V - 1 times
    for(int i = 0; i < V - 1; ++i)
    {
        for(auto &vertices: adj_list)
        {
            string u = vertices.first;
            string v;
            int w = 0;
            auto adj_vertices = vertices.second;
            auto it = adj_vertices.begin();
            
            while(it != adj_vertices.end())
            {
                v = (*it).first;
                w = (*it).second;
                if(utils::add(distances[u], w) < distances[v])
                {
                    distances[v] = distances[u] + w;
                }
                ++it;
            }
        }
    }
    for(auto &vertices: adj_list)
    {
        cout << vertices.first << ":" << setw(30) << "\t\t"
             << distances[vertices.first] << endl;
    }
}


