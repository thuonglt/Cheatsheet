#include<bits/stdc++.h>



using namespace std;
bool bfs(vector<vector<int>> &conn, vector<bool> &inGr1, vector<int> &dist, vector<int> &pair) {
    int n = conn.size();
    queue<int> travel;
    for(int i = 0; i < n; i++) {
        if(inGr1[i] && pair[i] == -1) {
            dist[i] = 0;
            travel.push(i);
        } else {
            dist[i] = INT_MAX;
        }
    }
    bool ret = false;
    while(!travel.empty()) {
        int node = travel.front();
        travel.pop();
        for(int next: conn[node]) {
            if(inGr1[next]) continue;
            if(pair[next] == -1) {
                dist[next] = dist[node] + 1;
                ret = true;
                continue;
            }
            if(dist[next] > dist[node] + 1) {
                dist[next] = dist[node] + 1;
                dist[pair[next]] = dist[node] + 2;
                travel.push(pair[next]);
            }
        }
    }
    return ret;
}

bool dfs(int node, vector<vector<int>> &conn, vector<int> &dist, vector<int> &pair) {
    if(node == -1) return true;
    for(int next: conn[node]) {
        if(dist[node] + 1 != dist[next]) continue;
        if(dfs(pair[next], conn, dist, pair)) {
            pair[next] = node;
            pair[node] = next;
            dist[next] = INT_MAX;
            dist[node] = INT_MAX;
            return true;
        }
    }
    dist[node] = INT_MAX;
    return false;
}

int hopcroftKarp(vector<vector<int>> &conn, vector<bool> &inGr1) {
    int n = conn.size();
    vector<int> dist(n), pair(n, -1);
    int ret = 0;
    while(bfs(conn, inGr1, dist, pair)) {
        for(int i = 0; i < n; i++ ) {
            if(pair[i] != -1) continue;
            if(dfs(i, conn, dist, pair)) ret++;
        }
    }
    return ret;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> gr = {{1}, {0, 2}, {1, 3}, {2}};
    vector<bool> inGr1 = {true, false, true, false};
    cout << hopcroftKarp(gr, inGr1);
    return 0;
}
