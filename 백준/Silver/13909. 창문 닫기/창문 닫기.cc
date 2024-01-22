#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int ans=0;
  for(int i=1; i*i<=n; i++) ans++;

  cout << ans << '\n';
}