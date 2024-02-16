#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
int deg[1005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  for(int i=0; i<m; i++){
    int num;
    int pre;

    cin >> num;
    
    for(int j=0; j<num; j++){
      int order;
      cin >> order;
      if(j==0) pre = order;

      else{
        adj[pre].push_back(order);
        deg[order]++;
        pre = order;
      }
      
    }
  }

  queue<int> q;
  vector<int> ans;

  for(int i=1; i<=n; i++)
    if(deg[i] == 0) q.push(i);

  while(!q.empty()){
    int cur = q.front(); q.pop();
    ans.push_back(cur);
    for(int nxt: adj[cur]){
      deg[nxt]--;
      if(deg[nxt] == 0) q.push(nxt);
    }
  }

  if(ans.size() != n) 
    cout << 0 << '\n';
  

  else
    for(int order: ans)
      cout << order << '\n';
    
}
