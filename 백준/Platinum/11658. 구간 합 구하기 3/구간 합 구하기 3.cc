#include <bits/stdc++.h>
using namespace std;

int table[1050][1050];
int sum[1050][1050];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cin >> table[i][j];
      if(j==1) sum[i][j] = table[i][j];
      else sum[i][j] = sum[i][j-1] + table[i][j];
    }
  }

  while (m--)
  {
    int w;
    cin >> w;

    if(w == 1){
      int x1,x2,y1,y2;
      cin >> x1 >> y1 >> x2 >> y2;
      int total = 0;
      for(int i=x1; i<=x2; i++)
          total += (sum[i][y2] - sum[i][y1-1]);
      
      cout << total << '\n'; 
    }

    else{
      int x1,y1,c;
      cin >> x1 >> y1 >> c;
      int dif = c - table[x1][y1];
      table[x1][y1] = c;

      for(int i=y1; i<=n; i++)
          sum[x1][i] = sum[x1][i] + dif;
    }

  }
  

  
}