#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
vector<string> child[1005];
vector<string> name;
unordered_map<string, int> mapping_name;
unordered_map<int, string> mapping_idx;

int deg[1005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin >> n;

  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    name.push_back(s);
  }

  sort(name.begin(), name.end());
  
  for(int i=0; i<n; i++){
    mapping_name[name[i]] = i+1;
    mapping_idx[i+1] = name[i];
  }

  cin >> m;

  for(int i=0; i<m; i++){
    string des, ance;
    cin >> des >> ance;
    adj[mapping_name[ance]].push_back(mapping_name[des]);
    deg[mapping_name[des]]++;
  }

  queue<int> q;
  vector<string> root;

  for(int i=1; i<=n; i++){
    if(deg[i] == 0){
      root.push_back(mapping_idx[i]);
      q.push(i);
    } 
  }

  sort(root.begin(), root.end());
  cout << root.size() << '\n';

  for(string s:root)
    cout << s << ' ';
  cout << '\n';

  while (!q.empty())
  {
    int cur = q.front(); q.pop();
    for(int nxt: adj[cur]){
      deg[nxt]--;
      if(deg[nxt] == 0){
        child[cur].push_back(mapping_idx[nxt]);
        q.push(nxt);
      }
    }
    sort(child[cur].begin(), child[cur].end());
  }

  for(int i=1; i<=n; i++){
    cout << mapping_idx[i] << ' ';
    cout << child[i].size() << ' ';
    for(string ch: child[i])
      cout << ch << ' ';
    cout << '\n'; 
  }

}
