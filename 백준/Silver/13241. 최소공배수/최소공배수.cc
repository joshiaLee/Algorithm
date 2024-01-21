#include <bits/stdc++.h>
using namespace std;

long long gcd(long a, long b){
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  long long a,b;
  cin >> a >> b;
  if(a==b){
    cout << a << '\n';
    return 0;
  }
  long long g = gcd(max(a,b), min(a,b));
  cout << (a/g) * (b/g) * g << '\n';
}