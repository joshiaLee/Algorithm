#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c){
    if(n==0){
        return 0;
    }

    int half = n - 1;
    int a = (1 << half);
    if(r/a == 0 && c/a == 0) return func(half,r,c);
    else if(r/a == 0 && c/a == 1) return 1*a*a + func(half,r,c-a);
    else if(r/a == 1 && c/a == 0) return 2*a*a + func(half,r-a,c);
    else if(r/a == 1 && c/a == 1) return 3*a*a + func(half,r-a,c-a);


}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,r,c;
    cin >> n >> r >> c;
    cout << func(n,r,c) << '\n';

}