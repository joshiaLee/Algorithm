#include <bits/stdc++.h>
using namespace std;



int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  deque<pair<int,int>> dq;

  for(int i=1; i<=n; i++){
    int mv;
    cin >> mv;
    dq.push_back({i,mv});
  }

  

  cout << dq[0].first << ' ';
  int mv = dq[0].second;
  dq.pop_front();

  while (true)
  { 
    if(dq.empty()) break;

    if(mv == 1){
      cout << dq.front().first << ' ';
      mv = dq.front().second;
      dq.pop_front();
      continue;
    }

    if(mv == -1){
      cout << dq.back().first << ' ';
      mv = dq.back().second;
      dq.pop_back();
      continue;
    }




    if(mv > 0){
      for(int i=0; i<=mv-1; i++){
        if(i == mv-1){
          cout << dq.front().first << ' ';
          mv = dq.front().second;
          dq.pop_front();
          break;
        }
        else{
          dq.push_back(dq.front());
          dq.pop_front();
        }
      }

    }

    else{
      mv = abs(mv);
      for(int i=0; i<=mv-1; i++){
        if(i == mv-1){
          cout << dq.back().first << ' ';
          mv = dq.back().second;
          dq.pop_back();
          break;
        }
        else{
          dq.push_front(dq.back());
          dq.pop_back();
        }
      }
    }

  }
  

}