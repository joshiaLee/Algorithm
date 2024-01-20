#include <bits/stdc++.h>
using namespace std;


char board[55][55];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n,m;
  cin >> n >> m;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> board[i][j];
    }
  }

  int M = 64;

  for(int i=0; i<=n-8; i++){
    for(int j=0; j<=m-8; j++){
      char temp[8][8];
      int cnt_w=0;
      int cnt_b=0;

      for(int x=i; x<i+8; x++){
        for(int y=j; y<j+8; y++){
          temp[x-i][y-j] = board[x][y];
        }
      }
      
      for(int x=0; x<8; x++){
        for(int y=0; y<8; y++){
          if((x+y) % 2 == 0 && temp[x][y] == 'B') cnt_w++;
          if((x+y) % 2 == 1 && temp[x][y] == 'W') cnt_w++; 
        }
      }

      for(int x=0; x<8; x++){
        for(int y=0; y<8; y++){
          if((x+y) % 2 == 0 && temp[x][y] == 'W') cnt_b++;
          if((x+y) % 2 == 1 && temp[x][y] == 'B') cnt_b++; 
        }
      }
      
      M = min({M, cnt_w, cnt_b});
        
      

    }
  }

  cout << M << '\n';


}