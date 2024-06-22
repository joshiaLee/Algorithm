#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k,a;
    int cnt = 0;
    vector<int> v;

    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> a;
        v.push_back(a);
    }

    for(int i=n-1; i>=0; i--){
        if(k / v[i]){
            cnt += k / v[i];
            k = k - (k / v[i]) * v[i];
        }
        else continue;
    }

    cout << cnt << '\n';
    

}
