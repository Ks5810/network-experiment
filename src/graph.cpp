/*******************************************************************************
Title           : graph.cpp
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
        ++num_edges;
    }
    --num_edges;
}

int Graph::getNumEdges()
{
    return num_edges;
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
    
    // Print output
    int width = 54;
    
    cout << "\n";
    utils::printCentered("Bellman Ford", width);
    utils::printWithSpaceBetween("Vertices:", adj_list.size(), width);
    utils::printWithSpaceBetween("Edges:", num_edges, width);
    utils::printCentered("", width);
    
    for(auto const &vertices: adj_list)
    {
        utils::printWithSpaceBetween(
            vertices.first,
            distances[vertices.first],
            width
        );
    }
    utils::printCentered("", width);
    
}



