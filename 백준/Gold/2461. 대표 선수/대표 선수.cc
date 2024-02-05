#include <bits/stdc++.h>
using namespace std;

int pointer[1005];
set<int> s;
vector<int> students[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int z;
      cin >> z;
      students[i].push_back(z);
    }
  }

  for(int i=0; i<n; i++)
    sort(students[i].begin(), students[i].end());

  for(int i=0; i<n; i++){
    s.insert(students[i][0]);
    if(m != 1) pq.push({students[i][1], i});
    pointer[i] = 1;
  }

  int M = *s.rbegin() - *s.begin();

  while (true){
    if(pq.empty()) break;

    auto p = pq.top(); pq.pop();
    s.insert(p.first);

    int cla = p.second; 
    int idx = pointer[cla];
    s.erase(s.find(students[cla][idx-1])); 

    if(idx != m-1){
      pointer[cla]++;
      idx = pointer[cla];
      pq.push({students[cla][idx], cla}); 
    }

    M = min(M, *s.rbegin() - *s.begin());
  }

  cout << M << '\n';
}
