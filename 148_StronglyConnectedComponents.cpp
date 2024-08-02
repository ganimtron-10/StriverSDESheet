
#include <bits/stdc++.h>

void topologySort(vector<vector<int>> &adj, stack<int> &s, int start, vector<int> &visited)
{
    visited[start] = 1;
    for (auto child : adj[start])
    {
        if (!visited[child])
        {
            topologySort(adj, s, child, visited);
        }
    }
    s.push(start);
}

void dfs(vector<vector<int>> &adj, vector<int> &scc, int start, vector<int> &visited)
{
    visited[start] = 1;
    scc.push_back(start);
    for (auto child : adj[start])
    {
        if (!visited[child])
        {
            dfs(adj, scc, child, visited);
        }
    }
}

vector<vector<int>> KosaRajuAlgo(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> visited(n);
    stack<int> topoSort;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topologySort(adj, topoSort, i, visited);
        }
    }

    vector<vector<int>> transpose(n, vector<int>());
    for (int i = 0; i < adj.size(); i++)
    {
        visited[i] = 0;
        for (auto child : adj[i])
        {
            transpose[child].push_back(i);
        }
    }

    vector<vector<int>> result;
    while (!topoSort.empty())
    {
        int node = topoSort.top();
        topoSort.pop();
        vector<int> temp;
        if (!visited[node])
        {
            dfs(transpose, temp, node, visited);
            result.push_back(temp);
        }
    }

    return result;
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> adj(n, vector<int>());
    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }
    return KosaRajuAlgo(adj);
}