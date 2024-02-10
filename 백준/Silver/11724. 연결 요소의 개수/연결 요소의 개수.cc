#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool vis[1005];


void dfs(int cur){
  vis[cur] = true;
  for(int nxt: adj[cur]){
    if(vis[nxt]) continue;
    dfs(nxt);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  for(int i=0; i<m; i++){
    int u,v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  int cnt=0;
  for(int i=1; i<=n; i++){
    if(vis[i]) continue;
    
    cnt++;
    dfs(i);
  }

  cout << cnt << '\n';


}
