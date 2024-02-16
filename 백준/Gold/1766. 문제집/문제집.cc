#include <bits/stdc++.h>
using namespace std;

vector<int> adj[32005];
int deg[32005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  for(int i=0; i<m; i++){
    int u,v;
    cin >> u >> v;

    adj[u].push_back(v);
    deg[v]++;
  }

  

  priority_queue<int, vector<int>, greater<int>> q;
  vector<int> ans;

  for(int i=1; i<=n; i++)
    if(deg[i] == 0) q.push(i);
  

  while(!q.empty()){
    int cur = q.top(); q.pop();
    ans.push_back(cur);
    for(int nxt: adj[cur]){
      deg[nxt]--;
      if(deg[nxt] == 0) q.push(nxt);
    }
  }

  for(int res: ans) cout << res << ' ';


}
