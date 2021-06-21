int bfs(int start, int end) {
    
    
    queue<int> q;
    q.push(start);
    vis[start] = true;
    dist[start] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    return dist[end];
}


void dfs(int u) {
    printf("%d ", u);
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = true;
            dfs(v);
        }
    }
}