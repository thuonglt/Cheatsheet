#include<bits/stdc++.h>

//============================================Adj list
void bfs(vector<vector<int>> &adj, int start) {
    queue<int> travel;
    travel.push(start);
    vector<bool> visited(adj.size(), false);
    visited[start] = true;
    while(!travel.empty()) {
        int node = travel.front();
        travel.pop();

        //Do smth

        for(int next: adj[node]) {
            if(!visited[next]) {
                travel.push(next);
                visited[next] = true;
            }
        }
    }
}

//===================================================== ADJ matrix

void bfs(vector<vector<int>> &adj, int start) {
    int n = adj.size();
    queue<int> travel;
    travel.push(start);
    vector<bool> visited(adj.size(), false);
    visited[start] = true;
    while(!travel.empty()) {
        int node = travel.front();
        travel.pop();

        //Do smth

        for(int next = 0; next < n; next++) {
            if(adj[node][next] == 0) continue;
            if(!visited[next]) {
                travel.push(next);
                visited[next] = true;
            }
        }
    }
}
