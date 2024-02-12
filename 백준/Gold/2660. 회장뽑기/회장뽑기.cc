#include <bits/stdc++.h>
using namespace std;

vector<int> adj[55];
int score[55];
int dis[55];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  while (true)
  {
    int u,v;
    cin >> u >> v;
    if(u == -1 && v == -1) break;

    adj[u].push_back(v);
    adj[v].push_back(u);

  }

  for(int root=1; root<=n; root++){
    fill(dis, dis+55, -1);
    queue<int> q;
    q.push(root);
    dis[root] = 0;

    while(!q.empty()){
      int cur = q.front(); q.pop();
      for(int nxt: adj[cur]){
        if(dis[nxt] != -1) continue;
        dis[nxt] = dis[cur] + 1;
        score[root] = max(score[root], dis[nxt]);
        q.push(nxt);
      }
    }

  }

    vector<int> ans;
    int m = *min_element(score+1, score+n+1);
    for(int i=1; i<=n; i++){
      if(score[i] == m){
        ans.push_back(i);
      }
    }

    cout << m << ' ' << ans.size() << '\n';
    for(int output: ans) cout << output << ' ';
  

}
