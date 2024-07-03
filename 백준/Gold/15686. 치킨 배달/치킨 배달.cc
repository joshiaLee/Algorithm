#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[55][55];

vector<pair<int,int>> ch;
vector<pair<int,int>> home;
vector<bool> on_off;
vector<int> dist;
int dis=0;

int cal_dis(pair<int,int> cur){
    vector<int> v;
    int idx=0;
    for(auto a:ch){
        int dis=0;
        if(!on_off[idx]){
            idx++;
            continue;
        }
        if(cur.X > a.X) dis += cur.X - a.X;
        else dis += a.X - cur.X;
        if(cur.Y > a.Y) dis += cur.Y - a.Y;
        else dis += a.Y - cur.Y;
        v.push_back(dis);
        idx++;
    }
    return *min_element(v.begin(), v.end());
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) home.push_back({i,j});
            if(board[i][j] == 2) ch.push_back({i,j});
        }
    }
    // ch.size() < m 일때 고려해야함

    int on = m;
    int off = ch.size() - m;

    for(int i=0; i<off; i++){
        on_off.push_back(0);
    }

    for(int i=0; i<on; i++){
        on_off.push_back(1);
    }
   
    int sum=0;
    do{ 
        sum = 0;
        for(auto h:home){
            sum += cal_dis(h);
        }
        dist.push_back(sum);
    } while (next_permutation(on_off.begin(), on_off.end()));
    
    cout << *min_element(dist.begin(), dist.end());
    
}