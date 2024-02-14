#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];
int score[105];
int dis[105];

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

  int min_val = 2000000000;
  for(int root=1; root<=n; root++){
    fill(dis, dis+105, -1);
    queue<int> q;
    q.push(root);
    dis[root] = 0;

    while (!q.empty())
    {
      int cur = q.front(); q.pop();
      for(int nxt: adj[cur]){
        if(dis[nxt] != -1) continue;
        dis[nxt] = dis[cur] + 1;
        score[root] += dis[nxt];
        q.push(nxt);
      }
    }
    
    min_val = min(min_val, score[root]);
  }

  for(int i=1; i<=n; i++){
    if(score[i] == min_val){
      cout << i << '\n';
      break;
    }
  }

  

}
