#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> v;
  vector<int> l;
  vector<int> order;

  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    v.push_back(a);

    if(l.empty()){
      l.push_back(a);
      order.push_back(0);
    }
    else{
      if(lower_bound(l.begin(), l.end(), a) != l.end()){
        int idx = lower_bound(l.begin(), l.end(), a)- l.begin();
        l[idx] = a;
        order.push_back(idx);
      }

      else{
        order.push_back(l.size());
        l.push_back(a);
      }
    }
  }
  int m = *max_element(order.begin(), order.end());

  vector<int> ans;

  for(int i=n-1; i>=0; i--){
    if(m < 0) break;

    if(order[i] == m){
      ans.push_back(v[i]);
      m--;
    }
  }
  
  cout << ans.size() << '\n';
  
  for(int i=ans.size()-1; i>=0; i--){
    cout << ans[i] << ' ';
  }



  
  
}