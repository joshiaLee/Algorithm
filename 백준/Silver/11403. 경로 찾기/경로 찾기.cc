#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];
int vis[105];

int board[105][105];


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      int a;
      cin >> a;

      if(a == 1) adj[i].push_back(j);
    }
  }


  queue<int> q;

  for(int root=1; root<=n; root++){
    
    q.push(root);
    fill(vis, vis+105, 0);

    while (!q.empty())
    {
      int cur = q.front(); q.pop();
      for(int nxt: adj[cur]){
        if(vis[nxt]) continue;
        vis[nxt] = 1;
        board[root][nxt] = 1;
        q.push(nxt);  
      }
    }
    
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }



}
