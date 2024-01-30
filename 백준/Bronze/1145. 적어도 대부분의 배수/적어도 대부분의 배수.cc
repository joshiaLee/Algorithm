#include <bits/stdc++.h>
using namespace std;



int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> v(5);

  for(int i=0; i<5; i++){
    cin >> v[i];
  } 

  for(int i=1; i<=1000000; i++){
    int cnt = 0;
    for(int j=0; j<5; j++){
      if(i % v[j] == 0) cnt++;
      if(cnt >= 3){
        cout << i << '\n';
        return 0;
      }
    }
  }


}