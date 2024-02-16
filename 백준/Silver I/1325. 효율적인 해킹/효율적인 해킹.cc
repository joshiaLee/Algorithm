#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10005];
int num[10005];
int vis[10005];
int mx;

void dfs(int cur, int root){
  num[root]++;
  vis[cur] = 1;

  for(int nxt: adj[cur]){
    if(vis[nxt]) continue;
    dfs(nxt, root);
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

    adj[v].push_back(u);
  }

  for(int i=1; i<=n; i++){
    fill(vis, vis+10005, 0);
    dfs(i, i);
  }

  int mx = *max_element(num+1, num+1+n);

  for(int i=1; i<=n; i++){
    if(num[i] == mx){
      cout << i << ' ';
    }
  }


  

}
