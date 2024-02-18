#include <bits/stdc++.h>
using namespace std;


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n,k,m;
    cin >> n >> k;
    vector<int> adj[1005];
    long d[1005] = {0};
    int deg[1005] = {0};

    for(int i=1; i<=n; i++)
      cin >> d[i];
    for(int i=0; i<k; i++){
      int u,v;
      cin >> u >> v;
      adj[u].push_back(v);
      deg[v]++;
    }

    cin >> m;

    queue<int> q;
    vector<int> pre[1005];

    for(int i=1; i<=n; i++)
      if(deg[i] == 0) q.push(i);
    
    while(!q.empty()){
      int cur = q.front(); q.pop();
      if(cur == m){
        cout << d[cur] << '\n';
        break;
      }
      for(int nxt: adj[cur]){
        deg[nxt]--;
        pre[nxt].push_back(d[cur]);
        if(deg[nxt] == 0){
          d[nxt] = d[nxt] + *max_element(pre[nxt].begin(), pre[nxt].end());
          q.push(nxt);
        }
      }
    }
  }

}