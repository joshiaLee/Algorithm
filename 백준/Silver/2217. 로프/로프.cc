#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v1,v2;
    int a,n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a;
        v1.push_back(a);
    }

    sort(v1.begin(), v1.end(), greater<>());
    
    int cnt=1;
    for(int i=0; i<n; i++){
        v2.push_back(v1[i] * cnt);
        cnt++;
    }

    cout << *max_element(v2.begin(), v2.end()) << '\n';
}