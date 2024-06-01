#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int n,m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int my_bfs(int a, int b){
    queue<pair<int,int>> Q;
    vis[a][b] = 1;
    Q.push({a,b});
    int cnt = 1;

    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
            cnt++; 
        }
    }

    return cnt;
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
    int a=0, cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] && !vis[i][j]){
                a = max(a, my_bfs(i,j));
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
    cout << a << '\n';    
}