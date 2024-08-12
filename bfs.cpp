#include <iostream>
#include <map>
#include <vector>
#include <queue> // for bfs later
#include <set>
using namespace std;


bool bfs(string start, string end, map<string, vector<string>>& graph, map<pair<string, string>, double>& w) 
{
    if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) return 0; // Start or end node not in the graph
    if (start == end) return 1; // Start and end are the same
       
    queue<string> q;
    set<string> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) 
    {
        string t = q.front();
        q.pop();

        if (t == end) return 1; // Path found

        for (auto neighbor : graph[t]) 
        {
            if (visited.find(neighbor) == visited.end()) // If neighbor has not been visited
            { 
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
    return 0; // No path found
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

    cout << bfs("a", "c",graph,w);
}


int main() 
{
    vector<vector<string>> edges = {{"a","b"}, {"b","c"}};
    vector<double> weights = {2.0, 3.0};  
    
    createGraph(edges, weights);   
    return 0;
}