#include <bits/stdc++.h>
using namespace std;



vector<tuple<int,int,int>> tuple_v;

bool cmp(tuple<int,int,int> a, tuple<int,int,int> b){
  return get<0>(a) < get<0>(b);
}


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  vector<int> v;

  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin(), v.end());

  vector<int> sum;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      tuple_v.push_back({v[i]+v[j], i, j});
      sum.push_back(v[i]+v[j]);
    }
  }

  sort(tuple_v.begin(), tuple_v.end(), cmp);
  sort(sum.begin(), sum.end());

  int cnt=0;
  for(int i=0; i<n; i++){
    auto start = lower_bound(sum.begin(), sum.end(), v[i]);
    auto end = upper_bound(sum.begin(), sum.end(), v[i]);
    int m = end - start;

    if(m > 0){
      int idx = start - sum.begin();
      for(int j=idx; j<idx+m; j++){
        if(get<1>(tuple_v[j]) != i && get<2>(tuple_v[j]) != i){
          cnt++;
          break;
        }
      }
    }
  }

  cout << cnt << '\n';





}