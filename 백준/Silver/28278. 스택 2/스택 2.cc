#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<int> st;

  int n;
  cin >> n;

  while(n--){
    int m;
    cin >> m;

    if(m == 1){
      int a;
      cin >> a;
      st.push(a);
    }

    else if(m == 2){
      if(!st.empty()){
        cout << st.top() << '\n';
        st.pop();
      }
      else cout << -1 << '\n';
    }

    else if(m == 3) cout << st.size() << '\n';

    else if(m == 4){
      if(st.empty()) cout << 1 << '\n';
      else cout << 0 << '\n';
    }

    else{
      if(!st.empty()) cout << st.top() << '\n';
      else cout << -1 << '\n';
    }

  }




  
  
}