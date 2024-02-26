#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int vis[100005];
int p[100005];
int cutting;

void dfs(int cur){
    if(vis[cur]) return;
    vis[cur] = 1;

    for(int nxt: adj[cur]){
        if(nxt == p[cur]) continue;
        p[nxt] = cur;
        dfs(nxt);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int num_trees = 0;
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        num_trees++;
        dfs(i);
    }

    cout << (num_trees-1) + (m+num_trees-1) - (n-1) << '\n';
}

