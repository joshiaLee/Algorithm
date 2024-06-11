#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
// 1 Red 2 Green 3 Blue

int board[102][102];
bool vis[102][102];
int n;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(pair<int,int> p, int v=1){
    int color = board[p.X][p.Y];
    queue<pair<int,int>> Q;
    vis[p.X][p.Y] = 1;
    Q.push(p);
    while(!Q.empty()){
      pair<int,int> cur = Q.front(); Q.pop();
      for(int dir=0; dir<4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(v == 1 || color == 3){
          if(vis[nx][ny] || board[nx][ny] != color) continue;
        }
        else{
          if(vis[nx][ny] || (board[nx][ny] != 1 && board[nx][ny] != 2)) continue;
        }
        vis[nx][ny] = 1;
        Q.push({nx,ny});
      }
    }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  char c;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> c;
      if(c == 'R') board[i][j] = 1;
      else if(c == 'G') board[i][j] = 2;
      else board[i][j] = 3;
    }
  }
  int cnt=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(vis[i][j] == 0){
        bfs({i,j});
        cnt++;
      }
    }
  }

  cout << cnt << ' ';
  
  for(int i=0; i<n; i++) fill(vis[i], vis[i] + n, 0);
  cnt=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(vis[i][j] == 0){
        bfs({i,j},2);
        cnt++;
      }
    }
  }

  cout << cnt << '\n';
  

}