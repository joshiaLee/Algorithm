#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  long long sum = 0;

  for(int i=0; i<n; i++){
    int prize;
    cin >> prize;
    sum += prize;
  }

  if(sum % 3 == 0) cout << "yes" << '\n';
  else cout << "no" << '\n';
  
}