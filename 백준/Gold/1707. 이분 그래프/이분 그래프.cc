#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    while(k--){
        int n,e;
        cin >> n >> e;
        vector<int> adj[20005];
        int red_black[20005] = {0};

        while(e--){
            int u,v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int flag=1;
        fill(red_black, red_black+20005, -1);

        for(int i=1; i<=n; i++){
            if(red_black[i] != -1) continue;
            queue<int> q;
            q.push(i);
            red_black[i] = 1;

            while(!q.empty()){
                int cur = q.front();
                q.pop();

                for(int nxt: adj[cur]){
                    if(red_black[nxt] != -1){
                        if(red_black[nxt] == red_black[cur]){
                            flag = 0;
                            break;
                        }
                        else continue;
                    }
    
                    red_black[nxt] = (red_black[cur]+1) % 2;
                    q.push(nxt);

                }

                if(flag == 0) break;
            }

            if(flag == 0) break;
        }

        if(flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}

