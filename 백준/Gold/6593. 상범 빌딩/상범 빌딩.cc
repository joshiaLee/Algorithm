#include <bits/stdc++.h>
using namespace std;

char board[32][32][32];
int dis[32][32][32];
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,-1,1};

int L,R,C;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        queue<tuple<int,int,int>> q;
        tuple<int,int,int> ending;
        cin >> L >> R >> C;
        if(L == 0) break;

        for(int i=0; i<L; i++){
            for(int j=0; j<R; j++) fill(dis[i][j], dis[i][j]+C, -1);
        }

        for(int i=0; i<L; i++){
            for(int j=0; j<R; j++){
                for(int k=0; k<C; k++){
                    cin >> board[i][j][k];
                    if(board[i][j][k] == 'S'){
                        q.push({i,j,k});
                        dis[i][j][k] = 0;
                    }
                    else if(board[i][j][k] == 'E') {
                        ending = make_tuple(i,j,k);
                    }
                }
            }
        }
        int flag=1;
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            int z,x,y,a,b,c;
            tie(z,x,y) = cur;
            tie(a,b,c) = ending;
            if(z == a && x == b && y == c){
                cout << "Escaped in " << dis[z][x][y] << " minute(s).\n";
                flag=0;
                break;
            }
            for(int dir=0; dir<6; dir++){
                int nz = z + dz[dir];
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if(board[nz][nx][ny] == '#') continue;
                if(dis[nz][nx][ny] != -1) continue;
                dis[nz][nx][ny] = dis[z][x][y] + 1;
                q.push({nz,nx,ny});
            }
        }
        if(flag) cout << "Trapped!\n";
    }
    
}


