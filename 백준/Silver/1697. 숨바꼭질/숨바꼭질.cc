#include <bits/stdc++.h>
using namespace std;

int dis[100002];

int dx[2] = {-1,1};


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a,b;
  cin >> a >> b;

  fill(dis, dis+100002, -1);

  queue<int> Q;

  dis[a] = 0;
  Q.push(a);

  while(dis[b] == -1){
    int cur = Q.front(); Q.pop();
    for(int dir=0; dir<3; dir++){
      int nx;

      if(dir == 2){
        nx = 2 * cur;
      }

      else{
        nx = cur + dx[dir];
      }

      if(nx < 0 || nx > 100000) continue;
      if(dis[nx] != -1) continue;
      dis[nx] = dis[cur] + 1;

      Q.push(nx);

    }

  }

  cout << dis[b] << '\n';

}
