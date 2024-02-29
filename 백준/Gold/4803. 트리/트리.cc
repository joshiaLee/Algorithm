#include <bits/stdc++.h>
using namespace std;

vector<int> adj[505];
int p[505];
int vis[505];
bool isTree;

void dfs(int cur){
    vis[cur] = 1;

    for(int nxt: adj[cur]){
        if(nxt == p[cur]) continue;
        if(vis[nxt]){
            isTree = 0;
            return;
        }
        p[nxt] = cur;
        dfs(nxt);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int t=1; ;t++)
    {
        int cnt=0;
        int n,m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for(int i=1; i<=n; i++) adj[i].clear();
        fill(vis+1, vis+n+1, 0);
        fill(p+1, p+n+1, 0);

        for(int i=0; i<m; i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=1; i<=n; i++){
            if(vis[i]) continue;
            isTree = 1;
            dfs(i);
            cnt += isTree;
        }

        if(cnt > 1) cout << "Case " << t << ": A forest of " << cnt <<" trees." << '\n';
        else if(cnt == 1) cout << "Case " << t <<": There is one tree." << '\n';
        else cout << "Case " << t << ": No trees." << '\n';

    }

}

