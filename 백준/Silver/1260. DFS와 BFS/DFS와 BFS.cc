#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool vis[1005];


void dfs(int cur){
  vis[cur] = true;
  cout << cur << ' ';
  for(int nxt: adj[cur]){
    if(vis[nxt]) continue;
    dfs(nxt);
  }
}

void bfs(int root){
  queue<int> q;
  q.push(root);
  vis[root] = true;

  while(!q.empty()){
    int cur = q.front(); q.pop();
    cout << cur << ' ';
    for(int nxt: adj[cur]){
      if(vis[nxt]) continue;
      q.push(nxt);
      vis[nxt] = true;
    }
  }

}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m,root;
  cin >> n >> m >> root;

  for(int i=0; i<m; i++){
    int u,v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  for(int i=1; i<=n; i++)
    sort(adj[i].begin(), adj[i].end());
  
  dfs(root);
  fill(vis, vis+1005, 0);
  cout << '\n';
  bfs(root);

}
