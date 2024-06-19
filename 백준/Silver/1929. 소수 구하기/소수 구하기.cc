#include <bits/stdc++.h>
using namespace std;

vector<int> eratost(int n){
    vector<int> primes;
    vector<bool> states(n+1,true);
    states[1] = false;
    for(int i=2; i*i<=n; i++){
        if(!states[i]) continue;
        for(int j=i*i; j<=n; j += i){
            states[j] = false;
        }
    }

    for(int i=1; i<=n; i++){
       if(states[i]) primes.push_back(i);
    }
    
    return primes;
}



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,n;
    cin >> m >> n;

    vector<int> p = eratost(n);
    for(int i=0; i<p.size(); i++){
        if(p[i] >= m) cout << p[i] << '\n';
    }
    
}