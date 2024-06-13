#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[105][105];
int v[105][105];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> bridge;
int n;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> board[i][j];
    }
  }
  int cnt=0;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(board[i][j] && v[i][j] == 0){
        cnt++;
        board[i][j] = cnt;

        queue<pair<int,int>> q;
        q.push({i,j});
        v[i][j] = 1;
        while (!q.empty())
        {
          auto cur = q.front(); q.pop();
          for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(board[nx][ny] == 0) continue;
            if(v[nx][ny]) continue;

            v[nx][ny] = 1;
            board[nx][ny] = cnt;
            q.push({nx,ny});

          }
        }
        
      }
    }
  }
  



  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(board[i][j]){
        for(int z=0; z<n; z++) fill(v[z], v[z] + n, 0);

        int island = board[i][j];

        queue<tuple<int,int,int>> q;
        q.push({i,j,0});
        v[i][j] = 1;
        
        while(!q.empty()){
          int x,y,d;
          tie(x,y,d) = q.front(); q.pop();
          if(board[x][y] != 0 && board[x][y] != island){
            bridge.push_back(d-1);
            break;
          }

          for(int dir=0; dir<4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nd;
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(board[nx][ny] == island) continue;
            if(v[nx][ny]) continue;

            v[nx][ny] = 1;
            nd = d + 1;
            q.push({nx,ny,nd});


            
            
          }
        }
      }
    }
  }

  cout << *min_element(bridge.begin(), bridge.end()) << '\n';


}