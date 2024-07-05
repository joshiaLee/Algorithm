#include <bits/stdc++.h>
using namespace std;
int a[100005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,s;
    cin >> n >> s;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int st=0,en=0,len=0;
    int ans=100005;
    int sum=a[0];
    while(true){
        if(en == n) break;

        if(en < n && sum < s){
            en++;
            sum += a[en];
            continue;
        }

        len = en -st +1;
        ans = min(ans, len);        
        sum -= a[st];
        st++;
    }
    
    if(ans != 100005) cout << ans;
    else cout << '0';
}

   