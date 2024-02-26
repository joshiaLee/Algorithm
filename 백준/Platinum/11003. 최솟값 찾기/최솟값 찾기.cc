#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

deque<pair<int,int>> dq;
vector<int> v,d;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n,window;

  cin >> n >> window;

  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }

  for(int i=0; i<n; i++){

    while(!dq.empty() && dq.back().Y >= v[i]) dq.pop_back();
  
    dq.push_back({i, v[i]});

    if(dq.front().first <= i-window) dq.pop_front();

    d.push_back(dq.front().second);

  
  }

  for(int i=0; i<n; i++){
    cout << d[i] << ' ';
  }

  
}