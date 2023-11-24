#include <bits/stdc++.h>
using namespace std;

int board[1005][1005];
int dis[1005][1005][12][2];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n,m,k;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;

  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    for(int j=0; j<m; j++){
      board[i][j] = s[j] - '0';
    }
  }

  queue<tuple<int,int,int,int>> q;
  q.push({0,0,0,0});
  dis[0][0][0][0] = 1;

  while (!q.empty())
  {
    int x,y,broken,don;
    tie(x,y,broken,don) = q.front(); q.pop();

    // BFS의 특성상 거리순으로 쌓이게 되고 가장 거리가 짧은것이 큐에서 먼저 나온다.
    if(x == n-1 && y == m-1){
      cout << dis[x][y][broken][don] << '\n';
      return 0;
    }

    for(int dir=0; dir<4; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      // 0이면 그냥 움직여도됨
      if(board[nx][ny] == 0){
        // 먼저 온적이 있으면 이미 큐에 들어갔기 때문에 넘어감
        if(dis[nx][ny][broken][1-don]) continue;
        dis[nx][ny][broken][1-don] = dis[x][y][broken][don] + 1;
        q.push({nx,ny,broken,1-don});
      }

      // 1이면 부순횟수와 낮과 밤을 따져야함
      else{
        
        // 부순 횟수 따짐
        if(broken+1 > k) continue;

        // 낮이면 부숴도 됨
        if(don == 0){

          // 먼저 온적이 있으면 넘어감
          if(dis[nx][ny][broken+1][1-don]) continue;
          dis[nx][ny][broken+1][1-don] = dis[x][y][broken][don] + 1;
          q.push({nx,ny,broken+1,1-don});

        }

        // 밤이면 낮이 올때까지 기다려야함
        else{

          // 먼저 온적이 있으면 넘어감
          if(dis[x][y][broken][1-don]) continue;
          dis[x][y][broken][1-don] = dis[x][y][broken][don] + 1;
          q.push({x,y,broken,1-don});

        }
      }
    }   

  }
  

  cout << "-1" << '\n';


}