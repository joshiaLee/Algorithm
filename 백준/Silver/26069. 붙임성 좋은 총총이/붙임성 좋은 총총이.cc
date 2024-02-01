#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  set<string> dancing;

  while (n--)
  {
    string s1, s2;
    cin >> s1 >> s2;
    
    if(s1 == "ChongChong"){
      dancing.insert(s1);
      dancing.insert(s2);
    }

    else if(s2 == "ChongChong"){
      dancing.insert(s2);
      dancing.insert(s1);
    }

    else if(dancing.find(s1) != dancing.end()) dancing.insert(s2);
    
    else if(dancing.find(s2) != dancing.end()) dancing.insert(s1);
    
  }
  
    cout << dancing.size() << '\n';
  
}