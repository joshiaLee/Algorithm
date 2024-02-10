#include <bits/stdc++.h>
using namespace std;

vector<int> adj[505];
int depth[505];

int cnt;


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

  queue<int> q;
  q.push(1);

  while(!q.empty()){
    int cur = q.front(); q.pop();

    for(int nxt: adj[cur]){
      if(depth[nxt] || nxt == 1) continue;
      depth[nxt] = depth[cur] + 1;
      if(depth[nxt] <= 2) cnt++;
      q.push(nxt);
    }
  }

  cout << cnt << '\n';

}
