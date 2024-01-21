#include <bits/stdc++.h>
using namespace std;

bool isprime[1000005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  vector<int> prime;

  for(long long i=2; i<=1000000; i++){
    if(isprime[i]) continue;
    prime.push_back(i);
    isprime[i] = 1;
    for(long long j=i*i; j<=1000000; j += i) isprime[j] = 1;
  }

  while(t--){
    int n;
    cin >> n;
    int cnt=0;
    for(auto a: prime){
      if(n-a > 0){
        if(binary_search(prime.begin(), prime.end(), n-a)) cnt++;
      }
    }

    cout << (cnt+1) / 2 << '\n';
  }



}