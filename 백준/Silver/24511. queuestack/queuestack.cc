#include <bits/stdc++.h>
using namespace std;

int queuestack[100005];
deque<int> dq;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin >> n;

  for(int i=0; i<n; i++) 
    cin >> queuestack[i];
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    if(queuestack[i] == 0)
      dq.push_back(a);
  }

  cin >> m;
  for(int i=0; i<m; i++){
    int a;
    cin >> a;
    dq.push_front(a);
  }

  while (m--){
    cout << dq.back() << ' ';
    dq.pop_back();
  }  

}