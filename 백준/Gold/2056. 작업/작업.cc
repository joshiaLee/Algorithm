#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10005];
vector<int> deg_t[10005];

int t[10005];
int deg[10005];
int mx = -1;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i=1; i<=n; i++){
    cin >> t[i];
    int m;
    cin >> m;

    for(int j=0; j<m; j++){
      int pre;
      cin >> pre;
      adj[pre].push_back(i);
      deg_t[i].push_back(pre);
      deg[i]++;
    }
  }

  queue<int> q;

  for(int i=1; i<=n; i++){
    if(deg[i] == 0) q.push(i);
    sort(adj[i].begin(), adj[i].end());
  }
  
  while(!q.empty()){
    int cur = q.front(); q.pop();
    mx = max(mx, t[cur]);

    for(int nxt: adj[cur]){
      deg[nxt]--;

      if(deg[nxt] == 0){
        int max_val = -1;
        for(int pre: deg_t[nxt])
          max_val = max(max_val, t[pre]);
        t[nxt] = t[nxt] + max_val;

        q.push(nxt);
      }
    }
  }

  cout << mx << '\n';

}
