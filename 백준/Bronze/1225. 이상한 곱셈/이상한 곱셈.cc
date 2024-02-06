#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s1,s2;
  cin >> s1;
  if(s1=="0"){
    cout << 0 << '\n';
    return 0;
  }

  cin >> s2;

  long long sum = 0;
  for(int i=0; i<s1.size(); i++)
    for(int j=0; j<s2.size(); j++)
      sum += (s1[i]-'0') * (s2[j]-'0');

  cout << sum << '\n';
}
