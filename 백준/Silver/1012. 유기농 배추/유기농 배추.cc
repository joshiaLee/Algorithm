#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[52][52];
bool vis[52][52];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(pair<int,int> coord){
  queue<pair<int,int>> Q;
  vis[coord.X][coord.Y] = 1;
  Q.push(coord);

  while(!Q.empty()){
    pair<int,int> cur = Q.front(); Q.pop();
    for(int dir=0; dir<4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(vis[nx][ny] || board[nx][ny] != 1) continue;
      vis[nx][ny] = 1;
      Q.push({nx,ny});
    }
  }
}


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t,k;

  cin >> t;

  while(t--){
    

    cin >> m >> n >> k;
    for(int i=0; i<n; i++) fill(board[i], board[i] + m, 0);
    for(int i=0; i<n; i++) fill(vis[i], vis[i] + m, 0);
    
    int x,y;
    for(int i=0; i<k; i++){
      cin >> x >> y;
      board[y][x] = 1;
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(board[i][j] && !vis[i][j]){
          bfs({i,j});
          cnt++;
        }
      }
    }
    cout << cnt << '\n';
  }
  
}
