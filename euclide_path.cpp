#include<bits/stdc++.h>

//ADJ edge list

void dfs(int node, vector<vector<int>> &conn, vector<pair<int, int>>&edge, vector<bool> &visited, vector<int> &path) {
    for(int next_edge: conn[node]) {
        if(visited[next_edge] == true) continue;
        visited[next_edge] = true;
        if(edge[next_edge].first == node) {
            dfs(edge[next_edge].second, conn, edge, visited, path);
            path.push_back(-next_edge);
        } else {
            dfs(edge[next_edge].first, conn, edge, visited, path);
            path.push_back(next_edge);
        }
    }
}
