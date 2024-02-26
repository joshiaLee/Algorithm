#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int vertexs[100005];
int p[100005];

int dfs(int cur){
    vertexs[cur] += 1;

    for(int nxt: adj[cur]){
        if(nxt == p[cur]) continue;
        p[nxt] = cur;
        vertexs[cur] += dfs(nxt);
    }

    return vertexs[cur];
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, root, q;
    cin >> n >> root >> q;

    for(int i=0; i<n-1; i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(root);

    while (q--)
    {
        int sub;
        cin >> sub;
        cout << vertexs[sub] << '\n';
    }
    

}
