// Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
// Explanation: 
// Given: a / b = 2.0, b / c = 3.0
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
// return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
// note: x is undefined => -1.0

#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

double bfs(string start, string end, map<string,vector<string>>& graph, map<pair<string,string>,double>& w){
    if(graph[start].empty() || graph[end].empty()) return -1.0;  // if start and end arent in the graph
    if(start==end) return 1.0;

    map<string,string> parent;  // save the "parent" of each node
    queue<string> q;
    q.push(start);

    while( !q.empty() )
    {
        string t= q.front();
        q.pop();

        if(t==end)   // if we found the end node
        {
            double res=1.0; 
            while(t!=start)
            {
                res*=w[{parent[t],t}];
                t=parent[t];
            }
            return res;
        }

        for(auto x:graph[t]) // else
        {
            if(x!=parent[t] && !parent[x].length()) // check if theres no circle and x wasnt visited already  
            {
                parent[x]=t;
                q.push(x);
            }
        }
    }
    return -1.0;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    map< string , vector<string >> graph;   // graph(node a)=[b,c,d]  vector of neighbors 
    map< pair<string,string> , double > w; // w(<a,b>)=5
    vector<double> res;
    
    // create the graph
    for(int i=0; i<values.size();i++)
    {
        // add nodes and edges
        graph[equations[i][0]].push_back(equations[i][1]);  
        graph[equations[i][1]].push_back(equations[i][0]);  

        // add weights to edges
        w[{equations[i][0],equations[i][1]}]= values[i];
        w[{equations[i][1],equations[i][0]}]= 1.0/values[i];
    }

    for(auto x: queries) res.push_back(bfs(x[0],x[1],graph,w));

    return res;
}

int main() {
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};  // a/b = 2.0 and b/c = 3.0
    vector<vector<string>> queries = {{"a", "c"}, {"c", "a"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    // Call the calcEquation function
    vector<double> results = calcEquation(equations, values, queries);

    cout << "Results of queries:" << endl;
    for (double result : results) {
        cout << result << endl;
    }

    return 0;
}