#include <bits/stdc++.h>
using namespace std;
queue<tuple<int,int,int>> q;

char board[1005][1005];
int dis[1005][1005][2];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;

int bfs(){
    while(!q.empty()){
        int x,y,crush;
        tie(x,y,crush) = q.front(); q.pop();

        if(x == n-1 && y == m-1) return dis[x][y][crush];
        for(int dir=0; dir<4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dis[nx][ny][crush] != -1) continue;
            if(board[nx][ny] == '1'){
                if(crush == 1) continue;
                else{
                    dis[nx][ny][1] = dis[x][y][0] + 1;
                    q.push({nx,ny,1});
                    continue;
                }
            }
            dis[nx][ny][crush] = dis[x][y][crush] + 1;
            q.push({nx,ny,crush});
        }
    }
    return 0;    
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<2; k++){
                dis[i][j][k] = -1;
            }
        }
    } 
    
    q.push({0,0,0});
    dis[0][0][0]= 1; dis[0][0][1] = 1;
    int a;
    a = bfs();
    if(a) cout << a << '\n';
    else cout << "-1" << '\n';
}
