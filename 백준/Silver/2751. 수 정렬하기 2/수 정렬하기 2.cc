#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a;
    vector<int> v;

    

    while(n--){
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for(auto c:v){
        cout << c << '\n';
    }    

}
