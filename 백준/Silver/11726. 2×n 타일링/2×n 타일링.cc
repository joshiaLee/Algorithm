#include <bits/stdc++.h>
using namespace std;

int D[1005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    D[1] = 1;
    D[2] = 2;

    if(n==1 || n == 2){
        cout << D[n];
        return 0;
    }

    for(int i=3; i<=n; i++){
        D[i] = (D[i-1] + D[i-2]) % 10007;
    }
    cout << D[n];


}