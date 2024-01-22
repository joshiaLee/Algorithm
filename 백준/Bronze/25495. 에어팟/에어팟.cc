#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int prev;
  cin >> prev;
  int percent = 2;
  int sum = 2;
  for(int i=1; i<n; i++){
    int a;
    cin >> a;
    if(prev == a){
      percent = percent * 2;
      sum += percent;
    }
    else{
      percent = 2;
      sum += percent;
    }

    prev = a;
    if(sum >= 100){
      prev = -1;
      percent = 0;
      sum = 0;
    }
  }

  cout << sum << '\n';



}