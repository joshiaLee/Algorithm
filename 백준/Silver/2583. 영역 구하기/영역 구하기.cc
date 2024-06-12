#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[102][102];
int vis[102][102];
int m,n,k;
vector<int> area;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(pair<int,int> p){
    queue<pair<int,int>> Q;
    vis[p.X][p.Y] = 1;
    Q.push(p);
    int cnt=1;
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n ) continue;
            if(vis[nx][ny] || board[nx][ny] == 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
            cnt++;
        }
    }

    area.push_back(cnt);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> k;
    for(int i=0; i<k; i++){
        int x1,y1,x2,y2,tmp;
        cin >> x1 >> y1 >> x2 >> y2;
        
        tmp = x1;
        x1 = m - y1;
        y1 = tmp;

        tmp = x2;
        x2 = m - y2;
        y2 = tmp;

        for(int j=x2; j<x1; j++){
            for(int w=y1; w<y2; w++){
                board[j][w] = 1;
            }
        }

    }

    int cnt=0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!vis[i][j] && !board[i][j]){
                bfs({i,j});
                cnt++;
            }
        }
    }

    sort(area.begin(), area.end());
    cout << cnt << '\n';
    for(auto c:area) cout << c << ' ';

}