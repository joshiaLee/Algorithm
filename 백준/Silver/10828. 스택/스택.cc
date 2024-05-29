#include <bits/stdc++.h>
using namespace std;

int s[10005];
int pos;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string comd;
  cin >> n;

  for(int i=0; i<n; i++){
    cin >> comd;

    if(comd == "push"){
      int a;
      cin >> a;
      s[pos++] = a;

    }

    else if(comd == "pop"){
      if(pos != 0){
        cout << s[pos-1] << '\n';
        pos--;
      }

      else{
        cout << "-1" << '\n';        
      }
    }

    else if(comd == "top"){
      if(pos != 0){
        cout << s[pos-1] << '\n';
      }

      else{
        cout << "-1" << '\n';        
      }

    }

    else if(comd == "empty"){
      if (pos){
        cout << "0" << '\n';
      }
      
      else{
        cout << "1" << '\n';
      }

    }

    else if(comd == "size"){
      cout << pos << '\n';

    }
    
  }

}