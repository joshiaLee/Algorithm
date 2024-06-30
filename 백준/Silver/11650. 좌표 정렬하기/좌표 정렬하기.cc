#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    
    pair<int,int> p[n];

    for(int i=0; i<n; i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p,p+n);

    for(int i=0; i<n; i++){
        cout << p[i].first << ' ' << p[i].second << '\n';
    }
}