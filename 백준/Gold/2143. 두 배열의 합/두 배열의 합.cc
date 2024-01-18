#include <bits/stdc++.h>
using namespace std;

int a[1005];
int b[1005];

int s1[1005];
int s2[1005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  int n,m;
  cin >> t;
  cin >> n;
  int sum=0;
  for(int i=1; i<=n; i++){
    cin >> a[i];
    sum += a[i];
    s1[i] = sum;
  }
  cin >> m;
  sum = 0;
  for(int i=1; i<=m; i++){
    cin >> b[i];
    sum += b[i];
    s2[i] = sum; 
  }

  vector<int> part_a;
  vector<int> part_b;


  for(int i=1; i<=n; i++){
    for(int j=i; j<=n; j++){
      part_a.push_back(s1[j] - s1[i-1]);
    }
  }

  for(int i=1; i<=m; i++){
    for(int j=i; j<=m; j++){
      part_b.push_back(s2[j] - s2[i-1]);
    }
  }
  
  sort(part_a.begin(), part_a.end());

  long long cnt=0;
  for(int i=0; i<part_b.size(); i++) cnt += upper_bound(part_a.begin(), part_a.end(), t - part_b[i]) - lower_bound(part_a.begin(), part_a.end(), t - part_b[i]);
  
  cout << cnt << '\n';



}