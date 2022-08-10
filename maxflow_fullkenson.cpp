#include<bits/stdc++.h>

//connection map
class MaxFlow {
    public: 
    vector<vector<int>> conn;
    int source, sink;

    MaxFlow(int node) {
        conn = vector<vector<conn>>(node, vector<int>(node, 0));
        source = 0; sink = node - 1;
    }

    void addEdge(int start, int end, int val) {
        conn[start][end] = val;
    }

    bool bfs(vector<int> &parent) {
        int n = conn.size();
        vector<bool> visited(n,false);
        queue<int> travel;
        travel.push(source);
        visited[source] = true;
        while(!travel.empty()) {
            int node = travel.front();
            travel.pop();
            for(int i = 0; i < n; i++) {
                if(conn[node][i] == 0 || visited[i]) continue;
                visited[i] = true;
                parent[i] = node;
                if(i == sink) return true;
                travel.push(i);
            }
        }
        return false;
    }

    int minFlow() {
        int n = conn.size();
        vector<int> parent(n);
        int ret = 0;
        while(bfs(parent)) {
            int curr = sink;
            int fl = INT_MAX;
            while(curr != source) {
                int par = parent[curr];
                fl = min(fl, conn[par][curr]);
                curr = par;
            }
            ret += fl;
            curr = sink;
            while(curr != source) {
                int par = parent[curr];
                conn[par][curr] -= fl;
                conn[curr][par] += fl;
                curr = par;
            }
        }
        return ret;
    }

}
