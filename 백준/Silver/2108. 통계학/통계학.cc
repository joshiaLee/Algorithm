#include <bits/stdc++.h>
using namespace std;

int num[8005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int sum = 0;
  vector<int> v;
  int m = 4005;
  int M = -4005;

  for(int i=0; i<n; i++)
  {
    int z;
    cin >> z;
    sum += z;
    
    v.push_back(z);
    
    num[z+4000]++;
    
    m = min(m,z);
    
    M = max(M,z);
  
  }

  int even = (sum >= 0) ? floor(((double) sum / (double) n) + 0.5) : floor(((double) (-1) * sum / (double) n) + 0.5);
  even = (sum >= 0) ? even : even * (-1);

  sort(v.begin(), v.end());
  int max_f = *max_element(num, num + 8001);

  vector<int> ans;
  for(int i=0; i<=8000; i++)
    if(num[i] == max_f) ans.push_back(i);
  
  sort(ans.begin(), ans.end());
  int max_val = (ans.size() >= 2)? ans[1] : ans[0]; 
  
  cout << even << '\n';
  cout << v[n/2] << '\n';
  cout << max_val - 4000 << '\n';
  cout << M - m << '\n';


}