#include <iostream>
#include <map>
#include <vector>
#include <queue> // for bfs later
using namespace std;

void printGraph(map< string , vector<string >> graph, map< pair<string,string> , double > w) 
{
    // Print the graph structure
    cout << "Graph:" << endl;
    for (const auto& node : graph)
    {
        cout << node.first << " -> ";
        for (const auto& neighbor : node.second)
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    
    // Print the weights of the edges
    cout << "Weights:" << endl;
    for (const auto& edge : w)
    {
        cout << "(" << edge.first.first << "," << edge.first.second << ") = " << edge.second << endl;
    }
}

void createGraph(vector<vector<string>>& edges, vector<double>& weights) 
{
    map< string , vector<string >> graph;   // graph(node a)=[b,c,d]  vector of neighbors 
    map< pair<string,string> , double > w; // w(<a,b>)=5
    
    // create the graph
    for(int i=0; i<weights.size();i++)
    {
        // add nodes and edges
        graph[edges[i][0]].push_back(edges[i][1]);   // graph[a]=[b]

        // add weights to edges
        w[{edges[i][0],edges[i][1]}]= weights[i];   // w[{a,b}]=2
    }

    printGraph(graph,w);

}

int main() 
{
    vector<vector<string>> edges = {{"a", "b"}, {"b", "c"}};
    vector<double> weights = {2.0, 3.0};  
    
    createGraph(edges, weights);   
    return 0;
}