#include <iostream>
#include <vector>
#include <stack>

using namespace std;

using Graph = vector<vector<int>>;

enum class State
{
    not_visited,
    visited,
    completed
};

/* This DFS traverse function adds the visited nodes to a stack after visiting the outgoing nodes. */
void DFS(Graph const& graph, size_t const node, vector<State>& states, stack<int>& s)
{
    if(states[node] != State::not_visited)
        return;

    states[node] = State::visited;

    for(auto& children : graph[node])
        DFS(graph, children, states, s);

    s.push(node);
    states[node] = State::completed;
}

/* This other DFS function just adds the nodes as soon as they are visited. */
void DFS2(Graph const& graph, size_t const node, vector<State>& states, vector<int>& output)
{
    if(states[node] != State::not_visited)
        return;

    states[node] = State::visited;

    output.emplace_back(node);

    for(auto& children : graph[node])
        DFS2(graph, children, states, output);

    states[node] = State::completed;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    Graph graph(nodes);
    Graph reversed(nodes);

    for(size_t i = 0; i < edges; ++i)
    {
        int source, dest;
        cin >> source >> dest;
        graph[source].emplace_back(dest);
        reversed[dest].emplace_back(source);
    }

    stack<int> kstack;

    vector<State> states(nodes, State::not_visited);

    for(size_t i = 0; i < nodes; ++i)
    {
        if(states[i] == State::not_visited)
        {
            DFS(graph, i, states, kstack);
        }
    }

    /* cleaning it to the DFS of the reversed graph. */
    states = vector<State>(nodes, State::not_visited);

    vector<int> sorted;
    while(not kstack.empty())
    {
        const int node = kstack.top();
        kstack.pop();

        if(states[node] == State::not_visited)
        {
            DFS2(reversed, node, states, sorted);            
        }
    }

    for(auto& node : sorted)
        cout << node << endl;

    return 0;
}
