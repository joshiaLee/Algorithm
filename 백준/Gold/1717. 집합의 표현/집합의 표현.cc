#include <bits/stdc++.h>
using namespace std;


int parent[1000005];

int find(int x){
  if(x != parent[x])
    return parent[x] = find(parent[x]);
  else return x; 
}


void uni(int x, int y){
  int v = find(x);
  int w = find(y);

  if(v == w) return;

  if(v < w) parent[w] = v;
  else parent[v] = w;
  
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  for(int i=0; i<=n; i++) parent[i] = i;

  for(int i=0; i<m; i++){
    int c,a,b;
    cin >> c >> a >> b;
    if(c == 0) uni(a,b);
    else{
      if(find(a) == find(b)) cout << "YES" << '\n';
      else cout << "NO" <<'\n';
    }
  }


  
}