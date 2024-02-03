#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  m["black"]=0;
  m["brown"]=1;
  m["red"]=2;
  m["orange"]=3;
  m["yellow"]=4;
  m["green"]=5;
  m["blue"]=6;
  m["violet"]=7;
  m["grey"]=8;
  m["white"]=9;
  
  string s1,s2,s3;
  cin >> s1 >> s2 >> s3;

  long long ans = m[s1] * 10 + m[s2];
  long long mul = 1;
  for(int i=0; i<m[s3]; i++)
    mul *= 10;

  cout << ans * mul << '\n'; 
  

  
}