#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);


  while(true){
    string s;
    cin >> s;
    if(s=="0") break;

    int sum=0;
    for(auto a:s){
      if(a == '0') sum += 4;
      else if(a == '1') sum += 2;
      else sum += 3;
    }
    sum += s.size() - 1;
    sum += 2;

    cout << sum << '\n';
  }



  
  
}