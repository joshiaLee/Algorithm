#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char board[105][105];
int vis[105][105];
int keys[30];
int doors[30];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int t,h,w;



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;

  while(t--){
    cin >> h >> w;

    vector<pair<int,int>> door_cor[30];
    for(int i=0; i<h; i++) fill(board[i], board[i] + w, '0');
    for(int i=0; i<h; i++) fill(vis[i], vis[i] + w, 0);
    fill(keys, keys + 30, 0);
    fill(doors, doors+ 30, 0);

    int cnt=0;


    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        cin >> board[i][j];
        if(i==0 || i==h-1 || j==0 || j==w-1){
          if(board[i][j] - 'a' >= 0 && board[i][j] - 'a' <= 25){
            keys[board[i][j] - 'a'] = 1;
          }
          if(board[i][j] - 'A' >=0 && board[i][j] - 'A' <= 25){
            doors[board[i][j] - 'A'] = 1;
            door_cor[board[i][j] - 'A'].push_back({i,j});
          }
        }
      }
    }


    string s;
    cin >> s;

    if(s != "0") for(auto e:s) keys[e - 'a'] = 1;
    
    queue<pair<int,int>> q_entrance;
    queue<pair<int,int>> q_temp;

    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        if(i==0 || i==h-1 || j==0 || j==w-1){
          if(board[i][j] - 'a' >= 0 && board[i][j] - 'a' <= 25){
            q_entrance.push({i,j});
          }

          if(board[i][j] == '.') q_entrance.push({i,j});

          if(board[i][j] - 'A' >=0 && board[i][j] - 'A' <= 25){
            if(keys[board[i][j] - 'A']){
              q_entrance.push({i,j});
            }
          }

          if(board[i][j] == '$'){
            cnt++;
            board[i][j] = '.';
            q_entrance.push({i,j});
          }
        }
      }
    }

    q_temp = q_entrance;


    while(!q_entrance.empty()){
      auto cur = q_entrance.front(); q_entrance.pop();
      for(int dir=0; dir<4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        int l = board[nx][ny] - 'a';
        int u = board[nx][ny] - 'A';
        if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
        if(vis[nx][ny]) continue;
        if(board[nx][ny] == '*') continue;
        if(l >= 0 && l <= 25){

          if(!keys[l]){
            keys[l] = 1;
            if(doors[l]) for(auto e:door_cor[l]) q_temp.push(e);
            for(int i=0; i<h; i++) fill(vis[i], vis[i] + w, 0);
            q_entrance = q_temp;
            continue;
          }

          vis[nx][ny] = 1;
          q_entrance.push({nx,ny});
        }

        if(u >= 0 && u <= 25){
          if(!keys[u]) continue;
          vis[nx][ny] = 1;
          q_entrance.push({nx,ny});
        }

        if(board[nx][ny] == '$'){
          cnt++;
          vis[nx][ny] = 1;
          board[nx][ny] = '.';
          q_entrance.push({nx,ny});
        }

        if(board[nx][ny] == '.'){
          vis[nx][ny] = 1;
          q_entrance.push({nx,ny});
        }
      }
    }
    
    cout << cnt << '\n';
  }

}