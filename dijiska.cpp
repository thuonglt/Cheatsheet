#include<bits/stdc++.h>

//Min dist adj matrix
void dijkstra(vector<vector<int>> &conn, int node)
{
    int n = conn.size();
    vector<int> dist(n, INT_MAX);
    dist[node] = 0;
    std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>> > travel;
    travel.push({0, src});

    while(!travel.empty()) {
        pair<int, int>  p = travel.top();
        travel.pop();
        if(p.first != dist[p.second]) continue;
        for(int next = 0; next < n; next++) {
            if(conn[p.second][next] == 0) continue;
            if(dist[next] <= dist[p.second] + conn[p.second][next]) continue;
            dist[next] = dist[p.second] + conn[p.second][next];
            travel.push({dist[next], next});
        }
    }
}

//Min step adj list

void dijkstra(vector<vector<int>> &conn, int node)
{
    int n = conn.size();
    vector<int> dist(n, INT_MAX);
    dist[node] = 0;
    std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>> > travel;
    travel.push({0, src});

    while(!travel.empty()) {
        pair<int, int>  p = travel.top();
        travel.pop();
        if(p.first != dist[p.second]) continue;
        for(int next: conn[p.second]) {
            if(conn[p.second][next] == 0) continue;
            if(dist[next] <= dist[p.second] + 1) continue;
            dist[next] = dist[p.second] + 1;
            travel.push({dist[next], next});
        }
    }
}
