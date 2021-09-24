
bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &augumented, vector<int> &path, int group) {
    for(int next: adj[node]) {
        if(visited[next]) continue;
        if(group == 1 && augumented[next]) {
            path.push_back(next);
            return true;
        }
        visited[next] = true;
        if(dfs(next, adj, visited, augmented, path, 1 - group)) return true;
        visited[next] = false;
    }
    return false;
}
