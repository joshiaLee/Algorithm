#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  set<string> set_name;
  int greeting = 0;

  while (n--)
  {
    string s;
    cin >> s;
    
    if(s == "ENTER") set_name.clear();
    else{
      if(set_name.find(s) == set_name.end()){
        greeting++;
        set_name.insert(s);
      }
    }
    
  }
  
  cout << greeting << '\n';
    
  
}