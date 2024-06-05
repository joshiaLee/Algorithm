#include <bits/stdc++.h>
using namespace std;

int d[1205];
vector<pair<int,int>> com; // 얻는 사람수, 비용

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int val,n;
  cin >> val >> n;

  for(int i=1; i<=n; i++){
    int people, p;
    cin >> p >> people;
    com.push_back({people,p});
  }

  sort(com.begin(), com.end());

  fill(d, d+1205, 10000000);
  d[0] = 0;

  for(int i=0; i<com.size(); i++){
    for(int j=1; j<=val+105; j++){
      if(j - com[i].first >= 0) d[j] = min(d[j], d[j-com[i].first] + com[i].second);
    }
  }

  cout << *min_element(d+val, d+val+105) << '\n';

}



