#include <bits/stdc++.h>
using namespace std;


int parent[4000005];
vector<int> v;

int find(int x){
  if(x != parent[x])
    return parent[x] = find(parent[x]);
  else return x; 
}


void uni(int x, int y){
  int v = find(x);
  int w = find(y);

  if(v != w) parent[v] = w;
    
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m,k;
  cin >> n >> m >> k;

  for(int i=0; i<n; i++) parent[i] = i;

  v.resize(m);

  for(int i=0; i<m; i++)
    cin >> v[i];
  

  sort(v.begin(), v.end());
  while(k--){
    int a;
    cin >> a;
    int idx = upper_bound(v.begin(), v.end(), a) - v.begin();
    idx = find(idx);

    cout << v[idx] << '\n';

    uni(idx, idx+1); 
  
  }

  
}