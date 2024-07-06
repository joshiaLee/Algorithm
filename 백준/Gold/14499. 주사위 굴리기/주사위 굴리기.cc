#include <bits/stdc++.h>
using namespace std;

int board[25][25];
int u,d,f,b,r,l;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m,x,y,k;
  cin >> n >> m >> x >> y >> k;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> board[i][j];
    }
  }

  
  for(int i=0; i<k; i++){
    int dir;
    cin >> dir;
    deque<int> ew = {u, r, d, l};
    deque<int> ns = {u, b, d, f};


    if(dir == 1){
      if(y+1 >= m) continue;
      ew.push_front(ew.back()); ew.pop_back();
      u = ew[0], r = ew[1], d = ew[2], l = ew[3];
      if(board[x][y+1] == 0){
        board[x][y+1] = d;
      }
      else{
        d = board[x][y+1];
        board[x][y+1] = 0;
      }

      cout << u << '\n'; 
      y++;
    }

    else if(dir == 2){
      if(y-1 < 0) continue;
      ew.push_back(ew.front()); ew.pop_front();
      u = ew[0], r = ew[1], d = ew[2], l = ew[3];
      if(board[x][y-1] == 0){
        board[x][y-1] = d;
      }
      else{
        d = board[x][y-1];
        board[x][y-1] = 0;
      }
      cout << u << '\n';
      y--;
    }

    else if(dir == 3){
      if(x-1 < 0) continue;
      ns.push_front(ns.back()); ns.pop_back();
      u = ns[0], b = ns[1], d = ns[2], f = ns[3];
      if(board[x-1][y] == 0){
        board[x-1][y] = d;
      }
      else{
        d = board[x-1][y];
        board[x-1][y] = 0;
      }
      cout << u << '\n';
      x--;
    }

    else if(dir == 4){
      if(x+1 >= n) continue;
      ns.push_back(ns.front()); ns.pop_front();
      u = ns[0], b = ns[1], d = ns[2], f = ns[3];
      if(board[x+1][y] == 0){
        board[x+1][y] = d;
      }
      else{
        d = board[x+1][y];
        board[x+1][y] = 0;
      }
      cout << u << '\n';
      x++;
    }
  }

  
}

 

