#include <bits/stdc++.h>
using namespace std;

class cmp{
    public:
        bool operator () (int a, int b){
            if (abs(a) != abs(b)) return abs(a) > abs(b);
            return a > 0 && b < 0;
        }
};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    priority_queue<int,vector<int>,cmp> pq;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        if(a != 0) pq.push(a);
        else{
            if(pq.empty()) cout << '0' << '\n';
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}