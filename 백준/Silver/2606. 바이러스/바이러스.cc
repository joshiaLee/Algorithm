#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];
bool vis[105];
int cnt = 0;

void dfs(int cur){
  vis[cur] = true;
  cnt++;
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

  dfs(1);

  cout << cnt - 1 << '\n';


}
