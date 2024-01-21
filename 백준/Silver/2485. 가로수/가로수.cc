#include <bits/stdc++.h>
using namespace std;

int n;
map<int, bool> tree;
int lo[100005];

int gcd(int a, int b){
  if(b == 0) return a;
  return gcd(b, a % b);
}


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;

  cin >> lo[0];
  tree[lo[0]] = 1;

  vector<int> distance;

  for(int i=1; i<n; i++){
    cin >> lo[i];
    tree[lo[i]] = 1;
    distance.push_back(lo[i] - lo[i-1]);
  }

  sort(distance.begin(), distance.end());

  int g = gcd(distance[1], distance[0]);

  for(int i=2; i<distance.size(); i++)
    g = gcd(max(g, distance[i]), min(g, distance[i]));

  int cnt=0;

  for(int i=0; i < distance.size(); i++){
    cnt += distance[i] / g - 1;
  }
  
  cout << cnt << '\n';
}