#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    stack<int> s;
    s.push(0);
    vector<char> v;
    int cnt = 0;
    int flag = 0;

    for(int i=1; i<=n; i++){
        int z;
        cin >> z;

        if(s.top() < z){
            for(int j=cnt+1; j<=z; j++){
                s.push(j);
                v.push_back('+');
            }
            s.pop();
            v.push_back('-');
            cnt = z;
        }

        else if(s.top() == z){
            s.pop();
            v.push_back('-');
        }

        else{
            flag = 1;
            break;
        }
    }

    if(flag){
        cout << "NO" << '\n';
    }

    else{
        for(char c:v)
            cout << c << '\n';
    }
}