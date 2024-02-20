#include <bits/stdc++.h>
using namespace std;

vector<int> adj[20005];
int dis[20005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(dis, dis+20005, -1);

    queue<int> q;
    q.push(1);
    dis[1] = 0;

    int max_val = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt: adj[cur]){
            if(dis[nxt] != -1) continue;
            dis[nxt] = dis[cur] + 1;
            max_val = max(max_val, dis[nxt]);
            q.push(nxt);
        }
    }
    int position = 1;
    int cnt = 0;
    
    for(int i=1; i<=n; i++){
        if(dis[i] == max_val){
            if(cnt == 0) position = i; 
            cnt++;
        }
    }

    cout << position << ' ' << max_val << ' ' << cnt << '\n';
}

