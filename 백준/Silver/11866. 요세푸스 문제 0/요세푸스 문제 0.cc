#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> v;

  int n,k;
  cin >> n >> k;

  for(int i=1; i<=n; i++) v.push_back(i);

  vector<int> ans;
  int idx=0;
  int cnt=1;
  while(true){
    if(ans.size() == n) break;

    if(idx == v.size()) idx = 0;
    if(v[idx] == 0){
      idx++;
      continue;
    }

    if(cnt == k){
      ans.push_back(v[idx]);
      v[idx]=0;
      cnt=0;
    }

    idx++;
    cnt++;

  }

  if(n==1){
    cout << "<1>" << '\n';
    return 0;
  }

  for(int i=0; i<n; i++){
    if(i==0) cout << "<" << ans[i] <<", "; 
    else if(i==n-1) cout << ans[i] << ">";
    else cout << ans[i] << ", ";
    
  }
}