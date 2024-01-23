#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> v;
  vector<int> l;
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    v.push_back(a);
    if(l.empty()) l.push_back(a);
    else{
      if(lower_bound(l.begin(), l.end(), a) != l.end()){
        int idx = lower_bound(l.begin(), l.end(), a)- l.begin();
        l[idx] = a;
      }

      else l.push_back(a);
    }
  }

  cout << l.size() << '\n';

  
  
}