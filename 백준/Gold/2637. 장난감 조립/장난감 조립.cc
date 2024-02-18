#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];
int parts[105][105];
int deg[105];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int u,v,k;
    cin >> u >> v >> k;
    adj[v].push_back(u);
    deg[u]++;
    parts[u][v] = k;
  }

  queue<int> q;
  vector<int> basics;

  for(int i=1; i<=n; i++)
    if(deg[i] == 0){
      q.push(i);
      basics.push_back(i);
    }
  
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    if(cur == n){
      for(int basic: basics)
        cout << basic << ' ' << parts[cur][basic] << '\n'; 
      break;
    }

    for(int nxt: adj[cur]){
      deg[nxt]--;
      int weight = parts[nxt][cur]; 
      for(int basic: basics)
        parts[nxt][basic] += parts[cur][basic] * weight;
      
      if(deg[nxt] == 0) q.push(nxt);
    }

  }

}