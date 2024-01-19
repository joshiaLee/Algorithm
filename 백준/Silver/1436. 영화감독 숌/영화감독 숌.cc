#include <bits/stdc++.h>
using namespace std;



int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  map<int,int> m;
  int cnt = 1;
  
  for(int i=1; i<=3000000; i++){
    string s = to_string(i);

    int continual = 0;
    for(int j=0; j<s.size(); j++){
      if(s[j] == '6') continual++;
      else continual = 0;
      if(continual >= 3){
        m[cnt++] = stoi(s);
        break;
      }
    }

    if(cnt > 10000) break;
  }

 cout << m[n] << '\n';




}