#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int p[100005];
int compliment[100005];

void dfs(int cur){
    if(cur != 1)
        compliment[cur] += compliment[p[cur]];

    for(int nxt: adj[cur]){
        if(nxt == p[cur]) continue;
        dfs(nxt);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        int boss;
        cin >> boss;
        if(boss == -1) continue;

        adj[i].push_back(boss);
        adj[boss].push_back(i);
        
        p[i] = boss;
    }

    for(int i=0; i<m; i++){
        int employee, com;
        cin >> employee >> com;
        compliment[employee] += com;
    }

    dfs(1);

    for(int i=1; i<=n; i++)
        cout << compliment[i] << ' ';
    cout << '\n';

}
