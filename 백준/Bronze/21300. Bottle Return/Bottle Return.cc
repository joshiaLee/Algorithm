#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int sum=0;
  for(int i=0; i<6; i++){
    int container;
    cin >> container;
    sum += container * 5;
  }

  cout << sum << '\n';
  
}