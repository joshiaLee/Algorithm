#include <bits/stdc++.h>
using namespace std;

int card[105];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n,m;
  vector<int> mask;
  cin >> n >> m;

  for(int i=0; i<n; i++){
    cin >> card[i];
  }

  for(int i=0; i<n; i++) mask.push_back((i<3)? 0:1);

  int ans=0;
  do
  {
    int sum=0;
    for(int i=0; i<n; i++) if(mask[i] == 0) sum += card[i];
    if(sum <= m) ans = max(ans, sum);
    if(ans == m) break;
  } while (next_permutation(mask.begin(), mask.end()));
   
  cout << ans << '\n';

}