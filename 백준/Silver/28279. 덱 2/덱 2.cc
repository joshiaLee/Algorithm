#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  deque<int> dq;

  int n;
  cin >> n;

  while(n--){
    int a;
    cin >> a;

    if(a == 1){
      int b;
      cin >> b;
      dq.push_front(b);
    }

    else if(a == 2){
      int b;
      cin >> b;
      dq.push_back(b);
    }

    else if(a == 3){
      if(dq.empty()) cout << "-1" << '\n';
      else{
        cout << dq.front() << '\n';
        dq.pop_front();
      }
    }

    else if(a == 4){
      if(dq.empty()) cout << "-1" << '\n';
      else{
        cout << dq.back() << '\n';
        dq.pop_back();
      }
    }

    else if(a == 5) cout << dq.size() << '\n';

    else if (a == 6) cout << dq.empty() << '\n';

    else if(a == 7){
      if(dq.empty()) cout << "-1" << '\n';
      else cout << dq.front() << '\n';
    }    

    else if(a == 8){
      if(dq.empty()) cout << "-1" << '\n';
      else cout << dq.back() << '\n';
    }    
  }
}