#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,a;
    vector<int> v;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for(int i=0; i<n ;i++){
        cout << v[i] << '\n';
    }

}