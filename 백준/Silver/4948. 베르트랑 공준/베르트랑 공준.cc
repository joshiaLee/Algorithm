#include <bits/stdc++.h>
using namespace std;

bool vis[250005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  

  vector<int> prime;

  for(long long i=2; i<=250000; i++){
    if(vis[i]) continue;
    vis[i] = 1;
    prime.push_back(i);
    for(long long j=i*i; j<=250000; j += i) vis[j] = 1;
  }

  while (true)
  {
    int n;
    cin >> n;
    if(n == 0) break;
    cout << upper_bound(prime.begin(), prime.end(), 2*n) - upper_bound(prime.begin(), prime.end(), n) << '\n'; 
  }
  
  





}