#include <bits/stdc++.h>
using namespace std;

int board[8][8];
char board_f[8][8];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  for(int i=0; i<8; i++)
    for(int j=0; j<8; j++)
      board[i][j] = ((i+j) % 2 == 0)? 0 : 1;

  int cnt=0;
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      cin >> board_f[i][j];
      if(board[i][j] == 0 && board_f[i][j] == 'F') cnt++;
    }
  }  
  
  cout << cnt << '\n';
}