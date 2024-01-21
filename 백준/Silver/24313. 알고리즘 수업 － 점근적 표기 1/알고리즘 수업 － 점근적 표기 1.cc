#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int a1,a0,c,n0;
  cin >> a1 >> a0 >> c >> n0;
  for(int i=n0; i<=100; i++){
    if(a1 * i + a0 > c*i){
      cout << 0 << '\n';
      return 0;
    }
  }

  cout << 1 << '\n';
}