#include <bits/stdc++.h>
using namespace std;

int l[100005];
int r[100005];
int p[100005];

int vis[100005];
int last;
int n;
vector<int> order;
int cnt;

void inorder(int v){
    if(l[v] != -1) inorder(l[v]);
    order.push_back(v);
    if(r[v] != -1) inorder(r[v]);
}

void psuedo_inorder(int root){
    vis[root] = 1;
    if(l[root] != -1 && !vis[l[root]]){
        psuedo_inorder(l[root]);
        cnt++;
    }
    else if(r[root] != -1 && !vis[r[root]]){
        psuedo_inorder(r[root]);
        cnt++;
    }
    
    else if(root == last) return;
    
    else if(p[root] != -1){
        psuedo_inorder(p[root]);
        cnt++;
    }

}



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        int v, a, b;
        cin >> v >> a >> b;
        l[v] = a;
        r[v] = b;

        p[a] = v;
        p[b] = v;
    }
    p[1] = -1;

    inorder(1);
    last = *order.rbegin();

    psuedo_inorder(1);
    cout << cnt << '\n';

}
