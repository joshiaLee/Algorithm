#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101005];
int dis[101005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k,m;
    cin >> n >> k >> m;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=k; j++){
            int nxt;
            cin >> nxt;

            adj[n+i].push_back(nxt);
            adj[nxt].push_back(n+i);
        }
    }

    fill(dis, dis+101005, -1);

    queue<int> q;
    q.push(1);
    dis[1] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int nxt: adj[cur]){
            if(dis[nxt] != -1) continue;
            dis[nxt] = dis[cur] + 1;
            q.push(nxt);
        }
    }

    if(dis[n] == -1) cout << dis[n] << '\n';
    else cout << dis[n] / 2 + 1 << '\n';
}
