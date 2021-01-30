#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;


struct Edge
{

    Edge(int source, int dest, int weight)
    : mSource(source), mDest(dest), mWeight(weight)
    {
    }

    int mSource;
    int mDest;
    int mWeight;
};

struct Compare
{
    bool operator()(Edge const& a, Edge const& b)
    {
        return a.mWeight > b.mWeight;
    }
};

using Graph = vector<vector<Edge>>;

int main()
{
    
    int nodes, edges;
    cin >> nodes >> edges;

    Graph graph(nodes);


    for(size_t i = 0; i < edges; ++i)
    {
        int s,d,w;
        cin >> s >> d >> w;

        Edge edge(s,d,w);
        graph[s].emplace_back(edge);

        Edge reverse(d,s,w);
        graph[d].emplace_back(reverse);
    }


    unordered_set<int> onMst;

    /* will start the mst at node 0 */
    onMst.insert(0);

    priority_queue<Edge, vector<Edge>, Compare> q;
    for(auto& edge : graph[0])
        q.push(edge);

    vector<Edge> mst;

    while(onMst.size() < nodes)
    {
        auto e = q.top();
        q.pop();

        /* if the destination of this edge is not already in the mst, then
           we have to add it to the mst, and add all its edges to the priority_queue */
        if(onMst.find(e.mDest) == onMst.end())
        {
            onMst.insert(e.mDest);
            for(auto& edge : graph[e.mDest])
                q.push(edge);

            mst.emplace_back(e);
        }
    }

    /* Finally, print the mst */

    for(const auto& edge : mst)
        cout << edge.mSource << "->" << edge.mDest << ": " << edge.mWeight << endl;


    return 0;
}
