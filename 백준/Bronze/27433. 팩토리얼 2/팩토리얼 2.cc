#include <bits/stdc++.h>
using namespace std;

long long func(int k){
  if(k == 1) return 1;
  else return func(k-1) * k;

}


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  if(n==0){
    cout << 1 << '\n';
    return 0;
  }

  else cout << func(n) << '\n';
}