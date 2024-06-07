#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1002][1002];
int dis[1002][1002];
int n,m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void my_bfs(vector<pair<int,int>> w){
    queue<pair<int,int>> Q;
    for(auto c:w){
        Q.push(c);
    }
    
    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dis[nx][ny] >= 1 || board[nx][ny] != 0) continue;
            dis[nx][ny] = dis[cur.X][cur.Y] + 1;
            Q.push({nx,ny}); 
        }
       
    }
    int r=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if( dis[i][j] == 0 && board[i][j] != 1 && board[i][j] != -1) {
                cout << "-1" << '\n';
                return;
            }

            else {
                r = max(r, dis[i][j]);
                
            }
        }
    }
    
    cout << r << '\n';
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> m >> n;
    vector<pair<int,int>> v;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) v.push_back({i,j});
        }
    }

    my_bfs(v);

}