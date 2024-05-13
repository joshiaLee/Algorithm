#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char board[1002][1002];
int dis[1002][1002];
int jis[1002][1002];
int n,m;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> Q1;
    queue<pair<int,int>> Q2;
    vector<int> v;

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];

            if(board[i][j] == 'F') {
                dis[i][j] = 1;
                Q1.push({i,j});
            }
            else if(board[i][j] == 'J') {
                jis[i][j] = 1;
                Q2.push({i,j});
            }

        }
    }
    
    if(n==1 && m==1){
        cout << '1' << '\n';
        return 0;
    }    

    while(!Q1.empty()){

        pair<int,int> cur = Q1.front(); Q1.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dis[nx][ny] > 0) continue;
            if(board[nx][ny] == '#') continue;
            dis[nx][ny] = dis[cur.X][cur.Y] + 1;
            Q1.push({nx,ny});
        }
    }

    while(!Q2.empty()){

        pair<int,int> cur = Q2.front(); Q2.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                cout << jis[cur.X][cur.Y];
                return 0;
            }
            if(jis[nx][ny] > 0) continue;
            if(board[nx][ny] == '#') continue;
            if(dis[nx][ny] != 0 && jis[cur.X][cur.Y] + 1 >= dis[nx][ny]) continue;
            jis[nx][ny] = jis[cur.X][cur.Y] + 1;
            Q2.push({nx,ny});
            
        }
    }

    cout << "IMPOSSIBLE" << '\n';
}