#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<pair<int,int>> p;
  for(int i=0; i<n; i++){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    p.push_back({a*100 + b, c*100 + d});
  }

  sort(p.begin(), p.end());

  int end = 301;
  int cnt = 0;
  int max_end = 301;
  
  for(int i=0; i<n; i++){
    if(p[i].first <= end && p[i].second > max_end){
      max_end = p[i].second;
      if(max_end > 1130){
        cnt++;
        cout << cnt << '\n';
        return 0;
      }
      continue;
    }

    if(p[i].first > end){
      end = max_end;
      cnt++;

      if(p[i].first > end){
        cout << 0 << '\n';
        return 0;
      }

      i--;
    }

  }
  
  cout << 0 << '\n';
}