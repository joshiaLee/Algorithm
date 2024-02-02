#include <bits/stdc++.h>
using namespace std;

int cnt=0;
string s;

int recursion(int l, int r){
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else {
      cnt++;
      return recursion(l+1, r-1);
    }
}

int isPalindrome(){
    cnt++;
    return recursion(0, s.size()-1);
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;

  while (t--)
  {
    cin >> s;
    cnt=0;

    cout << isPalindrome() << ' ' << cnt << '\n';

  }
  
}