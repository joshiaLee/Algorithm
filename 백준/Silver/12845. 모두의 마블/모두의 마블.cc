#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> v;

  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin(), v.end(), greater<int>());
  int sum = 0;

  if(n==1){
    cout << v[0] << '\n';
    return 0;
  }

  
  for(int i=1; i<n; i++) sum += (v[0] + v[i]);

  cout << sum << '\n';
  
}