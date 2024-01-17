#include <bits/stdc++.h>
using namespace std;

int card[105];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string s1,s2;
  cin >> s1 >> s2;
  int l = s1.size();
  int r = s2.size();
  int n, dif;

  if(s1.size() >= s2.size()){
    n = l;
    dif = l-r;
  }
  
  else{
    n = r;
    dif = r-l;
  }

  int carry=0;
  string temp = "";

  for(int i=n-1; i>=0; i--){
    int val;
    if(n == l){
      if(i-dif>=0) val = (s1[i] - '0') + (s2[i-dif] - '0') + carry;
      else val = (s1[i] - '0') + carry;
      if(val >= 10) carry = 1;
      else carry = 0;

      temp = to_string(val % 10) + temp;
    }

    else{
      if(i-dif>=0) val = (s1[i-dif] - '0') + (s2[i] - '0') + carry;
      else val = (s2[i] - '0') + carry;
      if(val >= 10) carry = 1;
      else carry = 0;
      temp = to_string(val % 10) + temp;
    }
  
  }

  if(carry) temp = "1" + temp;

  cout << temp << '\n';

}