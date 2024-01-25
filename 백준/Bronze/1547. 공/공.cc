#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cup[4] = {0, 1, 0, 0};

  int m;
  cin >> m;

  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;

    int temp = cup[a];
    cup[a] = cup[b];
    cup[b] = temp;
  }

  for(int i=1; i<=3; i++) if(cup[i]) cout << i << '\n';
  



  
  
}