#include <bits/stdc++.h>
using namespace std;

long long v[1000005];
long long sum[1000005];
long long comb[1005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m;

  cin >> n >> m;
  for(int i=1; i<=n; i++)
    cin >> v[i];
  
  sum[0] = 0;

  for(int i=1; i<=n; i++)
    sum[i] = sum[i-1] + v[i];
  

  for(int i=0; i<=n; i++)
    sum[i] = sum[i] % m;

  for(int i=0; i<=n; i++)
    comb[sum[i]]++;
  
  long long ans=0;

  for(int i=0; i<m; i++)
    if(comb[i] >= 2)
      ans += (comb[i] * (comb[i] - 1)) / 2;

  cout << ans << '\n';
  
  
    
  
}