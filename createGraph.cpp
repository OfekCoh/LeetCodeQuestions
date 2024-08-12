#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

void createGraph(vector<vector<string>>& edges, vector<double>& weights) 
{
    map< string , vector<string >> graph;   // graph(node a)=[b,c,d]  vector of neighbors 
    map< pair<string,string> , double > w; // w(<a,b>)=5
    
    // create the graph
    for(int i=0; i<weights.size();i++)
    {
        // add nodes and edges
        graph[edges[i][0]].push_back(edges[i][1]);  
        graph[edges[i][1]].push_back(edges[i][0]);  

        // add weights to edges
        w[{edges[i][0],edges[i][1]}]= weights[i];
        w[{edges[i][1],edges[i][0]}]= 1.0/weights[i];
    }
}


int main() 
{
    vector<vector<string>> edges = {{"a", "b"}, {"b", "c"}};
    vector<double> weights = {2.0, 3.0};  

    createGraph(edges, weights);   
    return 0;
}