/*******************************************************************************
Title           : graph.cpp
Author          : Keisuke Suzuki
Created on      : 5/14/20
Modification    :
*******************************************************************************/
#include "graph.h"

Graph::Graph() = default;

Graph::Graph(ifstream &file)
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
        if(v3 < 0)
        {
            has_negative_edges = true;
        }
        ++num_edges;
    }
    --num_edges;
}

int Graph::getNumEdges()
{
    return num_edges;
}

bool Graph::hasNegativeEdges()
{
    return has_negative_edges;
}

void Graph::clear()
{
    adj_list.clear();
}

bool Graph::bellmanFord(string &source) const
{
    int V = adj_list.size();
    unordered_map<string, int> distances;
    bool negative_cycles = false;
    
    auto DetectNegativeCycles = [&](auto v, auto u, auto w)
    {
        if(distances[v] <= utils::add(distances[u], w))
        {
            negative_cycles = true;
        }
    };
    auto CompareNSetDistance = [&](auto v, auto u, auto w)
    {
        if(utils::add(distances[u], w) < distances[v])
        {
            distances[v] = distances[u] + w;
        }
    };
    auto IterateAdjList = ([&](auto func)
    {
        for(auto &vertices: adj_list)
        {
            string u = vertices.first;
            string v;
            int w;
            for(const auto &vertex: vertices.second)
            {
                v = vertex.first;
                w = vertex.second;
                func(v, u, w);
            }
        }
    });
    
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
        IterateAdjList(CompareNSetDistance);
    }
    
    // Detect negative cycles
    if(has_negative_edges)
    {
        IterateAdjList(DetectNegativeCycles);
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
    
    // Return 1 if negative cycles are detected
    if(negative_cycles)
    {
        cerr << "Negative cycle(s) detected!\nThis result may be incorrect!\n";
        return true;
    }
    
    return false;
}



